namespace luaManager{

	std::string decrypt( std::string file, std::string Code ){
    	std::string temp = "";
    	int num = 0;
    	for (int i = 0; i < file.length(); i++)
    	{
    		num += file[i];
    	}
    	num = 1 + floor(num/1000);
    	//std::cout << "Num: " << num << "\n";

    	for (int i = 0; i < Code.length(); i++)
    	{
    		temp += (Code[i] - num);
    	}

    	return temp;
	}

//    std::string initLuaClassConstructors( std::string Code ){
//		for (int i = 0; i < luaClasses.size(); i++)
//		{
//			Code = m_str::replaceSubStr(Code, luaClasses[i] + "(", luaClasses[i] + ":new(");
//		}
//		return Code;
//    }

    void import( std::string path ){
		std::string luaCode = file::read("logic/" + m_str::replaceSubStr(m_str::replaceSubStr(path," ","/"), "assets/logic/", "") );

		if (luaCode == "") {
			luaFunctions::print( "!" + path + " file does not exists!" );
		}else{
			//luaCode = decrypt(path, luaCode);
			luaCode = syntax::ternary(luaCode);
			luaCode = syntax::classes(luaCode);
			luaCode = syntax::lambdas(luaCode);
			//luaCode = initLuaClassConstructors(luaCode);

			//std::cout << path << "\n\n" << luaCode;

			luaFunctions::do_string_error( luaCode );
			//luaFunctions::print( path + " was executed!" );
		}
		
    }

