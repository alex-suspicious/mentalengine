
namespace mental{
    class windowClass
    {
    public:
        amath::Vector2 resolution;
        amath::Vector2 cameraSize;
        amath::Vector2 size;
        std::vector< std::function<void()> > hooks;
        std::vector< std::function<void()> > physics;

        std::vector<screen::Shader*> screenSpaceShaders;
        std::unordered_map<std::string, std::vector<luabridge::LuaRef>> allHooks;

        mental::color skyColor;

        Camera2D camera = { 0 };

        float aspectRatio = 0;
        float time = 0.0f;
        bool saveSize = true;
        bool active = true;
        bool sky = false;
        bool computer = false;
        bool lmb_pressed = false;
        bool rmb_pressed = false;
        bool mmb_pressed = false;
        bool mobile_joystick = false;
        bool show_rect = true;
        bool fullscreen = true;
        bool window_close = false;

        float zoom = 1;
        amath::Vector2 camPos;
        amath::Vector2 camPosLerp;

        RenderTexture2D target;

        void init(){
            InitWindow(this->resolution.x, this->resolution.y, "MentalEngine");
            ToggleFullscreen();

            this->skyColor = mental::color(15,15,15,255);
            //this->camera.zoom = 1.0f;
            //this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
            this->camera.target = (Vector2){ 0.0f, 0.0f };      // Camera looking at point
            //this->camera.up = (Vector3){ 0.0f, -1.0f, 0.0f };          // Camera up vector (rotation towards target)
            //this->camera.fovy = 90.0f;                                // Camera field-of-view Y
            //this->camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
            this->camera.zoom = 1;

            this->resolution.x = GetScreenWidth();
            this->resolution.y = GetScreenHeight();

            

            this->target = LoadRenderTexture(this->resolution.x, this->resolution.y);

            //sf::VideoMode screen(sf::VideoMode::getDesktopMode());
            //sf::ContextSettings settings;
            //settings.antialiasingLevel = 2.0;

            //#if !defined(ANDROID_VERSION)
            //    ImGui::SFML::Init(this->buffer);
            //#endif
            
//            if( global::windowed )
//                this->buffer.create(sf::VideoMode(global::windowed_width, global::windowed_height), "mental engine");
//            else
//                this->buffer.create(screen, "mental engine",sf::Style::Fullscreen);
//
//
//            auto screenSize = this->buffer.getSize();
//            this->resolution.x = screenSize.x;
//            this->resolution.y = screenSize.y;
//            this->skyColor = sf::Color::Black;
//
//            this->aspectRatio = ((float)this->resolution.x)/((float)this->resolution.y);
//            this->size.x = 1080*this->aspectRatio;
//            this->size.y = 1080;
//
            //
//
//            this->screenBuffer.create(screenSize.x,screenSize.y,true);
//            this->shaderBuffer.create(screenSize.x,screenSize.y,false);
//
//            this->depthBuffer.create(screenSize.x,screenSize.y,false);
 //
//            this->screenSurface.setTexture( this->screenBuffer.getTexture() );
//            this->shaderSurface.setTexture( this->shaderBuffer.getTexture() );
//
//            this->depthSurface.setTexture( this->depthBuffer.getTexture() );
//
//
//            this->consoleText = sf::Text("", *mental::loadFont("sansation.ttf"), 25);
//            this->consoleText.setFillColor( sf::Color(255,255,255,255) );
//
//
//            this->view = buffer.getDefaultView();
//            this->defaultView = buffer.getDefaultView();
//            this->screenSpaceView = buffer.getDefaultView();
//            this->bufferView = buffer.getDefaultView();
//
//            this->bufferView.setSize(this->resolution.x, this->resolution.y);
//            this->view.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
//            this->defaultView.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
//            this->view.setCenter(this->camPos.x + (this->size.x*this->zoom)/2,this->camPos.y + (this->size.y*this->zoom)/2);
//
//            this->screenSpaceView.setSize(this->size.x, this->size.y);
//            this->screenSpaceView.setCenter(this->camPos.x + (this->size.x)/2,this->camPos.y + (this->size.y)/2);
//            amath::screenSize = this->view.getSize();
//
//            this->cameraSize = sf::Vector2i(this->size.x*this->zoom, this->size.y*this->zoom);
//
//            this->buffer.setActive();
//            this->buffer.setView(this->bufferView);
//            this->shaderBuffer.setView(this->bufferView);
//            this->screenBuffer.setView(this->view);
//            this->depthBuffer.setView(this->view);
//
//            guiInit::localGui = new tgui::Gui(this->buffer);
        }

        void toggleFullscreen(){
//            if( this->fullscreen ){
//                this->fullscreen = false;
//                this->buffer.create(sf::VideoMode(1280, 720), "mental engine");
//            }else{
//                sf::VideoMode screen(sf::VideoMode::getDesktopMode());
//                this->fullscreen = true;
//                this->buffer.create(screen, "mental engine",sf::Style::Fullscreen);
//            }
//
//            auto screenSize = this->buffer.getSize();
//
//            this->resolution = sf::Vector2i(screenSize.x, screenSize.y);
//            this->aspectRatio = ((float)this->resolution.x)/((float)this->resolution.y);
//            this->size.x = 1080*this->aspectRatio;
//            this->size.y = 1080;
//
//
//            this->view.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
//            this->defaultView.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
//            this->view.setCenter(this->camPos.x + (this->size.x*this->zoom)/2,this->camPos.y + (this->size.y*this->zoom)/2);
//            this->defaultView.setCenter((this->size.x*this->zoom)/2,(this->size.y*this->zoom)/2);
//            this->screenBuffer.setView(this->view);
//            this->depthBuffer.setView(this->view);
//
//            this->screenSpaceView.setSize(this->size.x, this->size.y);
//            this->screenSpaceView.setCenter(this->camPos.x,this->camPos.y);
//
//            this->cameraSize = sf::Vector2i(this->size.x*this->zoom, this->size.y*this->zoom);
//            this->buffer.setActive();
        }

        void setCamPos( float x, float y ){
            this->camPos.x = x;
            this->camPos.y = y;
        }

        void setCamZoom( float factor ){
            //this->view.zoom(factor);
            //this->zoom = factor;
            //this->camera.fovy = 90.0f * (1.0f-factor);
            this->camera.zoom = (1.0f-factor);

            //this->view.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
            //this->defaultView.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
            //this->view.setCenter(this->camPos.x + (this->size.x*this->zoom)/2,this->camPos.y + (this->size.y*this->zoom)/2);
            //this->defaultView.setCenter((this->size.x*this->zoom)/2,(this->size.y*this->zoom)/2);
            //this->cameraSize = sf::Vector2i(this->size.x*this->zoom, this->size.y*this->zoom);
        }

        void updateCamera(){
            this->camPosLerp = this->camPosLerp.lerp( this->camPos ,0.009f);
        }

        void hook( std::function<void()> func ){
            hooks.push_back( func );
        }

        void addHookLua( std::string hook, luabridge::LuaRef func ){
            this->allHooks[hook].push_back( func );
        }

