
namespace mjson{
	luabridge::LuaRef parseInternal( nlohmann::json j ){
		switch (j.type()) {
		    case nlohmann::json::value_t::null:
		        return luabridge::LuaRef(luaInit::luaState, nullptr);
		        
		    case nlohmann::json::value_t::boolean:
		        return luabridge::LuaRef(luaInit::luaState, j.get<bool>());
		        
		    case nlohmann::json::value_t::number_integer:
		        return luabridge::LuaRef(luaInit::luaState, j.get<int64_t>());
		        
		    case nlohmann::json::value_t::number_unsigned:
		        return luabridge::LuaRef(luaInit::luaState, j.get<uint64_t>());
		        
		    case nlohmann::json::value_t::number_float:
		        return luabridge::LuaRef(luaInit::luaState, j.get<double>());
		        
		    case nlohmann::json::value_t::string:
		        return luabridge::LuaRef(luaInit::luaState, j.get<std::string>());
		        
		    case nlohmann::json::value_t::array: {
		        luabridge::LuaRef array = luabridge::newTable(luaInit::luaState);
		        for (size_t i = 0; i < j.size(); ++i) {
		            array[i + 1] = mjson::parseInternal(j[i]); // Lua arrays are 1-based
		        }
		        return array;
		    }
		        
		    case nlohmann::json::value_t::object: {
		        luabridge::LuaRef table = luabridge::newTable(luaInit::luaState);
		        for (auto& el : j.items()) {
		            table[el.key()] = mjson::parseInternal(el.value());
		        }
		        return table;
		    }
		        
		    default:
		        return luabridge::LuaRef(luaInit::luaState, nullptr);
		}
	}

	luabridge::LuaRef parse( std::string A ){
		auto data = nlohmann::json::parse(A);
		return mjson::parseInternal( data );
	}


	std::string luaTypeToString(int type) {
	    switch (type) {
	        case LUA_TNIL: return "nil";
	        case LUA_TBOOLEAN: return "boolean";
	        case LUA_TLIGHTUSERDATA: return "light userdata";
	        case LUA_TNUMBER: return "number";
	        case LUA_TSTRING: return "string";
	        case LUA_TTABLE: return "table";
	        case LUA_TFUNCTION: return "function";
	        case LUA_TUSERDATA: return "userdata";
	        case LUA_TTHREAD: return "thread";
	        default: return "unknown type";
	    }
	}

	// Main conversion function
	std::string tableToJson(const luabridge::LuaRef& table) {
		std::string temp = "";

	    for (luabridge::Iterator iterator (table); !iterator.isNil (); ++iterator)
	    {
            auto next = iterator;
            ++next;

	    	auto value = iterator.value();
	    	std::string valueSTR = value.tostring();
	    	if( value.isTable() )
	    		valueSTR = mjson::tableToJson( value );

	    	if( value.isString() )
	    		valueSTR = "\"" + m_str::replaceSubStr(valueSTR,"\"","\\\"") + "\"";

	        temp += "\"" + iterator.key().tostring() + "\": " + valueSTR;
	    	if( !next.isNil() )
	    		temp += ",";
	    }
	    return "{"+temp+"}";
	}


	std::string luaTableToJson( const luabridge::LuaRef& table ) {
	    return mjson::tableToJson( table );
	}
}