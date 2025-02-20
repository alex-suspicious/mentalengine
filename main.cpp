
//#include <experimental/filesystem>
//#include <filesystem>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <random>
#include <cstdint>
#include <functional>
#include <memory>
#include <regex>
#include <map>
#include <unistd.h>
#include <thread>
#include <unordered_map>
#include <atomic>
#include <mutex>

#include <box2d/box2d.h>

//#include "raylib.h"
//#include "rlgl.h"
//#include "raymath.h"

//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
//#include <TGUI/TGUI.hpp>
//#include <TGUI/Backend/SFML-Graphics.hpp>

#if !defined(ANDROID_VERSION)
//    #include "imgui-SFML.h"
//    #include "imgui.h"
#endif

//#include "httplib.h"

extern "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}
#include <LuaBridge.h>
#include <Vector.h>
#include <vector>

#include "stringController.h"
#include "filesystem.h"
#include "variables.h"
#include "earcut.hpp"

#include "json.hpp"
#include "pugixml.hpp"
#include "Physics/init.h"
#include "Addons/init.h"
#include "Addons/Functions.h"
#include "files.h" 

#include "LUA/Init.h"
#include "jsonManager.h"
#include "savesManager.h"
#include "amath.h"
#include "vectors.h"
//#include "fontManager.h"
//#include "Render/rect.h"
#include "Render/essentials.h"
#include "Render/color.h"
#include "Render/bounds.h"
#include "Render/textureManager.h"
#include "Render/modelManager.h"
#include "Render/fontManager.h"

#include "Input/Functions.h" 
#include "Input/Gamepad.h"
#include "Input/Keyboard.h"
#include "Input/Mobile.h"

#include "Render/shaderManager.h"

#include "Render/renderable.h"
#include "Render/sprite.h"
#include "Render/brush.h"
#include "Render/model.h"
#include "Render/screenShader.h"

#include "Render/textureThreadLoading.h"

#include "soundManager.h"
#include "android.h"

#include "GUI/Init.h" 
#include "GUI/Classes.h"
#include "GUI/Manager.h"
#include "GUI/Functions.h"

#include "LUA/Interval.h" 
#include "LUA/Functions.h" 
#include "LUA/Classes.h"
#include "Physics/shapes.h"
#include "Physics/functions.h"

#include "entities.h"

#if !defined(ANDROID_VERSION)
//    #include "GUI/Console.h"
//    #include "GUI/Debug.h"
#endif

#include "Scene/tilesets.h"
#include "Render/tiles.h" 

#include "window.h"
#include "Networking/Init.h"
#include "Networking/Functions.h"

#include "Sensors/Init.h" 
#include "Sensors/Functions.h" 

#include "LUA/Manager.h" 

#include "loader.h"
#include "Scene/loader.h"
#include "intro.h"
#include "test.h"
#include "Errors/NullBuffer.h"
#include "Arguments/process.h" 

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL));
    
    //StringStreamBuffer errorBuffer;
    //std::ostream errorStream(&errorBuffer);
    //sf::err().rdbuf(errorStream.rdbuf());


    #if !defined(ANDROID_VERSION)
        addons::init();
    #endif

    //sensors::init();
    
    physics::init();
    body::init();
    networking::init();

    #if !defined(ANDROID_VERSION)
        arguments::process(argc - 1, argv + 1);
    #endif

    mental::music::init();
    
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    mental::windowClass newWindow;
    newWindow.init();

    mental::window = &newWindow;
    fs::init();

    //mental::window->depthShader = mental::loadShader("depth");
    //usleep(20);

    //if(!global::skip_logo){
    //    intro::show();
    //}

    //std::thread thread_loading(&loader::process);
    //intro::show();
    //thread_loading.join();
    
    
    mental::entities::init();
    Input::mobile::init();

    luaManager::updateInitFunctions();
    luaInit::luaState = luaFunctions::init();
    luaFunctions::initClasses(luaInit::luaState);
    mental::consoleBuffer = "";
    luaManager::importClasses();
    scene::lua();
    
    usleep(20);
    scenes::test();


    return 0;
}