    void initClasses( lua_State* luaState ){
    	luabridge::getGlobalNamespace(luaState)
    		.beginNamespace ("collision")
				.addFunction ("box", &body::box)
				.addFunction ("circle", &body::circle)
				.addFunction ("convex", &body::convex)
				.beginClass<b2PolygonShape> ("shape")
					.addConstructor<void ()> ()
				.endClass()
				.beginClass<b2CircleShape> ("shape_cirlce")
					.addConstructor<void ()> ()
				.endClass()
				.addFunction ("trace", (body::rayOutput (*)(amath::Vector2, amath::Vector2, body::rigidbody*))&body::trace, (body::rayOutput (*)(amath::Vector2, amath::Vector2))&body::trace)
			.endNamespace ()
    		.beginNamespace ("physics")
				.beginClass<body::rigidbody> ("rigidbody")
					.addConstructor<void(b2PolygonShape), void(b2CircleShape)> ()
					.addFunction ("getPos", &body::rigidbody::getPosition)
					.addFunction ("getRotation", &body::rigidbody::getRotation)
					.addFunction ("setPos", &body::rigidbody::setPosition)
					.addFunction ("setRotation", &body::rigidbody::setRotation)
					.addFunction ("setFixedRotation", &body::rigidbody::setFixedRotation)
					.addFunction ("getFixedRotation", &body::rigidbody::getFixedRotation)
					.addFunction ("setVelocity", &body::rigidbody::setVelocity)
					.addFunction ("getVelocity", &body::rigidbody::getVelocity)
					.addFunction ("setAngularVelocity", &body::rigidbody::setAngularVelocity)
					.addFunction ("getAngularVelocity", &body::rigidbody::getAngularVelocity)
					.addFunction ("applyVelocity", &body::rigidbody::applyVelocity)
					.addFunction ("applyAngularVelocity", &body::rigidbody::applyAngularVelocity)
					.addFunction ("setAngularDamping", &body::rigidbody::setAngularDamping)
					.addFunction ("getAngularDamping", &body::rigidbody::getAngularDamping)
					.addFunction ("setLinearDamping", &body::rigidbody::setLinearDamping)
					.addFunction ("getLinearDamping", &body::rigidbody::getLinearDamping)
					.addFunction ("setBullet", &body::rigidbody::setBullet)
					.addFunction ("getBullet", &body::rigidbody::getBullet)
					.addFunction ("setBouncy", &body::rigidbody::setBouncy)
					.addFunction ("setGravityFactor", &body::rigidbody::setGravityFactor)
					.addFunction ("setFriction", &body::rigidbody::setFriction)
					.addFunction ("setType", &body::rigidbody::setType)
					.addFunction ("setSensor", &body::rigidbody::setSensor)
					.addFunction ("setOwner", &body::rigidbody::setOwner)
					.addFunction ("isColliding", &body::rigidbody::isColliding)
					.addFunction ("collidersCount", &body::rigidbody::collidersCount)
					.addFunction ("addFilter", &body::rigidbody::addFilter)
					.addFunction ("remove", &body::rigidbody::remove)
					.addProperty ("hitSound", &body::rigidbody::hitSound)
				.endClass()
				.beginClass<body::rayOutput> ("rayOutput")
					.addConstructor<void (amath::Vector2, amath::Vector2, float)> ()
					.addProperty ("normal", &body::rayOutput::normal)
					.addProperty ("point", &body::rayOutput::point)
					.addProperty ("distance", &body::rayOutput::distance)
				.endClass()
			.endNamespace ()
      		.beginNamespace ("mnt")
				.beginClass<mental::dynamic> ("sprite")
					.addConstructor<void (std::string, bool), void (std::string)> ()
					.addProperty ("active", &mental::dynamic::active)
					.addProperty ("screenBorders", &mental::dynamic::screenBorders)
					.addFunction ("setPos", &mental::dynamic::setPosition, &mental::dynamic::setPositionByVectorLua)
					.addFunction ("getPos", &mental::dynamic::getPositionLua)
					.addFunction ("setRotation", &mental::dynamic::setRotation)
					.addFunction ("getRotation", &mental::dynamic::getRotation)
					.addFunction ("setScale", &mental::dynamic::setScale, &mental::dynamic::setScaleXY)
					.addFunction ("setColor", &mental::dynamic::setColor)
					.addFunction ("loadShader", &mental::dynamic::loadShader)
					.addFunction ("loadTexture", &mental::dynamic::loadTexture)
					.addFunction ("setLayer", &mental::dynamic::setLayer)
					.addFunction ("getLayer", &mental::dynamic::getLayer)
					.addFunction ("setRectSize", &mental::dynamic::setRectSize, &mental::dynamic::setRectSizeXY )
					.addFunction ("setRectPos", &mental::dynamic::setRectPos, &mental::dynamic::setRectPosXY )
					.addFunction ("getBounds", &mental::dynamic::getBounds)
					.addFunction ("screenCoords", &mental::dynamic::screenCoords)
					.addFunction ("setDepth", &mental::dynamic::setDepth)
					.addFunction ("setScreenCords", &mental::dynamic::setScreenCords)
					.addFunction ("setInterpolation", &mental::dynamic::setInterpolation)
					.addFunction ("remove", &mental::dynamic::remove)
					.addFunction ("setShaderFloat", &mental::dynamic::setShaderFloat)
					.addFunction ("setShaderInt", &mental::dynamic::setShaderInt)
					.addFunction ("setShaderFloatArray", &mental::dynamic::setShaderFloatArray)
					.addFunction ("setShaderColor", &mental::dynamic::setShaderColor)
				.endClass()
				.beginClass<renderable::model> ("model")
					.addConstructor<void (std::string), void ()> ()
					.addProperty ("pitch", &renderable::model::pitch)
					.addProperty ("yaw", &renderable::model::yaw)
					.addProperty ("roll", &renderable::model::roll)
					.addFunction ("setScale", &renderable::model::setScale)
					.addFunction ("setPos", &renderable::model::setPositionXYZ, &renderable::model::setPositionByVectorLua, &renderable::model::setPositionByVector2DLua)
					.addFunction ("getPos", &renderable::model::getPosition)
				.endClass()
				.beginClass<gui::text> ("text")
					.addConstructor<void (std::string, std::string), void (std::string, std::string, int), void (), void (std::string)> ()
					.addFunction ("setPos", (void (gui::text::*)(amath::Vector2)) &gui::text::setPosition, (void (gui::text::*)(float, float)) &gui::text::setPosition)
					.addFunction ("getPos", &gui::text::getPosition)
					.addFunction ("setRotation", &gui::text::setRotation)
					.addFunction ("setScale", &gui::text::setScale)
					.addFunction ("setSize", &gui::text::setSize)
					.addFunction ("setFont", &gui::text::setFont)
					.addFunction ("getBounds", &gui::text::getBoundsXY)
					.addFunction ("setOutlineColor", &gui::text::setOutlineColor)
					.addFunction ("setOutlineThickness", &gui::text::setOutlineThickness)
					.addFunction ("setColor", &gui::text::setColor)
					.addFunction ("setString", &gui::text::setString)
					.addFunction ("screenCoords", &gui::text::screenCoords)
				.endClass ()
				.beginClass<mental::color> ("color")
					.addConstructor<void (float,float,float), void (float,float,float,float)> ()
					.addProperty ("r", &mental::color::r)
					.addProperty ("g", &mental::color::g)
					.addProperty ("b", &mental::color::b)
					.addProperty ("a", &mental::color::a)
				.endClass ()
				.beginClass<amath::Vector3> ("vector3")
					.addConstructor<void (), void (float, float, float)> ()
					.addProperty ("x", &amath::Vector3::x)
					.addProperty ("y", &amath::Vector3::y)
					.addProperty ("z", &amath::Vector3::z)
			        .addProperty("xxx", &amath::Vector3::xxx )
			        .addProperty("xxy", &amath::Vector3::xxy )
			        .addProperty("xxz", &amath::Vector3::xxz )
			        .addProperty("xyx", &amath::Vector3::xyx )
			        .addProperty("xyy", &amath::Vector3::xyy )
			        .addProperty("xyz", &amath::Vector3::xyz )
			        .addProperty("xzx", &amath::Vector3::xzx )
			        .addProperty("xzy", &amath::Vector3::xzy )
			        .addProperty("xzz", &amath::Vector3::xzz )
			        .addProperty("yxx", &amath::Vector3::yxx )
			        .addProperty("yxy", &amath::Vector3::yxy )
			        .addProperty("yxz", &amath::Vector3::yxz )
			        .addProperty("yyx", &amath::Vector3::yyx )
			        .addProperty("yyy", &amath::Vector3::yyy )
			        .addProperty("yyz", &amath::Vector3::yyz )
			        .addProperty("yzx", &amath::Vector3::yzx )
			        .addProperty("yzy", &amath::Vector3::yzy )
			        .addProperty("yzz", &amath::Vector3::yzz )
			        .addProperty("zxx", &amath::Vector3::zxx )
			        .addProperty("zxy", &amath::Vector3::zxy )
			        .addProperty("zxz", &amath::Vector3::zxz )
			        .addProperty("zyx", &amath::Vector3::zyx )
			        .addProperty("zyy", &amath::Vector3::zyy )
			        .addProperty("zyz", &amath::Vector3::zyz )
			        .addProperty("zzx", &amath::Vector3::zzx )
			        .addProperty("zzy", &amath::Vector3::zzy )
			        .addProperty("zzz", &amath::Vector3::zzz )
			        .addProperty("xx", &amath::Vector3::xx )
			        .addProperty("xy", &amath::Vector3::xy )
			        .addProperty("xz", &amath::Vector3::xz )
			        .addProperty("yy", &amath::Vector3::yy )
			        .addProperty("yx", &amath::Vector3::yx )
			        .addProperty("yz", &amath::Vector3::yz )
			        .addProperty("zz", &amath::Vector3::zz )
			        .addProperty("zx", &amath::Vector3::zx )
			        .addProperty("zy", &amath::Vector3::zy )
					.addFunction("string", &amath::Vector3::toString)
					.addFunction("__add", (amath::Vector3 (amath::Vector3::*)(amath::Vector3))&amath::Vector3::operator+, (amath::Vector3 (amath::Vector3::*)(float))&amath::Vector3::operator+ )
					.addFunction("__mul", (amath::Vector3 (amath::Vector3::*)(amath::Vector3))&amath::Vector3::operator*, (amath::Vector3 (amath::Vector3::*)(float))&amath::Vector3::operator* ) 
					.addFunction("__sub", (amath::Vector3 (amath::Vector3::*)(amath::Vector3))&amath::Vector3::operator-, (amath::Vector3 (amath::Vector3::*)(float))&amath::Vector3::operator- ) 
					.addFunction("__div", (amath::Vector3 (amath::Vector3::*)(amath::Vector3))&amath::Vector3::operator/, (amath::Vector3 (amath::Vector3::*)(float))&amath::Vector3::operator/ ) 
				.endClass ()
				.beginClass<amath::Vector2> ("vector2")
					.addConstructor<void (), void (float, float)> ()
					.addProperty ("x", &amath::Vector2::x)
					.addProperty ("y", &amath::Vector2::y)
        			.addProperty("xxx", &amath::Vector2::xxx )
        			.addProperty("xxy", &amath::Vector2::xxy )
        			.addProperty("xyx", &amath::Vector2::xyx )
        			.addProperty("xyy", &amath::Vector2::xyy )
        			.addProperty("yxx", &amath::Vector2::yxx )
        			.addProperty("yxy", &amath::Vector2::yxy )
        			.addProperty("yyx", &amath::Vector2::yyx )
        			.addProperty("yyy", &amath::Vector2::yyy )
        			.addProperty("xx", &amath::Vector2::xx )
        			.addProperty("xy", &amath::Vector2::xy )
        			.addProperty("yy", &amath::Vector2::yy )
        			.addProperty("yx", &amath::Vector2::yx )
					.addFunction("string", &amath::Vector2::toString)
					.addFunction("length", &amath::Vector2::length)
					.addFunction("reflect", &amath::Vector2::reflect)
					.addFunction("normalize", &amath::Vector2::normalize)
					.addFunction("distance", &amath::Vector2::distance)
					.addFunction("lerp", &amath::Vector2::lerp)
					.addFunction("angle", &amath::Vector2::angle)
					.addFunction("radians", &amath::Vector2::radians)
					.addFunction("align", &amath::Vector2::align)
					.addFunction("right", &amath::Vector2::right)
					.addFunction("left", &amath::Vector2::left)
					.addFunction("forward", &amath::Vector2::forward)
					.addFunction("backward", &amath::Vector2::backward)
					.addFunction("rotate", &amath::Vector2::rotate)
					.addFunction("__add", (amath::Vector2 (amath::Vector2::*)(amath::Vector2))&amath::Vector2::operator+, (amath::Vector2 (amath::Vector2::*)(float))&amath::Vector2::operator+ )
					.addFunction("__mul", (amath::Vector2 (amath::Vector2::*)(amath::Vector2))&amath::Vector2::operator*, (amath::Vector2 (amath::Vector2::*)(float))&amath::Vector2::operator* ) 
					.addFunction("__sub", (amath::Vector2 (amath::Vector2::*)(amath::Vector2))&amath::Vector2::operator-, (amath::Vector2 (amath::Vector2::*)(float))&amath::Vector2::operator- ) 
					.addFunction("__div", (amath::Vector2 (amath::Vector2::*)(amath::Vector2))&amath::Vector2::operator/, (amath::Vector2 (amath::Vector2::*)(float))&amath::Vector2::operator/ ) 
				.endClass ()
				.beginClass<amath::Angle> ("angle")
					.addConstructor<void (double), void ()> ()
			        .addProperty("value", &amath::Angle::value)
			        .addFunction("normal", &amath::Angle::normal)
			        .addFunction("degrees", &amath::Angle::degrees)
			        .addFunction("radians", &amath::Angle::radians)
			        .addFunction("__add", &amath::Angle::operator+)
			        .addFunction("__sub", &amath::Angle::operator-)
			        .addFunction("__mul", &amath::Angle::operator*)
			        .addFunction("__div", &amath::Angle::operator/)
			        .addFunction("__eq", &amath::Angle::operator==)
			        .addFunction("__lt", &amath::Angle::operator<)
			        .addFunction("__le", &amath::Angle::operator<=)
				.endClass ()
			    .beginClass<luaClasses::FlexibleClass>("FlexibleClass")
			    	.addConstructor<void ()> ()
			    	.addFunction ("addHook", &luaClasses::FlexibleClass::addHook)
			    	.addFunction ("setName", &luaClasses::FlexibleClass::setName)
					.addFunction ("remove", &luaClasses::FlexibleClass::remove)
					.addFunction ("setRef", &luaClasses::FlexibleClass::setRef)
			    	.addProperty ("class", &luaClasses::FlexibleClass::name, false)
			    	.addProperty ("name", &luaClasses::FlexibleClass::name, false)
			    	.addProperty ("id", &luaClasses::FlexibleClass::id, false)
			    	//.addProperty ("removing", &luaClasses::FlexibleClass::removing, false)
					.addIndexMetaMethod ([] (luaClasses::FlexibleClass& self, const luabridge::LuaRef& key, lua_State* L)
					{
						auto it = self.properties.find(key.tostring());
						if (it != self.properties.end())
							return it->second;

						return luabridge::LuaRef (L, luabridge::LuaNil ()); // or luaL_error("Failed lookup of key !")
					})
					.addNewIndexMetaMethod ([] (luaClasses::FlexibleClass& self, const luabridge::LuaRef& key, const luabridge::LuaRef& value, lua_State* L)
					{
						auto it = self.properties.find(key.tostring());
						if (it != self.properties.end()){
							it->second = value;
							return luabridge::LuaRef (L, luabridge::LuaNil ());
						}

						self.properties.emplace (std::make_pair (key.tostring(), value));
						return luabridge::LuaRef (L, luabridge::LuaNil ());
					})
			    .endClass ()
	  		.endNamespace ();
    }

