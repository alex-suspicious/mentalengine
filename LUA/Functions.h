namespace luaFunctions{
    void quit(){
        exit(0);
    }

    void print( std::string text ){
    	//std::cout << text << "\n";
    	mental::consoleBuffer = mental::consoleBuffer + "\n" + text;
    	//if( mental::consoleBuffer.size() > 350 ){
    	//	mental::consoleBuffer = mental::consoleBuffer.substr(0, 350);
    	//}
    }


    bool do_string_error( std::string luaCode ){
        
        int result = luaL_dostring(luaInit::luaState, luaCode.c_str());

        if (result != LUA_OK) {
            luaFunctions::print( "!" + m_str::replaceSubStr(std::string( lua_tostring(luaInit::luaState, -1) ) + "\n_____________\n" + luaCode,"\n","\n!") );
            lua_pop(luaInit::luaState, 1); // Pop error message from the stack
            return false;
        } 

        return true;
    }

    void do_string_error_safe( std::string luaCode ){
        int result = luaL_dostring(luaInit::luaState, luaCode.c_str());

        if (result != LUA_OK) {
            luaFunctions::print( "!" + m_str::replaceSubStr(std::string( lua_tostring(luaInit::luaState, -1) ) + "\n_____________\n" + luaCode,"\n","\n!") );
            lua_pop(luaInit::luaState, 1);
            return;
        }
    }

    namespace Android{
        void showKeyboard(){
            //sf::Keyboard::setVirtualKeyboardVisible(true);
        }

        void hideKeyboard(){
            //sf::Keyboard::setVirtualKeyboardVisible(false);
        }
    }

    void remove( luabridge::LuaRef ent ){
        ent = luabridge::LuaNil();
    }

    std::function<lua_State*()> init;
    std::function<void(lua_State*)> initClasses;


    void loadString( std::string luaCode ){
        std::lock_guard<std::mutex> guard(render::renderMutex);
        
        luaCode = syntax::ternary(luaCode);
        luaCode = syntax::classes(luaCode);
        luaCode = syntax::lambdas(luaCode);

        do_string_error(luaCode.c_str());
    }

    void loadStringSchedule( std::string luaCode ){
        //if( thread::thread_safe ){
            //thread::thread_safe = false;
            std::lock_guard<std::mutex> guard(thread::luaMutex);
            loadString( luaCode );
            //thread::thread_safe = true;
        //}else{
            //thread::callbacks_str.push_back( luaCode );
        //}
    }

    void loadStringOlds(){
        if( thread::callbacks_str.size() < 1 )
            return;
        
        //if( thread::thread_safe ){
            //thread::thread_safe = false;
        std::lock_guard<std::mutex> guard(thread::luaMutex);
            for (int i = 0; i < thread::callbacks_str.size(); i++)
            {
                loadString( thread::callbacks_str[i] );
            }
            thread::callbacks_str.clear();
            //thread::thread_safe = true;
        //}
        
    }

}