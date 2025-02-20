namespace mental{
    //std::vector<sf::Sound*> soundsVector;
    //std::map<std::string,sf::SoundBuffer*> soundsBuffer;
    void* wrongSound = nullptr;
    //sf::Sound* Music;

//    sf::SoundBuffer* loadSound( std::string name ){
//        name = "/sounds/" + name;
//        bool loaded = true;
//
//        if (mental::soundsBuffer.find( "assets" + name) != mental::soundsBuffer.end())
//            return mental::soundsBuffer[ "assets" + name ];
//
//        mental::soundsBuffer.insert({ "assets" + name, new sf::SoundBuffer });
//        if( !mental::soundsBuffer[ "assets" + name ]->loadFromFile( "assets" + name ) ){
//            loaded = false;
//
//            for (int i = 0; i < addons::dirs.size(); i++)
//            {
//                if( mental::soundsBuffer[ "assets" + name ]->loadFromFile( addons::dirs[i] + name ) ){
//                    loaded = true;
//                    break;
//                }
//            }
//        }
//
//        if( !loaded )
//            return (sf::SoundBuffer*)wrongSound;
        //
//        return mental::soundsBuffer[ "assets" + name ];
//    }

    void playSound( std::string name, float pitch = 1, float volume = 100, amath::Vector2 pos = amath::Vector2(0,0) ){
//        sf::SoundBuffer* sound = loadSound(name);
//        if( sound == wrongSound )
//            return;
//
//        mental::soundsVector.push_back( new sf::Sound );
//        mental::soundsVector[ mental::soundsVector.size()-1 ]->setBuffer( *sound );
//
//        mental::soundsVector[ mental::soundsVector.size()-1 ]->setPitch( pitch );
//
//        if( pos.x != 0 && pos.y != 0 ){
//            mental::soundsVector[ mental::soundsVector.size()-1 ]->setPosition(pos.x*0.004f, pos.y*0.004f, -5.f);
//            //mental::soundsVector[ mental::soundsVector.size()-1 ]->setRelativeToListener(true);
//            mental::soundsVector[ mental::soundsVector.size()-1 ]->setMinDistance(20.f);
//            mental::soundsVector[ mental::soundsVector.size()-1 ]->setAttenuation(25.f);
//        }else{
//            mental::soundsVector[ mental::soundsVector.size()-1 ]->setRelativeToListener(true);
//        }
//
//        mental::soundsVector[ mental::soundsVector.size()-1 ]->setVolume(volume);
//        mental::soundsVector[ mental::soundsVector.size()-1 ]->play();
    }


    void clearSoundBuffer(){
//        for (int i = 0; i < mental::soundsVector.size(); i++)
//        {
//            if( mental::soundsVector[i]->getStatus() == 0 ){
//                delete( mental::soundsVector[i] );
//                mental::soundsVector.erase( mental::soundsVector.begin() + i );
//            } 
//
//        }
    }

    namespace music{
        void init(){
            //mental::Music = new sf::Sound;
        }

        void load(std::string name ){
            //mental::Music->setBuffer( *mental::loadSound(name) );
        }

        void setVolume( float value ){
            //mental::Music->setVolume( value );
        }

        void play(){
            //mental::Music->play();
            //mental::Music->setLoop(true);
        }

        void pause(){
            //mental::Music->pause();
        }

        void stop(){
            //mental::Music->stop();
        }
    }
}