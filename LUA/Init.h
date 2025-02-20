

//void lua_lock(lua_State* L) {
//    luaMutex.lock();
//}
//
//void lua_unlock(lua_State* L) {
//    luaMutex.unlock();
//}

namespace thread{
    //std::atomic<bool> thread_safe (true);
    std::mutex luaMutex;

    std::vector<std::function<void()>> callbacks;
    std::vector<std::string> callbacks_str;

    void run_lua( std::function<void()> callback, bool schedule = false ){
        //if( !luaMutex.is_locked() ){
            //thread_safe = false;
            //luaMutex.lock();
            std::lock_guard<std::mutex> guard(luaMutex);
            callback();
            //luaMutex.unlock();
            //thread_safe = true;
        //}else if( schedule ){
            //callbacks.push_back( callback );
        //}
    }

    void run_olds(){
        if( callbacks.size() < 1 )
            return;

        //if( !luaMutex.is_locked() ){
            //thread_safe = false;
            std::lock_guard<std::mutex> guard(luaMutex);
            //luaMutex.lock();
            for (int i = 0; i < callbacks.size(); i++)
            {
                callbacks.at(i)();
            }
            callbacks.clear();
            //thread_safe = true;
            //luaMutex.unlock();
        //}
    }
}

namespace luaInit{
    lua_State* luaState;
    //lua_State* luaStatePhysics;
    //lua_State* luaStateRender;

    std::vector<void*> luaFlexibleObjects;
    std::vector<void*> luaFlexibleObjectsRemoving;
}

namespace syntax{

    std::string ternary( std::string Code ){
        //(a and "blah" or "nahblah")

        std::vector<std::string> splitted;
        splitted = m_str::split(Code, '\n');
        std::string temp = "";
        for (int i = 0; i < splitted.size(); i++)
        {
            if(
                m_str::includes( splitted[i], "==" ) &&
                m_str::includes( splitted[i], "?" ) &&
                m_str::includes( splitted[i], "\"" ) &&
                m_str::includes( splitted[i], ":" )
            ){
                splitted[i] = m_str::replaceSubStr(splitted[i],"?","and");
                splitted[i] = m_str::replaceSubStr(splitted[i],":","or");
            }

            temp += splitted[i] + "\n";
        }

        return temp;
        //m_str::replaceSubStr(luaCode,"{"," then");
        //m_str::replaceSubStr(luaCode,"}","end");
    }

    std::string lambdas( std::string Code ){
        //(a and "blah" or "nahblah")

        std::vector<std::string> splitted;
        splitted = m_str::split(Code, '\n');
        std::string temp = "";

        std::vector<std::string> splittedFunction;

        std::string tempFuncName = "";
        std::string tempFunction = "";
        std::string functions = "";
        int functionScrapping = 0;

        for (int i = 0; i < splitted.size(); i++)
        {
            if(
                m_str::includes( splitted[i], "=>" ) &&
                m_str::includes( splitted[i], "()" ) &&
                functionScrapping == 0
            ){
                tempFuncName = "__lambda__" + m_str::random(15);
                tempFunction = "";
                splitted[i] = m_str::replaceSubStr(splitted[i],"=>","");
                splitted[i] = m_str::replaceSubStr(splitted[i],"()", tempFuncName );
                functionScrapping = 1;
            }


            if( 
                functionScrapping == 1 &&
                m_str::includes( splitted[i], "{" )
            ){
                functionScrapping = 2;
            }

            if( 
                functionScrapping == 2
            ){
                tempFunction += splitted[i] + "\n";
                if( m_str::includes( splitted[i], "}" ) ){
                    splittedFunction = m_str::split(tempFunction, '{');
                    temp += splittedFunction[0];

                    splittedFunction = m_str::split(splittedFunction[1], '}');
                    temp += m_str::replaceSubStr(splittedFunction[1],"\n","");
                    functions += "function " + tempFuncName + "()\n" + splittedFunction[0] + "\nend\n";
                    functionScrapping = 0;
                }
                continue;
            }


            temp += splitted[i] + "\n";
        }

        return functions + temp;
        //m_str::replaceSubStr(luaCode,"{"," then");
        //m_str::replaceSubStr(luaCode,"}","end");
    }

    std::string classes( std::string Code ){
        //(a and "blah" or "nahblah")

        std::vector<std::string> splitted;
        splitted = m_str::split(Code, '\n');
        std::string temp = "";
        std::string class_name = "";

        bool class_scrapper = false;
        bool func_scrapper = false;

        int ends = 0;


        for (int i = 0; i < splitted.size(); i++)
        {

            if( m_str::includes( splitted[i], "class " ) && !m_str::includes( splitted[i], "\"" ) && !m_str::includes( splitted[i], "\'" ) ){
                class_name = m_str::replaceSubStr(splitted[i],"class ","");
                temp += "__" + class_name + " = {";
                ends = 1;
                class_scrapper = true;
                func_scrapper = false;
            }

            if( class_scrapper ){
                if( m_str::includes( splitted[i], "end" ) && !m_str::includes( splitted[i], "," ) )
                    ends--;

                if( m_str::includes( splitted[i], "public " ) )
                    temp += m_str::replaceSubStr(splitted[i],"public ","") + ",";

                if( m_str::includes( splitted[i], "function " ) ){
                    if( !func_scrapper ){
                        func_scrapper = true;
                        temp.pop_back();
                        temp += "}\n";
                    }   
                    
                    temp += m_str::replaceSubStr(splitted[i],"function ","function __" + class_name + ":") + "\n";
                    ends++;
                    continue;
                }

                if( 
                    m_str::includes( splitted[i], "if " ) &&
                    !m_str::includes( splitted[i], "elseif " ) ||
                    m_str::includes( splitted[i], " do" )
                )
                    ends++;

                if( ends < 1 ){
                    class_scrapper = false;
                    func_scrapper = false;
                    std::string tempClassName = "__obj__" + m_str::random(25);

                    temp += "\nfunction __" + class_name + ":__create()\nlocal classSoul = mnt.FlexibleClass()\nclassSoul:setName('"+class_name+"')\nclassSoul:setRef(classSoul)\nfor key,value in pairs(self) do\nclassSoul[key] = value\nend\nreturn classSoul\nend\n";
                    temp += "\nfunction " + class_name + "(...)\n"+tempClassName+" = __"+class_name+":__create()\n"+tempClassName+" = "+tempClassName+":init("+tempClassName+",...)\nreturn "+tempClassName+"\nend\n";

                    continue;
                }

                if( func_scrapper ){
                    temp += splitted[i] + "\n";
                }

                continue;
            }else{
                temp += splitted[i] + "\n";
            }
        }

        return temp;
    }
}