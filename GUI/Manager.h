namespace gui{
    void clear(){
        //guiInit::localGui->removeAllWidgets();
    }

    void load( std::string path ){
//        std::string testXml = file::read("gui/" + path);
//        pugi::xml_document doc;
//        pugi::xml_parse_result result = doc.load_string(testXml.c_str());
//
//
//        //std::cerr << "+Loading the GUI " << path << "\n";
//        if (!result){
//            std::cerr << "!Can't load the GUI, parsing error!\n";
//            return;
//        }
//        //std::cerr << "+GUI was parsed!\n";
//
//        //lua_State* tempL = luaL_newstate();
//        //luaL_openlibs(tempL);
//        //luabridge::getGlobalNamespace(tempL);
//
//        for (pugi::xml_node buttonElement: doc.child("gui").children("button"))
//        {
//            auto button = tgui::Button::create();
//            //button->setRenderer(theme.getRenderer("Button"));
//            button->setText(buttonElement.child_value());
//
//            if( buttonElement.attribute("pos") ){
//                std::vector<std::string> posCoords = m_str::split(buttonElement.attribute("pos").value(),',');
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + posCoords[0]).c_str());
//                float floatX = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + posCoords[1]).c_str());
//                float floatY = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                button->setPosition(floatX,floatY);
//            }
//
//            if( buttonElement.attribute("size") ){
//                std::vector<std::string> sizeCoords = m_str::split(buttonElement.attribute("size").value(),',');
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + sizeCoords[0]).c_str());
//                float floatX = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + sizeCoords[1]).c_str());
//                float floatY = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//
//                button->setSize(floatX,floatY);
//            }
//
//            if( buttonElement.attribute("background-color") ){
//                std::vector<std::string> newColor = m_str::split(buttonElement.attribute("background-color").value(),',');
//                button->getRenderer()->setBackgroundColor( sf::Color(std::stof(newColor[0]),std::stof(newColor[1]),std::stof(newColor[2]),std::stof(newColor[3])) );
//            }
//
//            if( buttonElement.attribute("border-color") ){
//                std::vector<std::string> newColor = m_str::split(buttonElement.attribute("border-color").value(),',');
//                button->getRenderer()->setBorderColor( sf::Color(std::stof(newColor[0]),std::stof(newColor[1]),std::stof(newColor[2]),std::stof(newColor[3])) );
//            }
//
//            if( buttonElement.attribute("text-color") ){
//                std::vector<std::string> newColor = m_str::split(buttonElement.attribute("text-color").value(),',');
//                button->getRenderer()->setTextColor( sf::Color(std::stof(newColor[0]),std::stof(newColor[1]),std::stof(newColor[2]),std::stof(newColor[3])) );
//            }
//
//            if( buttonElement.attribute("text-size") ){
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + std::string(buttonElement.attribute("text-size").value()) ).c_str());
//                float floatSize = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                button->setTextSize(floatSize);
//            }
//
//            if( buttonElement.attribute("onclick") ){
//                std::string tempString = buttonElement.attribute("onclick").value();
//
//                button->onPress([&]( std::string lua_code ){
//                    luaL_dostring(luaInit::luaState, lua_code.c_str() );
//                },tempString);
//            }
//
//            guiInit::localGui->add(button);
//        }
//
//        for (pugi::xml_node labelElement: doc.child("gui").children("label"))
//        {
//            auto label = tgui::Label::create();
//            //button->setRenderer(theme.getRenderer("Button"));
//            label->setText(labelElement.child_value());
//
//            if( labelElement.attribute("pos") ){
//                std::vector<std::string> posCoords = m_str::split(labelElement.attribute("pos").value(),',');
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + posCoords[0]).c_str());
//                float floatX = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + posCoords[1]).c_str());
//                float floatY = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                label->setPosition(floatX,floatY);
//            }
//
//            if( labelElement.attribute("size") ){
//                std::vector<std::string> sizeCoords = m_str::split(labelElement.attribute("size").value(),',');
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + sizeCoords[0]).c_str());
//                float floatX = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + sizeCoords[1]).c_str());
//                float floatY = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//
//                label->setSize(floatX,floatY);
//            }
//
//            if( labelElement.attribute("background-color") ){
//                std::vector<std::string> newColor = m_str::split(labelElement.attribute("background-color").value(),',');
//                label->getRenderer()->setBackgroundColor( sf::Color(std::stof(newColor[0]),std::stof(newColor[1]),std::stof(newColor[2]),std::stof(newColor[3])) );
//            }
//
//            if( labelElement.attribute("border-color") ){
//                std::vector<std::string> newColor = m_str::split(labelElement.attribute("border-color").value(),',');
//                label->getRenderer()->setBorderColor( sf::Color(std::stof(newColor[0]),std::stof(newColor[1]),std::stof(newColor[2]),std::stof(newColor[3])) );
//            }
//
//            if( labelElement.attribute("text-color") ){
//                std::vector<std::string> newColor = m_str::split(labelElement.attribute("text-color").value(),',');
//                label->getRenderer()->setTextColor( sf::Color(std::stof(newColor[0]),std::stof(newColor[1]),std::stof(newColor[2]),std::stof(newColor[3])) );
//            }
//
//            if( labelElement.attribute("text-size") ){
//
//                luaL_dostring(luaInit::luaState, ( "guiresolve = " + std::string(labelElement.attribute("text-size").value()) ).c_str());
//                float floatSize = luabridge::getGlobal(luaInit::luaState, "guiresolve");
//
//                label->setTextSize(floatSize);
//            }
//
//            guiInit::localGui->add(label);
//        }
//

        //lua_close(tempL);
            //std::cout << "Brush: " <<  << "\n";
        
    }
}