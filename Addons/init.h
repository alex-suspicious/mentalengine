namespace addons{
    std::vector<std::string> dirs;
    
    
    #if defined(ANDROID_VERSION)
        std::string addons_dir = "addons";
        void init(){
            //std::cout << "FS TEST";
            std::filesystem::directory_entry addons_entry{addons_dir};
            //std::cout << addons_entry.exists();

            if( !addons_entry.exists() )
                return;

            //std::filesystem::create_directory(addons_dir);


            for(auto& p : std::filesystem::directory_iterator(addons_dir))
                if (p.is_directory())
                    dirs.push_back(p.path().string());
        }
    #else
        std::string addons_dir = "addons";
        void init(){
            std::filesystem::directory_entry addons_entry{addons_dir};
            if( !addons_entry.exists() )
                std::filesystem::create_directory(addons_dir);


            for(auto& p : std::filesystem::directory_iterator(addons_dir))
                if (p.is_directory())
                    dirs.push_back(p.path().string());
        }
    #endif

}