        void triggerHookLua( std::string hook, luabridge::LuaRef parameters){
            for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
            {
                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                if( !temp )
                    continue;

                if( temp->removing ){
                    temp->clear();
                    temp = nullptr;
                    
                    luaInit::luaFlexibleObjects[i] = nullptr;
                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                    continue;
                }

                if (temp->hooks.count(hook)){
                    for (int e = 0; e < temp->hooks[hook].size(); e++)
                    {
                        auto hookFunc = luaClasses::allHooks.find(temp->hooks[hook][e]);
                        if (hookFunc == luaClasses::allHooks.end())
                            continue;


                        if( temp ){
                            hookFunc->second(temp, parameters);
                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                        }
                    }
                }
            }

            if (this->allHooks.find(hook) != this->allHooks.end()){
                for (int e = 0; e < this->allHooks[hook].size(); e++)
                {
                    this->allHooks[hook][e]( parameters );
                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                }
            }
        }

        void physics_hook( std::function<void()> func ){
            hooks.push_back( func );
        }

        amath::Vector2 getSize(){
            //return this->view.getSize();
        }

        bool checkEvents(){
            //PollInputEvents();

            if (IsKeyPressed(KEY_ESCAPE))
            {
            
                for (int e = 0; e < this->allHooks["exit"].size(); e++)
                {
                    thread::run_lua([&, this](){
                        this->allHooks["exit"][e]();
                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                    });
                }
            }
            bool trigger = false;

            Input::pointer::update();

            for (int k = GetKeyPressed(); k != 0; k = GetKeyPressed()) {
                trigger = Input::keyboard::KeyDownRegister( (KeyboardKey)k );
                if( trigger ){
                    auto keyName = Input::keyboard::getKeyName(k);

                    thread::run_lua([&, keyName, this](){
                        for (int e = this->allHooks["key_press"].size(); e--> 0;)
                        {
                            this->allHooks["key_press"][e]( keyName );
                        }
                    }, true);

                    thread::run_lua([&, keyName, this](){
                        for (int i = luaInit::luaFlexibleObjects.size(); i--> 0;)
                        {
                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                            if( !temp )
                                continue;

                            if( temp->removing ){
                                temp->clear();
                                temp = nullptr;

                                luaInit::luaFlexibleObjects[i] = nullptr;
                                luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                                continue;
                            }

                            for (int e = temp->hooks["key_press"].size(); e--> 0;)
                            {
                                auto it = luaClasses::allHooks.find(temp->hooks["key_press"][e]);
                                if (it == luaClasses::allHooks.end())
                                    continue;
                              //
                                if( temp ){
                                    it->second(temp, keyName);
                                }
                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            }

                        }
                    }, true);
                }
            }

            for (int i = 0; i < Input::keyboard::downKeys.size(); i++)
            {
                if( !IsKeyDown( Input::keyboard::downKeys[i] ) ){
                    trigger = Input::keyboard::KeyReleaseRegister( Input::keyboard::downKeys[i] );
                    if( trigger ){
                        auto keyName = Input::keyboard::getKeyName( Input::keyboard::downKeys[i] );

                        thread::run_lua([&, keyName, this](){
                            for (int e = this->allHooks["key_release"].size(); e--> 0;)
                            {
                                this->allHooks["key_release"][e]( keyName );
                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            }
                        },true);

                        thread::run_lua([&, keyName, this](){
                            for (int i = luaInit::luaFlexibleObjects.size(); i--> 0;)
                            {
                                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                                if( !temp )
                                    continue;

                                if( temp->removing ){
                                    temp->clear();
                                    temp = nullptr;
                                  //
                                    luaInit::luaFlexibleObjects[i] = nullptr;
                                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                                    continue;
                                }

                                for (int e = 0; e < temp->hooks["key_release"].size(); e++)
                                {
                                    auto it = luaClasses::allHooks.find(temp->hooks["key_release"][e]);
                                    if (it == luaClasses::allHooks.end())
                                        continue;

                                    if( temp ){
                                        it->second(temp, keyName );
                                    }
                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                }

                            }
                        },true);
                    }
                }
            }

            return;

//            sf::Event event;
            //
//            while (1)
//            {
//                bool trigger = false;
//
////                #if !defined(ANDROID_VERSION)
////                    ImGui::SFML::ProcessEvent(this->buffer, event);
////                    if( ImGui::IsWindowFocused("Mental Console") )
////                        continue;
////                #endif
//
//                switch (event.type)
//                {
//                    case sf::Event::Closed:
//                        for (int e = 0; e < this->allHooks["exit"].size(); e++)
//                        {
//                            thread::run_lua([&, this](){
//                                this->allHooks["exit"][e]();
//                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                            });
//                        }
//                        //this->buffer.close();
//                        break;
//                    case sf::Event::MouseWheelScrolled: {
//                        auto delta = event.mouseWheelScroll.delta;
//                        thread::run_lua([&, delta, this](){
//                            for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
//                            {
//                                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                                if( !temp )
//                                    continue;
//
//                                if( temp->removing ){
//                                    temp->clear();
//                                    temp = nullptr;
                                    //
//                                    luaInit::luaFlexibleObjects[i] = nullptr;
//                                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
//                                    continue;
//                                }
//
//                                for (int e = 0; e < temp->hooks["mouse_scroll"].size(); e++)
//                                {
//                                    auto drag = luaClasses::allHooks.find(temp->hooks["mouse_scroll"][e]);
//                                    if (drag == luaClasses::allHooks.end())
//                                        continue;
//
//
//                                    if( temp ){
//                                        drag->second(temp, delta);
//                                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                    }
//                                }
                                         //
//                            }
//                        });
//                        for (int e = 0; e < this->allHooks["mouse_scroll"].size(); e++)
//                        {
//                            thread::run_lua([&, delta, this](){
//                                this->allHooks["mouse_scroll"][e]( delta );
//                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                            });
//                        } 
//                        break;
//                    }
//                    case sf::Event::MouseButtonPressed:
//                        trigger = Input::pointer::KeyDownRegister( event.mouseButton.button );
//                        if( trigger ){
//                            auto keyName = Input::pointer::getKeyName( event.mouseButton.button );
//
//                            thread::run_lua([&, keyName, this](){
//                                for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
//                                {
//                                    luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                                    if( !temp )
//                                        continue;
//
//                                    if( temp->removing ){
//                                        temp->clear();
//                                        temp = nullptr;
                                        //
//                                        luaInit::luaFlexibleObjects[i] = nullptr;
//                                        luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
//                                        continue;
//                                    }
//
//                                    for (int e = 0; e < temp->hooks["mouse_press"].size(); e++)
//                                    {
//                                        auto drag = luaClasses::allHooks.find(temp->hooks["mouse_press"][e]);
//                                        if (drag == luaClasses::allHooks.end())
//                                            continue;
//
//
//                                        if( temp ){
//                                            drag->second(temp, keyName);
//                                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                        }
//                                    }
                                             //
//                                }
//                            });
//
//                            for (int e = 0; e < this->allHooks["mouse_press"].size(); e++)
//                            {
//                                thread::run_lua([&, keyName, this](){
//                                    this->allHooks["mouse_press"][e]( keyName );
//                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                });
//                            }
//                        }
//                        break;
//                    case sf::Event::MouseButtonReleased:
//                        trigger = Input::pointer::KeyReleaseRegister( event.mouseButton.button );
//                        if( trigger ){
//                            auto keyName = Input::pointer::getKeyName( event.mouseButton.button );
//
//                            thread::run_lua([&, keyName, this](){
//                                for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
//                                {
//                                    luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                                    if( !temp )
//                                        continue;
//
//                                    if( temp->removing ){
//                                        temp->clear();
//                                        temp = nullptr;
                                        //
//                                        luaInit::luaFlexibleObjects[i] = nullptr;
//                                        luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
//                                        continue;
//                                    }
//
//                                    for (int e = 0; e < temp->hooks["mouse_release"].size(); e++)
//                                    {
//                                        auto drag = luaClasses::allHooks.find(temp->hooks["mouse_release"][e]);
//                                        if (drag == luaClasses::allHooks.end())
//                                            continue;
//
//                                        if( temp ){
//                                            drag->second(temp, keyName);
//                                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                        }
//                                    }
                                             //
//                                }
//                            });
//
//                            for (int e = 0; e < this->allHooks["mouse_release"].size(); e++)
//                            {
//                                thread::run_lua([&, keyName, this](){
//                                    this->allHooks["mouse_release"][e]( keyName );
//                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                });
//                            }
//                        }
//                        break;
//                    case sf::Event::KeyPressed:
////                        if (event.key.code == sf::Keyboard::Escape){
////                            for (int e = 0; e < this->allHooks["exit"].size(); e++)
////                            {
////                                thread::run_lua([&, this](){
////                                    this->allHooks["exit"][e]();
////                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
////                                });
////                            }
////                            this->buffer.close();
////                        }
//
//                        trigger = Input::keyboard::KeyDownRegister( event.key.code );
//                        if( trigger ){
//                            auto keyName = Input::keyboard::getKeyName(event.key.code);
//
//                            thread::run_lua([&, keyName, this](){
//                                for (int e = this->allHooks["key_press"].size(); e--> 0;)
//                                {
//                                    this->allHooks["key_press"][e]( keyName );
//                                }
//                            }, true);
//
//                            thread::run_lua([&, keyName, this](){
//                                for (int i = luaInit::luaFlexibleObjects.size(); i--> 0;)
//                                {
//                                    luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                                    if( !temp )
//                                        continue;
//
//                                    if( temp->removing ){
//                                        temp->clear();
//                                        temp = nullptr;
                                        //
//                                        luaInit::luaFlexibleObjects[i] = nullptr;
//                                        luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
//                                        continue;
//                                    }
//
//                                    for (int e = temp->hooks["key_press"].size(); e--> 0;)
//                                    {
//                                        auto it = luaClasses::allHooks.find(temp->hooks["key_press"][e]);
//                                        if (it == luaClasses::allHooks.end())
//                                            continue;
                                        //
//                                        if( temp ){
//                                            it->second(temp, keyName);
//                                        }
//                                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                    }
//
//                                }
//                            }, true);
//                        }
                        //
//                        break;
//                    case sf::Event::KeyReleased:
//                        trigger = Input::keyboard::KeyReleaseRegister( event.key.code );
//                        if( trigger ){
//                            auto keyName = Input::keyboard::getKeyName(event.key.code);
//
//                            thread::run_lua([&, keyName, this](){
//                                for (int e = this->allHooks["key_release"].size(); e--> 0;)
//                                {
//                                    this->allHooks["key_release"][e]( keyName );
//                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                }
//                            },true);
//
//                            thread::run_lua([&, keyName, this](){
//                                for (int i = luaInit::luaFlexibleObjects.size(); i--> 0;)
//                                {
//                                    luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                                    if( !temp )
//                                        continue;
//
//                                    if( temp->removing ){
//                                        temp->clear();
//                                        temp = nullptr;
                                        //
//                                        luaInit::luaFlexibleObjects[i] = nullptr;
//                                        luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
//                                        continue;
//                                    }
//
//                                    for (int e = 0; e < temp->hooks["key_release"].size(); e++)
//                                    {
//                                        auto it = luaClasses::allHooks.find(temp->hooks["key_release"][e]);
//                                        if (it == luaClasses::allHooks.end())
//                                            continue;
//
//                                        if( temp ){
//                                            it->second(temp, keyName );
//                                        }
//                                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                                    }
//
//                                }
//                            },true);
//                        }
                    //
//                        break;
//                    case sf::Event::Resized:
////                        this->resolution = sf::Vector2i(event.size.width, event.size.height);
////                        this->aspectRatio = ((float)this->resolution.x)/((float)this->resolution.y);
////                        this->size.x = 1080*this->aspectRatio;
////                        this->size.y = 1080;
////
////
////                        this->view.setSize(this->size.x*this->zoom, this->size.y*this->zoom);
////                        this->defaultView.setSize((this->size.x*this->zoom), (this->size.y*this->zoom));
////                        this->view.setCenter(this->camPos.x + this->size.x/2,this->camPos.y + this->size.y/2);
////                        this->defaultView.setCenter((this->size.x*this->zoom)/2,(this->size.y*this->zoom)/2);
////                        this->screenBuffer.setView(this->view);
////                        this->depthBuffer.setView(this->view);
////
////                        this->screenSpaceView.setSize(this->size.x, this->size.y);
////                        this->screenSpaceView.setCenter(this->camPos.x, this->camPos.y);
//
//                        for (int e = 0; e < this->allHooks["window_resize"].size(); e++)
//                        {
//                            thread::run_lua([&, this](){
//                                this->allHooks["window_resize"][e]( this->size.x*this->zoom, this->size.y*this->zoom );
//                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                            });
//                        }
//                        break;
//                    case sf::Event::MouseLeft:
//                        this->active = false;
//                        for (int e = 0; e < this->allHooks["window_unfocus"].size(); e++)
//                        {
//                            thread::run_lua([&, this](){
//                                this->allHooks["window_unfocus"][e]( event.size.width, event.size.height );
//                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                            });
//                        }
//                        break;
//                    case sf::Event::MouseEntered:
//                        this->active = true;
//                        for (int e = 0; e < this->allHooks["window_focus"].size(); e++)
//                        {
//                            thread::run_lua([&, this](){
//                                this->allHooks["window_focus"][e]();
//                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
//                            });
//                        }
//                        break;
//                }
//


                //thread::run_lua([&, this](){
                //    guiInit::localGui->handleEvent(event);
                //});

//            }

            return this->active;
        }
 
