
namespace scenes{
    

    void music(){
        //mental::music.loadFromFile("mentalbass/test.mendi");

        //mental::playSound("mentalbass/Bossa Brazil.wav");

        mental::window->process();
    }

    void test(){
        //mental::music.loadFromFile("mentalbass/test.mendi");
        //mental::playSound("mentalbass/Bossa Brazil.wav");
        //
//        for (int i = 0; i < 100; i++)
//        {
//            mental::dynamic* sfml = new mental::dynamic("ball.png");
//            sfml->velocity.x = -30 + rand()%60;
//            sfml->velocity.y = -30 + rand()%60;
//            sfml->sprite->setPosition(i*15 + rand()%50,rand()%60);
//            sfml->sprite->setScale(0.15,0.15);
//            sfml->pixel_collision = false;
//            sfml->weight = 1.3f;
//            sfml->screenBorders = true;
//
//            sfml->addHook([](mental::dynamic* sfml){
//                sfml->sprite->setRotation( sfml->sprite->getPosition().x*2.5 );
//            });
//
//        }

        //mental::light* newLight1 = new mental::light( sf::Vector2f(0.3,0.5), sf::Color(255,0,0) );
//        mental::dynamic* sfml1 = new mental::dynamic("ball.png");
//        sfml1->sprite->setScale(0.15,0.15);
//        sfml1->weight = 1.3f;
//        sfml1->pixel_collision = false;
//        sfml1->screenBorders = true;
//        sfml1->addHook(player_phys);
        //sfml1->custom.push_back( newLight1 );
        //sfml1->addHook([](mental::dynamic* sfml){
            //mental::light* temp = (mental::light*)sfml->custom[0];
            //temp->position = sfml->sprite->getPosition() + sf::Vector2f(0,0);
        //});


//        mental::light* newLight2 = new mental::light( sf::Vector2f(0.3,0.5), sf::Color(0,255,0) );
//        mental::dynamic* sfml2 = new mental::dynamic("ball.png");
//        sfml2->sprite->setScale(0.0,0.0);
//        sfml2->weight = 1.3f;
//        sfml2->screenBorders = true;
//        sfml2->addHook(player_phys);
//        sfml2->custom.push_back( newLight2 );
//        sfml2->addHook([](mental::dynamic* sfml){
//            mental::light* temp = (mental::light*)sfml->custom[0];
//            temp->position = sfml->sprite->getPosition() + sf::Vector2f(0,0);
//        });
//
//
//
//        mental::light* newLight3 = new mental::light( sf::Vector2f(0.3,0.5), sf::Color(0,0,255) );
//        mental::dynamic* sfml3 = new mental::dynamic("ball.png");
//        sfml3->sprite->setScale(0.0,0.0);
//        sfml3->weight = 1.3f;
//        sfml3->screenBorders = true;
//        sfml3->addHook(player_phys);
//        sfml3->custom.push_back( newLight3 );
//        sfml3->addHook([](mental::dynamic* sfml){
//            mental::light* temp = (mental::light*)sfml->custom[0];
//            temp->position = sfml->sprite->getPosition() + sf::Vector2f(0,0);
//        });

        //mental::dynamic* walls = new mental::dynamic("logo.png");
        //walls->active = false;
        //walls->sprite->setPosition(1920/2,1080/2);
        //walls->pixel_collision = true;

        //mental::window->sky = true;

        if( global::load_map == "" )
            luaManager::loadFile("main.lua");
        else
            scene::load( global::load_map );
        
        for (int i = 0; i < addons::dirs.size(); i++)
        {
            std::filesystem::path filepath = std::string(addons::dirs[i] + "/logic/autorun/");
            bool filepathExists = std::filesystem::is_directory(filepath.parent_path());
            if( !filepathExists )
                continue;
            
            for(auto& p : std::filesystem::recursive_directory_iterator( addons::dirs[i] + "/logic/autorun" )){
                if (!p.is_directory()){
                    luaFunctions::loadString( file::readRaw( p.path().string() ) );
                    luaFunctions::print( p.path().string() + " was executed!" );
                }
            }
        }

        //luaManager::print( "Test\nTest\nTest\nTest\nTest\nTest\nTest\n" );
        mental::window->process();
    }

}