    void importClasses(){
	    std::map<std::string, std::string>::iterator it;
		for (it = fs::files.begin(); it != fs::files.end(); it++)
		{
			//std::cout << it->first << "\n";
	        if ( m_str::includesRaw(it->first, "logic/entities") )
	        {
	        	import(it->first);
	        }
		}

        for (int i = 0; i < addons::dirs.size(); i++)
        {
    		std::filesystem::path filepath = std::string(addons::dirs[i] + "/logic/entities/");
			bool filepathExists = std::filesystem::is_directory(filepath.parent_path());
			if( !filepathExists )
				continue;

			for(auto& p : std::filesystem::recursive_directory_iterator( addons::dirs[i] + "/logic/entities" )){
	        	if (!p.is_directory()){
	            	luaFunctions::loadString( file::readRaw( p.path().string() ) );
	            	luaFunctions::print( "+" + p.path().string() + " was executed!" );
	        	}
	        }
        }

	    std::map<std::string, std::string>::iterator itAuto;
		for (itAuto = fs::files.begin(); itAuto != fs::files.end(); itAuto++)
		{
			//std::cout << it->first << "\n";
	        if ( m_str::includesRaw(itAuto->first, "logic/autorun") )
	        {
	        	import(itAuto->first);
	        }
		}
		
//		std::vector<std::string> ents = m_str::split(file::read("logic/lua.entities"), '\n');
//		for (int i = 0; i < ents.size(); ++i)
//		{
//			std::cout << ents[i] << "\n";
//			import("entities/" + ents[i]);
//		}
    }

