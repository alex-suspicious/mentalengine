namespace luaClasses{
	std::unordered_map<std::string, luabridge::LuaRef> allHooks;
	//std::vector<lua_State*> threadStates;

	class FlexibleClass
	{
	public:
		std::unordered_map<std::string, luabridge::LuaRef> properties;
		std::map<std::string, std::vector<std::string>> hooks;
		std::string name;
		luabridge::LuaRef localRef = luabridge::LuaRef( luaInit::luaState );
		int id;
		bool removing = false;

		FlexibleClass(){
			luaInit::luaFlexibleObjects.push_back(this);
			this->id = rand() % 99999999999;
		}

		void clear(){
//			this->properties.clear();
			//for(std::unordered_map<std::string, luabridge::LuaRef>::const_iterator iter = this->properties.begin(); iter != this->properties.end(); ++iter)
			//{
			    //this->properties.at(iter->first) = luabridge::LuaNil();

				//if( iter->second.isInstance<FlexibleClass>() )
			    //	iter->second["remove"]();
			    
			//    iter->second = (luabridge::LuaRef)luabridge::LuaNil();
			    //this->properties.erase( iter->first );
			//}
		    for (auto &prop : this->properties) {
		        //prop.second = luabridge::LuaNil();
		        //this->properties.at(prop.first).pop();
		        //if( this->properties.at(prop.first).isInstance<FlexibleClass>() ){
		        	//auto result = this->properties.at(prop.first).cast<FlexibleClass*>().value();
		        	//prop.second["remove"]( prop.second );
			        //if (result) {
			        //    FlexibleClass* obj = result.value();
			            //obj->remove();

						//obj->localRef = luabridge::LuaNil();
						//this->clear();
						//this->~FlexibleClass();
						//delete( this );
						//obj->removing = true;
			        //} else {
			        //    std::cout << "Failed to cast LuaRef to FlexibleClass*" << std::endl;
			        //}
		        //}
			    
			    this->properties.at(prop.first) = luabridge::LuaNil();
		    }
		    this->properties.clear();
			//for (auto prop : this->properties) {
			    //luabridge::LuaRef j1 = prop.first;
			    //luabridge::LuaRef j2 = prop.second;
			    //prop.second = luabridge::LuaNil();
			    //prop.first = luabridge::LuaNil();
			    //this->properties.at(prop.first) = luabridge::LuaNil();	
			//}
			//this->properties.clear();


		    for (auto &prop : this->hooks) {
				std::vector<std::string> k = this->hooks.at(prop.first);

				for (int i = k.size(); i--> 0;)
				{
					auto it = allHooks.find(k[i]);
                    if (it == allHooks.end())
                    	continue;

					//luabridge::LuaRef j2 = it->second;
					//j2 = luabridge::LuaNil();
					allHooks.at(it->first) = luabridge::LuaNil();
					allHooks.erase(it); 
					//std::cout << "\n\n" << it->first << "\n\n";
				}
		    }
		    //this->hooks.clear();
		    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
		}

		~FlexibleClass(){
			//this->clear();
		}

		void remove(){     
			this->localRef = luabridge::LuaNil();
			//this->clear();
			//this->~FlexibleClass();
			//delete( this );
			this->removing = true;


			for(std::unordered_map<std::string, luabridge::LuaRef>::const_iterator iter = this->properties.begin(); iter != this->properties.end(); ++iter)
			{
			    //this->properties.at(iter->first) = luabridge::LuaNil();

				if( iter->second.isInstance<FlexibleClass>() ){
			    	//iter->second["remove"]( iter->second );

		        	auto result = iter->second.cast<FlexibleClass*>();
		        	//prop.second["remove"]( prop.second );

			        if (result) {
			            FlexibleClass* obj = result.value();
			            //std::cerr << "DEL: " << obj->name << "\n";
			            obj->remove();
						//obj->localRef = luabridge::LuaNil();
						//this->clear();
						//this->~FlexibleClass();

						//delete( this );
						//obj->removing = true;
			        } else {
			            //std::cout << "Failed to cast LuaRef to FlexibleClass*" << std::endl;
			        }
				}
			    
			    //iter->second = luabridge::LuaNil();
			    //this->properties.erase( iter->first );
			}

            for (int i = luaInit::luaFlexibleObjects.size(); i--> 0;)
            {
                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
                
                if( temp->id == this->id ){
                    temp->clear();
                    temp = nullptr;
                    luaInit::luaFlexibleObjects[i] = nullptr;
                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                    //delete temp;
                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                    break;
                }
            }


			luaInit::luaFlexibleObjectsRemoving.push_back(this);
			lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
		}

		void removeC(){     
			this->localRef = luabridge::LuaNil();
			//this->clear();
			//this->~FlexibleClass();
			//delete( this );
			this->removing = true;
            //this->clear();
		}

        void addHook( std::string hook, luabridge::LuaRef func ){
        	if( this->removing )
        		return;

        	std::string refID = func.tostring();
        	//std::cout << "\nHookHash: " << refID << "\n\n";
	        if (allHooks.find(this->name + "_" + hook + refID + std::to_string(this->id) ) == allHooks.end()){
				//lua_State* newThreadState = luaFunctions::init();
				//luaFunctions::initClasses(newThreadState);
				//func.moveTo(newThreadState);

				//func.push(luaInit::luaState);
				//int referenceIndex = luaL_ref(luaInit::luaState, LUA_REGISTRYINDEX);
				//lua_rawgeti(newThreadState, LUA_REGISTRYINDEX, referenceIndex);
				//lua_xmove(luaInit::luaState, newThreadState, 1);
				
				//luaL_unref(luaInit::luaState, LUA_REGISTRYINDEX, referenceIndex);


				//func.push(newThreadState);
				//lua_xmove(luaInit::luaState, newThreadState, 1); 

				//threadStates.push_back(newThreadState);

				//func = luabridge::LuaRef(threadStates[threadStates.size()-1], 1); 
				//luabridge::LuaRef newRef = luabridge::LuaRef::fromStack(newThreadState, -1);
	        	
	            allHooks.emplace( std::make_pair(this->name + "_" + hook + refID + std::to_string(this->id), func) );
	        }

            this->hooks[hook].push_back(this->name + "_" + hook + refID + std::to_string(this->id));
        }

        void setName( std::string name ){
        	if( this->removing )
        		return;

            this->name = name;
        }

        void setRef( luabridge::LuaRef ref ){
            this->localRef = ref;
        }
        
	};

	class flexTable
	{
	public:
		std::vector<FlexibleClass*> entities;
		std::string method;

		flexTable();
		
		flexTable* selectMethod(flexTable& self, const luabridge::LuaRef& key, lua_State* L)
		{
			this->method = key.tostring();
			return this;
		}

		luabridge::LuaRef fireFunction(luabridge::LuaRef args)
		{
			luabridge::LuaRef temp = luabridge::LuaRef (luaInit::luaState, luabridge::LuaNil ());

			for (int i = 0; i < this->entities.size(); i++)
			{
				temp = this->entities[i]->localRef[this->method](this->entities[i], args);
			}

			return temp;
		}
		
	};
    
    luabridge::LuaRef getObjectsList(){
		luabridge::LuaRef luaVec = luabridge::newTable(luaInit::luaState);
		for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++) {
			luaVec[i + 1] = (luaClasses::FlexibleClass*)(luaInit::luaFlexibleObjects[i]);
		}

        return luaVec;
    }

    luabridge::LuaRef Query(std::string filter){
    	std::string code = ""
    		"local all_objects = ents.list()\n"
    		"local new_list = {}\n"
			"for _,ent in pairs(all_objects) do\n"
				"if ent"+filter+" then\n"
					"table.insert(new_list, ent)\n"
				"end\n"
			"end\n"
    		"return new_list";

    	luaFunctions::do_string_error( code );
    	return luabridge::LuaRef::fromStack( luaInit::luaState , -1);  
    }
    
}