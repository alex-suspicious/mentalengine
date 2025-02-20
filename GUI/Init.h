namespace guiInit{
    std::vector<void*> texts;
    //std::vector<sf::Text*> texts_native;
    //tgui::Gui* localGui;
}

namespace thread{
    std::atomic<bool> thread_safe_gui (true);

    void run_gui( std::function<void()> callback ){
        if( thread_safe_gui ){
            thread_safe_gui = false;
            callback();
            thread_safe_gui = true;
        }
    }
}