        void processThink(){
//            float itS = 1.0f / 60.0f;
//            float currentTime = GetTime();
//            float endTime = currentTime + itS;
//
//            while(!WindowShouldClose()){
                //
//
//
//            }

        }

        void physicsThink(){
//            sf::Clock clockCollisions;
//            sf::Time timePerFrameCollisions = sf::seconds(1.f / 60.f);
//            sf::Time passed;
//
//            sf::Vector2f localMousePosition;
//            sf::Vector2f localMousePositionOffset;
//            sf::Clock clock;
//            sf::Time timePerFrame = sf::seconds(1.f / 60.f);

            float passed = 0;
            float itS = 1.0f / 60.0f;
            float currentTime = GetTime();
            float lastUpdate = GetTime();
            float endTime = currentTime + itS;

            float itS_collisions = 1.0f / 60.0f;
            float endTime_collisions = currentTime + itS_collisions;

            while (!this->window_close){
                mental::camPos = this->camPos;
                //if( this->mobile_joystick )
                //    Input::mobile::process(&this->buffer);
                //Input::pointer::update(&this->buffer);

                for (int i = 0; i < this->hooks.size(); i++)
                {
                    thread::run_lua([&, this](){
                        this->hooks[i]();
                    });
                }

                thread::run_lua([&, this](){
                    for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                    {
                        luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                        if( !temp )
                            continue;

                        if( temp->removing ){
                            temp->clear();
                            temp = nullptr;
                            
                            luaInit::luaFlexibleObjects[i] = nullptr;
                            luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                            continue;
                        }

                        for (int e = 0; e < temp->hooks["think"].size(); e++)
                        {
                            auto it = luaClasses::allHooks.find(temp->hooks["think"][e]);
                            if (it == luaClasses::allHooks.end())
                                continue;

                            if( temp ){
                                it->second(temp);
                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            }
                        }

                    }
                });

                for (int e = 0; e < this->allHooks["think"].size(); e++)
                {
                    thread::run_lua([&, this](){
                        this->allHooks["think"][e]();
                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                    });
                }


                if ( !Input::pointer::isPressed() ){
                    if( this->lmb_pressed ){
                        this->lmb_pressed = !this->lmb_pressed;

                        thread::run_lua([&, this](){
                            for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                            {
                                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                                if( !temp )
                                    continue;

                                if( temp->removing ){
                                    temp->clear();
                                    temp = nullptr;
                                    
                                    luaInit::luaFlexibleObjects[i] = nullptr;
                                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                                    continue;
                                }

                                for (int e = 0; e < temp->hooks["mouse_release"].size(); e++)
                                {
                                    auto drag = luaClasses::allHooks.find(temp->hooks["mouse_release"][e]);
                                    if (drag == luaClasses::allHooks.end())
                                        continue;

                                    if( temp ){
                                        drag->second(temp);
                                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                    }
                                }
                                         
                            }
                        });

                        for (int e = 0; e < this->allHooks["mouse_release"].size(); e++)
                        {
                            thread::run_lua([&, this](){
                                this->allHooks["mouse_release"][e]();
                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            });
                        }
                    }
                }else{
                    //localMousePosition = Input::pointer::getPosition2f();
                    if( !this->lmb_pressed ){
                        //localMousePositionOffset = Input::pointer::getPosition2f();
                        this->lmb_pressed = !this->lmb_pressed;

                        thread::run_lua([&, this](){
                            for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                            {
                                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                                if( !temp )
                                    continue;

                                if( temp->removing ){
                                    temp->clear();
                                    temp = nullptr;
                                    
                                    luaInit::luaFlexibleObjects[i] = nullptr;
                                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                                    continue;
                                }

                                for (int e = 0; e < temp->hooks["mouse_press"].size(); e++)
                                {
                                    auto drag = luaClasses::allHooks.find(temp->hooks["mouse_press"][e]);
                                    if (drag == luaClasses::allHooks.end())
                                        continue;


                                    if( temp ){
                                        drag->second(temp);
                                        //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                    }
                                }
                                         
                            }
                        });

                        for (int e = 0; e < this->allHooks["mouse_press"].size(); e++)
                        {
                            thread::run_lua([&, this](){
                                this->allHooks["mouse_press"][e]();
                                //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            });
                        }
                    }

                    thread::run_lua([&, this](){
                        for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                        {
                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                            if( !temp )
                                continue;

                            if( temp->removing ){
                                temp->clear();
                                temp = nullptr;
                                
                                luaInit::luaFlexibleObjects[i] = nullptr;
                                luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                                continue;
                            }

                            for (int e = 0; e < temp->hooks["drag"].size(); e++)
                            {
                                auto drag = luaClasses::allHooks.find(temp->hooks["drag"][e]);
                                if (drag == luaClasses::allHooks.end())
                                    continue;

                                if( temp ){
                                    //drag->second(temp, amath::Vector2(localMousePosition), amath::Vector2(localMousePosition-localMousePositionOffset));
                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                }
                            }
                                     
                        }
                    });

                    for (int e = 0; e < this->allHooks["drag"].size(); e++)
                    {
                        thread::run_lua([&, this](){
                            //this->allHooks["drag"][e](amath::Vector2(localMousePosition), amath::Vector2(localMousePosition-localMousePositionOffset));
                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                        });
                    }
                }


                currentTime = GetTime();
                if ( (endTime_collisions - currentTime) <= 0 )
                {
                    passed = (endTime_collisions - currentTime);
                    endTime_collisions = currentTime + itS_collisions;

                    thread::run_lua([&, this](){
                        for (int i = 0; i < luaInit::luaFlexibleObjectsRemoving.size(); i++)
                        {
                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjectsRemoving[i];

                            for (int e = 0; e < luaInit::luaFlexibleObjects.size(); e++)
                            {
                                if( luaInit::luaFlexibleObjectsRemoving[i] == luaInit::luaFlexibleObjects[e] ){
                                    temp->clear();
                                    temp = nullptr;
                                    
                                    luaInit::luaFlexibleObjects[e] = nullptr;
                                    luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + e);
                                    break;
                                }
                            }

                            luaInit::luaFlexibleObjectsRemoving[i] = nullptr;
                            luaInit::luaFlexibleObjectsRemoving.erase(luaInit::luaFlexibleObjectsRemoving.begin() + i);
                            //delete temp;
                            
                        }

                        for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                        {
                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                            if( !temp->removing )
                                continue;

                            temp->clear();
                            temp = nullptr;

                            luaInit::luaFlexibleObjects[i] = nullptr;
                            luaInit::luaFlexibleObjects.erase(luaInit::luaFlexibleObjects.begin() + i);
                            //delete temp;
                        }

                        lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                    });

                    thread::run_lua([&, this](){
                        for (int i = physics::bodies.size(); i--> 0;)
                        {
                            if( !physics::bodies[i] )
                                continue;


                            if( physics::bodies[i]->GetUserData().pointer == (uintptr_t)body::removing ){
                                physics::world->DestroyBody(physics::bodies[i]);
                                physics::bodies[i] = nullptr;

                                physics::bodies.erase(physics::bodies.begin() + i);
                            }
                        }
                    });

                    thread::run_lua([&, this](){
                        for (int i = 0; i < mental::brushBuffer.size(); i++)
                        {
                            mental::brush* temp = ((mental::brush*)mental::brushBuffer[i]);
                            if( temp->removed ){
                                temp = nullptr;
                                mental::brushBuffer.erase(mental::brushBuffer.begin() + i);
                                lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            }
                        }
                    });

                    thread::run_lua([&, this](){
                        for (int i = 0; i < mental::renderablesBuffer.size(); i++)
                        {
                            renderable::sprite* temp = (renderable::sprite*)mental::renderablesBuffer[i];
                            //temp->update();
                            if( temp->removed ){
                                temp = nullptr;
                                mental::renderablesBuffer.erase(mental::renderablesBuffer.begin() + i);
                                lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                            }
                            //this->depthBuffer.draw( *mental::renderablesBuffer[i]  );
                        }
                    });

                    thread::run_lua([&, this](){
                        physics::world->Step( physics::timeStep * physics::speed , physics::velocityIterations, physics::positionIterations);
                    });

                    thread::run_lua([&, this](){
                        for (int e = this->allHooks["physics"].size(); e --> 0;)
                        {
                            this->allHooks["physics"][e]();
                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                        }
                    });

                    thread::run_lua([&, this](){
                        for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                        {
                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                            if( !temp )
                                continue;
                            if( temp->removing )
                                continue;

                            for (int e = temp->hooks["physics"].size(); e --> 0;)
                            {
                                auto physics = luaClasses::allHooks.find(temp->hooks["physics"][e]);
                                if (physics == luaClasses::allHooks.end())
                                    continue;


                                //if( temp ){
                                physics->second(temp);
                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                //}
                            }
         
                        }
                    });
                }

                currentTime = GetTime();
                if ( (endTime - currentTime) <= 0 )
                {
                    endTime = currentTime + itS;
                    this->time += 0.01;
//                    for (int i = 0; i < this->physics.size(); i++)
//                    {
//                        this->physics[i]();
//                    }

                    thread::run_lua([&, this](){
                        for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                        {
                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
                            if( !temp )
                                continue;
                            if( temp->removing )
                                continue;

                            for (int e = temp->hooks["fixed_think"].size(); e --> 0;)
                            {
                                auto think = luaClasses::allHooks.find(temp->hooks["fixed_think"][e]);
                                if (think == luaClasses::allHooks.end())
                                    continue;

                            
                                //if( temp ){
                                think->second(temp);
                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                //}
                                
                            }

                        }
                    });
                    
                    for (int e = 0; e < this->allHooks["fixed_think"].size(); e++)
                    {
                        thread::run_lua([&, this](){
                            this->allHooks["fixed_think"][e]();
                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                        });
                    }

                    currentTime = GetTime();
                    amath::delta = (currentTime-lastUpdate)*100.0f;
                    if( amath::delta > 25 )
                        amath::delta = 1;

                    lastUpdate = GetTime();
                }

                luaInterval::fire();

                if( thread::callbacks.size() > 0 ){
                    thread::run_lua([&, this](){
                        for (int i = thread::callbacks.size(); i--> 0;)
                        {
                            thread::callbacks.at(i)();
                        }
                        thread::callbacks.clear();
                    });
                }
                //luaFunctions::loadStringOlds();

                //usleep(1500);
//
//            if (clock.getElapsedTime() >= timePerFrame) {
//                clock.restart();
              //
//                for (int i = 0; i < this->physics.size(); i++)
//                {
//                    this->physics[i]();
//                }
//               amath::delta = amath::clock.restart().asSeconds()*100.0f;
//                if( amath::delta > 25 )
//                    amath::delta = 1;
//            }

                
                //luaFunctions::loadStringOlds();


                //usleep(1500);
            }

            
        }

        void luaQueueTasks(){
            
            while (!this->window_close){

            }
        }

        void soundsThink(){
            while (!this->window_close){
                thread::run_lua([&, this](){
                    mental::clearSoundBuffer();
                });

                //mental::processMusic();
                usleep(2000);
            }
        }

        void inputs(){
            //sf::Clock clock;
            //sf::Time timePerFrame = sf::seconds(1.f / 120.f);

            float itS = 1.0f / 120.0f;
            float currentTime = GetTime();
            float endTime = currentTime + itS;

            while (!this->window_close){
                currentTime = GetTime();
                if ( (endTime - currentTime) <= 0 )
                {
                    endTime = currentTime + itS;
                    Input::keyboard::process();
                    Input::axis::process();
                }
                
                usleep(2000);
            }
        }

        void process(){
            // --------
            //std::thread thread_drag(&windowClass::dragThink,this);
            // --------

            //std::thread thread_process(&windowClass::processThink,this);
            std::thread thread_physics(&windowClass::physicsThink,this);
            //std::thread thread_luaQueueTasks(&windowClass::luaQueueTasks,this);
            //std::thread thread_sounds(&windowClass::soundsThink,this);
            std::thread thread_inputs(&windowClass::inputs,this);
            float currentTime = GetTime();
            float itS_collisions = 1.0f / 30.0f;
            float endTime_draw = currentTime + itS_collisions;


            //return;

//            sf::ConvexShape debugPolygon;
//            debugPolygon.setFillColor(sf::Color(150, 0, 150,50));
//            debugPolygon.setOutlineThickness(2);
//            debugPolygon.setOutlineColor(sf::Color(255, 255, 255,200));
//
//            sf::CircleShape debugCirlce;
//            debugCirlce.setFillColor(sf::Color(150, 0, 150,50));
//            debugCirlce.setOutlineThickness(2);
//            debugCirlce.setOutlineColor(sf::Color(255, 255, 255,200));
//
//            sf::RectangleShape debugBox(sf::Vector2f(0, 0));
//            debugBox.setFillColor(sf::Color(150, 0, 150,50));
//            debugBox.setOutlineThickness(2);
//            debugBox.setOutlineColor(sf::Color(255, 255, 255,200));
//
//            sf::Vertex debugLineTrace[] =
//            {
//                sf::Vertex(sf::Vector2f(10, 10)),
//                sf::Vertex(sf::Vector2f(150, 150))
//            };

            //if( this->computer ){
            //    this->vfx[0]->setUniform("sky",this->sky);
            //}
            
            bool showMessageBox = false;

            //while (this->buffer.isOpen())
            while( !WindowShouldClose() )
            {
                this->window_close = false;
                this->checkEvents();
                this->updateCamera();
                this->resolution.x = GetScreenWidth();
                this->resolution.y = GetScreenHeight();

                currentTime = GetTime();
                if ( (endTime_draw - currentTime) <= 0 )
                {
                    //passed = (endTime_draw - currentTime);
                    endTime_draw = currentTime + itS_collisions;

                    std::sort(mental::renderablesBuffer.begin(), mental::renderablesBuffer.end(), renderable::sort_by_layer());
                }

                //this->camera.position = ( amath::Vector3(this->camPosLerp.x,this->camPosLerp.y,-600) ).raylib();
                this->camera.target = (Vector2){ (int)this->camPos.x,(int)this->camPos.y };

                this->cameraSize = this->resolution;

                //this->camera.position = ( amath::Vector3(this->camPosLerp.x + (this->camPosLerp.x-this->camPos.x),this->camPosLerp.y + (this->camPosLerp.y-this->camPos.y) -50,-600) ).raylib();
                //this->camera.target = ( amath::Vector3(this->camPos.x,this->camPos.y,100) ).raylib();


                this->camera.offset = (Vector2){ static_cast<float>(GetScreenWidth()/2), static_cast<float>(GetScreenHeight()/2) };

                //std::lock_guard<std::mutex> guard(render::renderMutex);
                textureThread::asyncLoadTextureBuffer();


                //{
                    BeginTextureMode( this->target );
                        ClearBackground(this->skyColor.raylib());
                        BeginMode2D(camera);
                        
                        rlDisableBackfaceCulling();
                        rlEnableDepthTest();

                        //float aspect = (float)GetScreenWidth() / (float)GetScreenHeight(); // Current aspect ratio
                        //Matrix customProjection = MatrixPerspective(this->camera.fovy * DEG2RAD, aspect, 0.1f, 5000.0f); // Set far plane to 5000.0f
                        //rlSetMatrixProjection(customProjection);
                        

                
                //                this->buffer.clear( this->skyColor );
                //                this->screenBuffer.clear( this->skyColor );
                //                this->depthBuffer.clear( sf::Color::White );
                //                this->shaderBuffer.clear( sf::Color::Black );
                //
                //                this->view.setCenter( this->camPosLerp.x,this->camPosLerp.y);
                //                sf::Listener::setPosition(this->camPosLerp.x*0.004f, this->camPosLerp.y*0.004f, 1.0f);
                //
                //                luaInit::campos = this->camPosLerp;
                //
                //                this->screenBuffer.setView(this->view);
                //                this->depthBuffer.setView(this->view);
                
                //
                //                #if !defined(ANDROID_VERSION)
                //                thread::run_lua([&, this](){
                //                    for (int e = this->allHooks["prerender"].size(); e > 0; e--)
                //                    {
                //                        this->allHooks["prerender"][e]();
                //                    }
                //                });
                //
                //                thread::run_lua([&, this](){
                //                    for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                //                    {
                //                        luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
                //
                //                        if( !temp )
                //                            continue;
                //                        if( temp->removing )
                //                            continue;
                //
                //                        for (int e = temp->hooks["prerender"].size(); e --> 0;)
                //                        {
                //                            auto prerender = luaClasses::allHooks.find(temp->hooks["prerender"][e]);
                //                            if (prerender == luaClasses::allHooks.end())
                //                                continue;
                //
                //                            prerender->second(temp);
                //                        }
                     //
                //                    }
                //                });
                //                #endif
                //
                        for (int i = 0; i < mental::renderablesBuffer.size(); i++)
                        {
                            renderable::base* temp = (renderable::base*)mental::renderablesBuffer[i];
                            if( !temp->screen && !temp->removed ){
                                temp->update();
                                if( temp->newBorn )
                                    continue;

                                switch( temp->type ){
                                    case 1:{
                                        renderable::sprite* tempObj = (renderable::sprite*)mental::renderablesBuffer[i];
                                        tempObj->draw(this->time,i);
                                        break;
                                    } 
                                    case 2:{
                                        renderable::brush* tempObj = (renderable::brush*)mental::renderablesBuffer[i];
                                        tempObj->draw(this->time,i);
                                        break;
                                    }
                                    case 3:{
                                        gui::text* tempObj = (gui::text*)mental::renderablesBuffer[i];
                                        tempObj->draw(this->time,i);
                                        break;
                                    }
//                                    case 4:{
//                                        renderable::tiles* tempObj = (renderable::tiles*)mental::renderablesBuffer[i];
//                                        tempObj->draw(this->time,i);
//                                        break;
//                                    }
                                }
                                //temp->drawing( &this->screenBuffer, this->time, this->view, this->screenSpaceView, &this->shaderTexturePrev); 
        //                        #if !defined(ANDROID_VERSION)
        //                        if( temp->depthpass )
        //                            temp->drawing( &this->depthBuffer, this->time, this->view, this->screenSpaceView, nullptr, this->depthShader ); 
        //                        #endif
                            }
                        }
                        

//                        for (int i = 0; i < mental::modelsBuffer.size(); i++)
//                        {
//                            renderable::model* temp = (renderable::model*)mental::modelsBuffer[i];
//                            temp->draw(this->time);
//                        }
                        
        
                        if( global::debug ){
                            for (int i = 0; i < physics::bodies.size(); i++)
                            {
                                //physics::bodies[0];
                                auto tempVec = physics::bodies[i]->GetPosition();
        
                                for (b2Fixture* fixture = physics::bodies[i]->GetFixtureList(); fixture; fixture = fixture->GetNext()) 
                                {
                                    b2Shape::Type shapeType = fixture->GetType();
                                    if ( shapeType == b2Shape::e_chain )
                                    {
                                        b2ChainShape* chainShape = (b2ChainShape*)fixture->GetShape();
        
                                        rlPushMatrix();
                                            rlTranslatef(tempVec.x*physics::worldSize,tempVec.y*physics::worldSize, 0);
                                            rlRotatef( physics::bodies[i]->GetAngle()*amath::r2d, 0.0, 0.0, 1.0);
                                            for (int g = 0; g < chainShape->m_count-1; g++){
                                                //debugPolygon.setPoint(g, sf::Vector2f(polygonShape->m_vertices[g].x*physics::worldSize,polygonShape->m_vertices[g].y*physics::worldSize));
        
                                                DrawLineEx(amath::Vector2(chainShape->m_vertices[g].x*physics::worldSize,chainShape->m_vertices[g].y*physics::worldSize).raylib(), amath::Vector2(chainShape->m_vertices[g+1].x*physics::worldSize,chainShape->m_vertices[g+1].y*physics::worldSize).raylib(), 5, BLUE);
                                            }
                                        rlPopMatrix();
                                    }
                                    if ( shapeType == b2Shape::e_circle )
                                    {
                                        //sf::FloatRect bounds = debugCirlce.getLocalBounds();
                                        b2CircleShape* circleShape = (b2CircleShape*)fixture->GetShape();
        
        //                                debugCirlce.setRadius(circleShape->m_radius*physics::worldSize);
        //
        //                                debugCirlce.setPosition( sf::Vector2f(tempVec.x*physics::worldSize,tempVec.y*physics::worldSize) );
        //                                debugCirlce.setRotation( physics::bodies[i]->GetAngle()*amath::r2d );
        //                                debugCirlce.setOrigin( sf::Vector2f(bounds.width,bounds.height)/2.0f );
        //
        //                                this->screenBuffer.draw(debugCirlce);
                                    }
                                    else if ( shapeType == b2Shape::e_polygon )
                                    {
                                        b2PolygonShape* polygonShape = (b2PolygonShape*)fixture->GetShape();
        
                                        //DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);    
        
        //                                debugPolygon.setPointCount(polygonShape->m_count);
        //
                                        rlPushMatrix();
                                            rlTranslatef(tempVec.x*physics::worldSize,tempVec.y*physics::worldSize, 0);
                                            rlRotatef( physics::bodies[i]->GetAngle()*amath::r2d, 0.0, 0.0, 1.0);
                                            for (int g = 0; g < polygonShape->m_count; g++){
                                                //debugPolygon.setPoint(g, sf::Vector2f(polygonShape->m_vertices[g].x*physics::worldSize,polygonShape->m_vertices[g].y*physics::worldSize));
        
                                                if( g == polygonShape->m_count-1 )
                                                    DrawLineEx(amath::Vector2(polygonShape->m_vertices[g].x*physics::worldSize,polygonShape->m_vertices[g].y*physics::worldSize).raylib(), amath::Vector2(polygonShape->m_vertices[0].x*physics::worldSize,polygonShape->m_vertices[0].y*physics::worldSize).raylib(), 2, GREEN);
                                                else
                                                    DrawLineEx(amath::Vector2(polygonShape->m_vertices[g].x*physics::worldSize,polygonShape->m_vertices[g].y*physics::worldSize).raylib(), amath::Vector2(polygonShape->m_vertices[g+1].x*physics::worldSize,polygonShape->m_vertices[g+1].y*physics::worldSize).raylib(), 2, GREEN);
                                            }
                                        rlPopMatrix();
        //
        //                                debugPolygon.setPosition( sf::Vector2f(tempVec.x*physics::worldSize,tempVec.y*physics::worldSize) );
        //                                debugPolygon.setRotation( physics::bodies[i]->GetAngle()*amath::r2d );
        
        //                                this->screenBuffer.draw(debugPolygon);
                                    }
                                }
        
                            }
        
                            rlPushMatrix();
                                //rlTranslatef(0,0, -3.0f);
                                for (int i = 0; i < body::traces.size(); i++)
                                {
                                    //debugBox.setPosition( body::traces[i][0].sfml() );
                                    //debugBox.setSize( sf::Vector2f( body::traces[i][0].distance(body::traces[i][1]) ,4) );
                                    //debugBox.setRotation( (body::traces[i][1]-body::traces[i][0]).angle() );
                                    
                                    DrawLineEx(body::traces[i][0].raylib(), body::traces[i][1].raylib(), 5, RED);
                                    //this->screenBuffer.draw( debugBox );
                                    //body::traces[i].clear();
                                }
                            rlPopMatrix();
        
                            body::traces.clear();
        
                            DrawFPS(this->camPosLerp.x -this->resolution.x/3 + 10,this->camPosLerp.y -this->resolution.y/3 + 10);
                        }
        //
                        EndMode2D();
                    EndTextureMode();
        
                    BeginDrawing();
                        ClearBackground(RAYWHITE);  // Clear screen background
        
                        //BeginShaderMode(shaders[currentShader]);
                            // NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
                            DrawTextureRec(this->target.texture, (Rectangle){ 0, 0, (float)this->target.texture.width, (float)-this->target.texture.height }, (Vector2){ 0, 0 }, WHITE);
                        //EndShaderMode();

                            for (int e = this->allHooks["gui"].size(); e --> 0;)
                            {
                                thread::run_lua([&, this](){
                                    this->allHooks["gui"][e]();
                                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                                });
                            }
        
                        
                            for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                            {
                                luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
        
                                if( !temp )
                                    continue;
                                if( temp->removing )
                                    continue;
        
                                for (int e = temp->hooks["gui"].size(); e --> 0;)
                                {
                                    auto gui = luaClasses::allHooks.find(temp->hooks["gui"][e]);
                                    if (gui == luaClasses::allHooks.end())
                                        continue;
                                    
                                    thread::run_lua([&, this](){
                                        gui->second(temp);
                                    });
                                }
             
                            }
                    EndDrawing();

                    for (int e = this->allHooks["postrender"].size(); e --> 0;)
                    {
                        thread::run_lua([&, this](){
                            this->allHooks["postrender"][e]();
                            //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                        });
                    }

                    for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
                    {
                        luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];

                        if( !temp )
                            continue;
                        if( temp->removing )
                            continue;

                        for (int e = temp->hooks["postrender"].size(); e --> 0;)
                        {
                            auto postrender = luaClasses::allHooks.find(temp->hooks["postrender"][e]);
                            if (postrender == luaClasses::allHooks.end())
                                continue;

                            thread::run_lua([&, this](){
                                postrender->second(temp);
                            });
                        }
                    }
                //}
//      
//                for (int i = 0; i < guiInit::texts.size(); i++)
//                {
//                    auto temp = (gui::text*)guiInit::texts[i];
//                    if( !temp->screen && !temp->removing && !temp->newBorn ){
//                        this->screenBuffer.draw( *temp->native );
//                    }
//                }
//
//
//
//                std::vector<sf::Vector2f> light_positions;
//                std::vector<sf::Vector3f> light_colors;
//                for (int i = 0; i < mental::lightsBuffer.size(); i++)
//                {
//                    mental::light* temp = (mental::light*)mental::lightsBuffer[i];
//                    light_positions.push_back(temp->position);
//                    light_colors.push_back(sf::Vector3f(temp->color.r/255.0,temp->color.g/255.0,temp->color.b/255.0));              
//                }
//
//
//
                

//                }
//
//
//                this->screenBuffer.setView(this->defaultView);
//                this->depthBuffer.setView(this->defaultView);
//
//                for (int i = 0; i < guiInit::texts.size(); i++)
//                {
//                    auto temp = (gui::text*)guiInit::texts[i];
//                    if( temp->screen && !temp->removing ){
//                        this->screenBuffer.draw( *temp->native );
//                    }
//                }
//
//
//                this->depthBuffer.display();
//                this->screenBuffer.display();
//
//                if( this->screenSpaceShaders.size() ){
//                    this->shaderSurface.setScale(1.0,1.0);
//                    this->shaderSurface.setPosition(0,0);
//                    for (int i = 0; i < this->screenSpaceShaders.size(); i++){
//                        if( !this->screenSpaceShaders[i]->enabled )
//                            continue;
//
//
//                        this->screenSpaceShaders[i]->native->setUniform("time", this->time);
//
//                        this->screenSpaceShaders[i]->native->setUniform("buffer", this->shaderTexture );
//
//                        this->screenSpaceShaders[i]->native->setUniform("bufferPrev", this->shaderTexturePrev );
//                        this->screenSpaceShaders[i]->native->setUniform("screenPrev", this->oldScreen );
//                        this->screenSpaceShaders[i]->native->setUniform("screen", this->screenBuffer.getTexture() );
//                        this->screenSpaceShaders[i]->native->setUniform("depth", this->depthBuffer.getTexture() );
        
//
//                        this->shaderBuffer.clear();
//
//                        this->shaderBuffer.draw( this->shaderSurface, this->screenSpaceShaders[i]->native );
//
//                        this->shaderBuffer.display();
//                        this->shaderTexture = this->shaderBuffer.getTexture();
//
//                    }
//
//                    this->shaderTexturePrev = this->shaderBuffer.getTexture();
//                    this->shaderBuffer.display();
//
//                    this->shaderSurface.setTexture(this->shaderTexture);
//                    this->buffer.setActive(true);
//
//                    this->shaderSurface.setScale(1.0,-1.0);
//                    this->shaderSurface.setPosition(0,this->shaderSurface.getGlobalBounds().height);
//
//                    this->buffer.draw( this->shaderSurface );
//                }else
//                    this->buffer.draw( this->screenSurface );
//
//
//                #if !defined(ANDROID_VERSION)
//                    ImGui::SFML::Update(this->buffer, this->deltaClockImgui.restart());
//
//                    if( global::debug )
//                        console::draw( this->buffer, &this->deltaClockImgui );
//
//                    thread::run_lua([&, this](){
//                        for (int e = 0; e < this->allHooks["debugrender"].size(); e++)
//                        {
//                            this->allHooks["debugrender"][e]();
//                        }
//                    });
//
//                    thread::run_lua([&, this](){
//                        for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
//                        {
//                            luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                            if( !temp )
//                                continue;
//                            if( temp->removing )
//                                continue;
//
//                            for (int e = temp->hooks["debugrender"].size(); e --> 0;)
//                            {
//                                auto debugrender = luaClasses::allHooks.find(temp->hooks["debugrender"][e]);
//                                if (debugrender == luaClasses::allHooks.end())
//                                    continue;
//
//                                debugrender->second(temp);
//                            }
         //
//                        }
//                    });
//
//                    ImGui::SFML::Render(this->buffer);
//                #endif
//
//
//                if( this->mobile_joystick ){
//                    this->buffer.draw( *Input::mobile::stick_soul[1] );
//                    this->buffer.draw( *Input::mobile::stick_soul[0] );
//                }
//
//                this->buffer.setView(this->bufferView);
//                this->shaderBuffer.setView(this->bufferView);
//                this->screenBuffer.setView(this->view);
//
//                #if !defined(ANDROID_VERSION)
//                thread::run_lua([&, this](){
//                    for (int e = this->allHooks["postrender"].size(); e > 0; e--)
//                    {
//                        this->allHooks["postrender"][e]();
//                    }
//                });
//
//                thread::run_lua([&, this](){
//                    for (int i = 0; i < luaInit::luaFlexibleObjects.size(); i++)
//                    {
//                        luaClasses::FlexibleClass* temp = (luaClasses::FlexibleClass*)luaInit::luaFlexibleObjects[i];
//
//                        if( !temp )
//                            continue;
//                        if( temp->removing )
//                            continue;
//
//                        for (int e = temp->hooks["postrender"].size(); e --> 0;)
//                        {
//                            auto postrender = luaClasses::allHooks.find(temp->hooks["postrender"][e]);
//                            if (postrender == luaClasses::allHooks.end())
//                                continue;
//
//                            postrender->second(temp);
//                        }
     //
//                    }
//                });
//                #endif
//
//                    guiInit::localGui->draw();
//                    this->buffer.display();
//
//
//                for (int i = 0; i < guiInit::texts.size(); i++)
//                {
//                    auto temp = (gui::text*)guiInit::texts[i];
//                    if( temp->removing ){
//                        temp = nullptr;
//                        guiInit::texts.erase(guiInit::texts.begin() + i);
//                    }
//                }

            }
            this->window_close = true;


            // ----------
            //thread_drag.join();
            // ----------

            //thread_process.join();
            thread_physics.join();
            //thread_luaQueueTasks.join();
            //thread_sounds.join();
            thread_inputs.join();

            //#if !defined(ANDROID_VERSION)
            //    ImGui::SFML::Shutdown();
            //#endif

            CloseWindow();

            return;
        }
    };

    windowClass *window;

    namespace window_lua{
        void addHookLua( std::string hook, luabridge::LuaRef func ){
            window->addHookLua(hook, func);
        }

        void triggerHookLua( std::string hook, luabridge::LuaRef parameters ){
            window->triggerHookLua(hook, parameters);
        }

        void setCamPos( amath::Vector2 pos ){
            window->setCamPos(pos.x,pos.y);
        }

        void setCamPosXY( float x, float y ){
            window->setCamPos(x,y);
        }

        void setCamZoom( float factor ){
            window->setCamZoom( factor );
        }

        amath::Vector2 getCamPos(){
            return amath::Vector2(window->camPos);
        }

        void setEnabled( bool value ){
            global::debug = value;
        }

        amath::Vector2 getPositionWorldLua(){
            return amath::Vector2( GetScreenToWorld2D( Input::pointer::positionRaw, window->camera ) );
        }

        void loadShader( std::string name ){
            //window->screenSpaceShaders.insert({ name, new screen::Shader(name) });
            //window->screenSpaceShaders.push_back( new screen::Shader(name) );
            //window->depthShader = mental::loadShader("depth");
        }

        void setShaderFloatArray( std::string name, std::string variable, std::vector<float> arr ){
            const float* dataPtr = arr.data();
            //for (int i = 0; i < window->screenSpaceShaders.size(); i++)
            //{
                //if( window->screenSpaceShaders[i]->name == name ){
                    //window->screenSpaceShaders[i]->native->setUniformArray(variable, dataPtr,arr.size());
                //    return;
                //}
            //}
        }

        void setShaderInt( std::string name, std::string variable, int parameter){
            //for (int i = 0; i < window->screenSpaceShaders.size(); i++)
            //{
                //if( window->screenSpaceShaders[i]->name == name ){
                //    window->screenSpaceShaders[i]->native->setUniform(variable, parameter);
                //    return;
                //}
            //}
        }

        void setShaderFloat( std::string name, std::string variable, float parameter){
            //for (int i = 0; i < window->screenSpaceShaders.size(); i++)
            //{
                //if( window->screenSpaceShaders[i]->name == name ){
                //    window->screenSpaceShaders[i]->native->setUniform(variable, parameter);
                //    return;
                //}
            //}
        }

        void setShaderColor( std::string name, std::string variable, mental::color parameter){
//            for (int i = 0; i < window->screenSpaceShaders.size(); i++)
//            {
//                if( window->screenSpaceShaders[i]->name == name ){
//                    window->screenSpaceShaders[i]->native->setUniform(variable, sf::Glsl::Vec4(parameter.r,parameter.g,parameter.b,parameter.a));
//                    return;
//                }
//            }
        }

        void setShaderEnabled( std::string name, bool status ){
            //auto it = window->screenSpaceShaders.find(name);
            //if (it == window->screenSpaceShaders.end())
            //    return;

            //it->second->enabled = status;
//            for (int i = 0; i < window->screenSpaceShaders.size(); i++)
//            {
//                if( window->screenSpaceShaders[i]->name == name ){
//                    window->screenSpaceShaders[i]->enabled = status;
//                    return;
//                }
//            }
        }

        bool isEnabled(){
            return global::debug;
        }

        void toggleFullscreen(){
            window->toggleFullscreen();
        }


        void skyColor( mental::color newColor ){
            window->skyColor = newColor;
        }

    }
}