namespace Input{
	namespace mobile{
		//std::vector<sf::Sprite*> stick_soul;
		bool active = true;
		bool stop = false;

		void init(){
//			stick_soul.push_back( new sf::Sprite );
//			stick_soul.push_back( new sf::Sprite );

//            stick_soul[0]->setTexture( *mental::loadTexture( "circle.png" ) );
//            stick_soul[0]->setOrigin( stick_soul[0]->getLocalBounds().width/2, stick_soul[0]->getLocalBounds().height/2 );
//            stick_soul[0]->setColor(sf::Color(255, 255, 255, 100));
//            stick_soul[0]->setScale(0.7,0.7);
//
//            stick_soul[1]->setTexture( *mental::loadTexture( "circle.png" ) );
//            stick_soul[1]->setOrigin( stick_soul[1]->getLocalBounds().width/2, stick_soul[1]->getLocalBounds().height/2 );
//            stick_soul[1]->setColor(sf::Color(255, 255, 255, 150));
//            stick_soul[1]->setScale(0.5,0.5);
		}

		void process(){
//			sf::Vector2u windowSize = window->getSize();
//
//			if( Input::pointer::isPressed() ){
//				if( !stop && !active ){
//					float dist = amath::Vector2(Input::pointer::getPosition2f()).distance( amath::Vector2( stick_soul[0]->getPosition() ) );
//					if( dist > 400 )
//						stop = true;
//				}
//
//				if( stop )
//					return;
//
//				if( !active ){
//					active = true;
//					stick_soul[0]->setPosition( Input::pointer::getPosition2f() );
//					stick_soul[1]->setPosition( Input::pointer::getPosition2f() );
//				}
//
//				amath::Vector2 dir = amath::Vector2( Input::pointer::getPosition2f() - stick_soul[0]->getPosition() ).normalize();
//				float dist = amath::Vector2(Input::pointer::getPosition2f()).distance( amath::Vector2( stick_soul[0]->getPosition() ) );
//				amath::Vector2 finalPos = dir * amath::clip(dist,0,150);
//				Input::axis::leftStick.x = amath::clip(finalPos.x/150,-1,1);
//				Input::axis::leftStick.y = amath::clip(finalPos.y/150,-1,1);
//
//				stick_soul[1]->setPosition( stick_soul[0]->getPosition() + sf::Vector2f(finalPos.x,finalPos.y) );
//			}else{
//				stop = false;
//
//				if( active ){
//					Input::axis::leftStick.x = 0;
//					Input::axis::leftStick.y = 0;
//
//					active = false;
//				}else{
//					stick_soul[0]->setPosition(stick_soul[0]->getLocalBounds().width/2 ,windowSize.y - stick_soul[0]->getLocalBounds().height/2 );
//					stick_soul[1]->setPosition(stick_soul[0]->getLocalBounds().width/2 ,windowSize.y - stick_soul[0]->getLocalBounds().height/2 );
//				}
//			}
		}
	}
}