    void clear(){
    	//thread::thread_safe = false;

    	luaFunctions::print( "+Scene was cleared!" );

        for (int i = 0; i < physics::bodies.size(); i++)
        {
            //physics::world->DestroyBody(physics::bodies[i]);
            physics::bodies[i]->GetUserData().pointer = (uintptr_t)body::removing;
            //physics::bodies[i] = nullptr;
            //physics::bodies[i]->SetSleepingAllowed(false);

            //physics::bodies.erase(physics::bodies.begin() + i);
        }
//
        //for (int i = 0; i < guiInit::texts.size(); i++)
        //{
        //	gui::text* temp = (gui::text*)guiInit::texts[i];
        //	temp->removing = true;
            //guiInit::texts[i] = nullptr;
            //guiInit::texts.erase(guiInit::texts.begin() + i);
        //}
//
//        for (int i = 0; i < guiInit::texts_native.size(); i++)
//        {
//            guiInit::texts_native[i] = nullptr;
//            guiInit::texts_native.erase(guiInit::texts_native.begin() + i);
//        }

        for (int i = mental::brushBuffer.size()-1; i > 0; i--)
        {
        	((mental::brush*)mental::brushBuffer[i])->removed = true;
            mental::brushBuffer[i] = nullptr;
            mental::brushBuffer.erase(mental::brushBuffer.begin() + i);
        }

        for (int i = 0; i < mental::renderablesBuffer.size(); i++)
        {
        	renderable::sprite* temp = ((renderable::sprite*)mental::renderablesBuffer[i]);
        	temp->removed = true;
            //mental::renderablesBuffer[i] = nullptr;
            //mental::renderablesBuffer.erase(mental::renderablesBuffer.begin() + i);
        }

        for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
        {
            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
            temp->removeC();
//            temp = nullptr;
//            luaInit::luaFlexibleObjects[i] = nullptr;
//            luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);

            //temp = nullptr;

            //luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);

            //luaInit::luaFlexibleObjects[i] = nullptr;
            
            //delete temp;
        }

        for (int i = mental::dynamicsBuffer.size()-1; i > 0; i--)
        {
        	mental::dynamicsBuffer[i] = nullptr;
            mental::dynamicsBuffer.erase(mental::dynamicsBuffer.begin() + i);
        }

        lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//		for(std::unordered_map<std::string, luabridge::LuaRef>::const_iterator iter = luaClasses::allHooks.begin(); iter != luaClasses::allHooks.end(); ++iter)
//		{
//		    iter->second = luabridge::LuaNil();
//		    luaClasses::allHooks.erase( iter->first );
//		}

        //lua_close(luaInit::luaState);
	    //luaInit::luaState = luaFunctions::init();
	    //luaFunctions::initClasses(luaInit::luaState);
	    //luaManager::importClasses();
	    //thread::thread_safe = true;
    }

