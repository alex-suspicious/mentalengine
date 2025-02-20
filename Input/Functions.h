namespace Input{
    namespace pointer{
        //std::vector<sf::Mouse::Button> downKeys;
        amath::Vector2 position;
        ::Vector2 positionRaw;
        bool pressed = false;
        bool mobile = false;

        //bool KeyReleaseRegister( sf::Mouse::Button key ){
       //     mobile = false;
//            auto index = std::find(downKeys.begin(), downKeys.end(), key);
//            if( index != downKeys.end()) {
//                downKeys.erase(index);
//                return true;
//            }
        //    return false;
        //}

        //bool KeyDownRegister( sf::Mouse::Button key ){
        //    mobile = false;
//            auto index = std::find(downKeys.begin(), downKeys.end(), key);
//            if( index == downKeys.end()) {
//                downKeys.push_back( key );
//                return true;
//            }
       //    return false;
        //}

//        const char *getKeyName(const sf::Mouse::Button key) {
//            switch(key) {
//            case sf::Mouse::Button::Left:
//                return "Left";
//            case sf::Mouse::Button::Right:
//                return "Right";
//            case sf::Mouse::Button::Middle:
//                return "Middle";
//            case sf::Mouse::Button::XButton1:
//                return "XButton1";
//            case sf::Mouse::Button::XButton2:
//                return "XButton2";
//            }
//        }
        
        amath::Vector2 getPosition(){
            return position;
        }

        amath::Vector2 getPosition2f(){
            return position;
        }

        amath::Vector2 getPositionGlobalLua(){
            return position;
        }

        bool isPressed(){
            return pressed;
        }

        void update(){
            positionRaw = GetMousePosition();
            position = amath::Vector2( positionRaw );



            pressed = false;

            if( IsMouseButtonDown(MOUSE_BUTTON_LEFT) )
                pressed = true;
//
//            if (sf::Touch::isDown(0))
//            {
//                //positionRaw = sf::Touch::getPosition(0, *window);
//                //position = window->mapPixelToCoords( positionRaw );
//                pressed = true;
//                mobile = true;
//            }else if( !mobile ){
//                //positionRaw = sf::Mouse::getPosition(*window);
//                //position = window->mapPixelToCoords( positionRaw );
//                pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
//            }
//
//            if( mobile && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
//                mobile = false;
        }
    }
    
    
}