    lua_State* init(){
	    lua_State* luaState = luaL_newstate();
    	luaL_openlibs(luaState);

	    luabridge::getGlobalNamespace(luaState)
	    .addFunction("print", luaFunctions::print)
	    .addFunction ("find", luaClasses::Query)
	    .beginNamespace("android")
			.addFunction ("showKeyboard", &luaFunctions::Android::showKeyboard)
			.addFunction ("hideKeyboard", &luaFunctions::Android::hideKeyboard)
			.addProperty ("joystick", &mental::window->mobile_joystick, true)
		.endNamespace ()
	    .beginNamespace("sensors")
			.addFunction ("enableAccelerometer", &sensors::enableAccelerometer)
			.addFunction ("enableGyroscope", &sensors::enableGyroscope)
			.addFunction ("enableAcceleration", &sensors::enableAcceleration)
			.addFunction ("enableOrientation", &sensors::enableOrientation)
			.addFunction ("enableGravity", &sensors::enableGravity)
			.addFunction ("disableAccelerometer", &sensors::disableAccelerometer)
			.addFunction ("disableGyroscope", &sensors::disableGyroscope)
			.addFunction ("disableAcceleration", &sensors::disableAcceleration)
			.addFunction ("disableOrientation", &sensors::disableOrientation)
			.addFunction ("disableGravity", &sensors::disableGravity)
			.addFunction ("getAccelerometer", &sensors::getAccelerometer)
			.addFunction ("getGyroscope", &sensors::getGyroscope)
			.addFunction ("getAcceleration", &sensors::getAcceleration)
			.addFunction ("getOrientation", &sensors::getOrientation)
			.addFunction ("getGravity", &sensors::getGravity)
		.endNamespace ()
	    .beginNamespace("http")
			.addFunction ("get", &http::get)
		.endNamespace ()
	    .beginNamespace("json")
			.addFunction ("parse", &mjson::parse)
			.addFunction ("dump", &mjson::luaTableToJson)
		.endNamespace ()
	    .beginNamespace("save")
			.addFunction ("write", &mental::save::write)
			.addFunction ("read", &mental::save::read)
		.endNamespace ()
	    .beginNamespace("controller")
			.addProperty ("leftStick", &Input::axis::leftStick, false)
		.endNamespace ()
	    .beginNamespace("keyboard")
			.addFunction ("isPressed", &Input::keyboard::isDownLua)
		.endNamespace ()
		.beginNamespace("screen")
			.addProperty ("width", &mental::window->resolution.x, false)
			.addProperty ("height", &mental::window->resolution.y, false)
			.addFunction ("addShader", &mental::window_lua::loadShader)
			.addFunction ("setShaderEnabled", &mental::window_lua::setShaderEnabled)
			.addFunction ("setShaderFloat", &mental::window_lua::setShaderFloat)
			.addFunction ("setShaderInt", &mental::window_lua::setShaderInt)
			.addFunction ("setShaderFloatArray", &mental::window_lua::setShaderFloatArray)
			.addFunction ("setShaderColor", &mental::window_lua::setShaderColor)
		.endNamespace ()
		.beginNamespace("window")
			.addFunction ("toggleFullscreen", &mental::window_lua::toggleFullscreen )
		.endNamespace ()
		.beginNamespace("pointer")
			.addFunction ("getPos", &Input::pointer::getPositionGlobalLua)
			.addFunction ("getWorldPos", &mental::window_lua::getPositionWorldLua)
		.endNamespace ()
		.beginNamespace("global")
			.addFunction ("addHook", &mental::window_lua::addHookLua)
			.addFunction ("triggerHook", &mental::window_lua::triggerHookLua)
			.addFunction ("objects", &luaClasses::getObjectsList)
		.endNamespace ()
		.beginNamespace("sound")
		//	.addFunction ("play", &mental::playSound)
		.endNamespace ()
		.beginNamespace("cam")
			.addFunction ("setPos", &mental::window_lua::setCamPos, &mental::window_lua::setCamPosXY)
			.addFunction ("getPos", &mental::window_lua::getCamPos)
			.addFunction ("setZoom", &mental::window_lua::setCamZoom)
			.addProperty ("width", &mental::window->cameraSize.x, false)
			.addProperty ("height", &mental::window->cameraSize.y, false)
		.endNamespace ()
		.beginNamespace("debug")
			.addFunction ("isEnabled", &mental::window_lua::isEnabled)
			.addFunction ("setEnabled", &mental::window_lua::setEnabled)
		.endNamespace ()
//		#if !defined(ANDROID_VERSION)
//		.beginNamespace("imgui")
//			.addFunction ("SetNextWindowSize", &debug::SetNextWindowSize)
//			.addFunction ("Begin", &debug::Begin)
//			.addFunction ("End", &debug::End)
//		.endNamespace ()
//		#endif
		.beginNamespace("time")
			.addProperty ("current", &mental::window->time, false)
			.addProperty ("delta", &amath::delta, false)
		.endNamespace ()
		.beginNamespace("file")
			.addFunction ("read", &file::readRaw)
			.addFunction ("write", &file::write)
		.endNamespace ()
		.beginNamespace("dir")
			.addFunction ("list", &file::ls)
		.endNamespace ()
		.beginNamespace("lua")
			.addFunction ("interprete", &luaFunctions::loadString)
			.addFunction ("clear", &clear)
		.endNamespace ()
		.beginNamespace("sky")
			.addFunction ("setColor", &mental::window_lua::skyColor)
		.endNamespace ()
		.beginNamespace("math")
			.addFunction ("clamp", &amath::clip)
			.addFunction ("lerp", &amath::lerp)
		.endNamespace ()
		.beginNamespace("addons")
			.addFunction ("list", &addons::list)
		.endNamespace ()
		.beginNamespace("physics")
			.addFunction ("setGravity", &physics::setGravity)
			.addFunction ("setSpeed", &physics::setSpeed)
		.endNamespace ()
		.beginNamespace("gui")
			//.addFunction ("load", &gui::load)
			//.addFunction ("clear", &gui::clear)
			.addFunction ("setFont", &gui::GuiSetFont)
			.addFunction ("setStyle", &gui::GuiSetStyle)
			.addFunction ("button", &gui::GuiButton)
		.endNamespace ()
		.beginNamespace("str")
			.addFunction ("split", &m_str::split)
		.endNamespace ()
		.beginNamespace("async")
			.addFunction ("timeout", &luaInterval::create)
		.endNamespace ()
		.beginNamespace("ents")
			.addFunction ("list", &luaClasses::getObjectsList)
		.endNamespace ()
		.beginNamespace("music")
			.addFunction ("load", &mental::music::load)
			.addFunction ("play", &mental::music::play)
			.addFunction ("pause", &mental::music::pause)
			.addFunction ("stop", &mental::music::stop)
			.addFunction ("setVolume", &mental::music::setVolume)
		.endNamespace ()
		.beginNamespace("game")
			.addFunction ("exit", &luaFunctions::quit)
		.endNamespace ();

		return luaState;
    }

    void updateInitFunctions(){
	    luaFunctions::init = *init;
	    luaFunctions::initClasses = *initClasses;
    }

    void loadFile( std::string path ){
		//std::string scriptString;

		//std::ifstream luaFile;
    	//mental::consoleBuffer = "";
		std::string luaCode = file::read("logic/" + path);

		if (luaCode == "") {
			luaFunctions::print( "!" + path + " file does not exists!" );
		}else{
			//luaCode = decrypt(path, luaCode);
			luaCode = syntax::ternary(luaCode);
			luaCode = syntax::classes(luaCode);
			luaCode = syntax::lambdas(luaCode);
			//luaCode = initLuaClassConstructors(luaCode);

			//std::cout << path << "\n\n" << luaCode;

		    luabridge::getGlobalNamespace(luaInit::luaState).addFunction ("import", &import);

			luaFunctions::do_string_error( luaCode );
			luaFunctions::print( "+" + path + " was executed!" );
		}
		
    }

}