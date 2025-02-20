namespace file{
    #if defined(ANDROID_VERSION)
        std::string internal = "/data/data/mht.mentalengine.android/files/";
    #else
        std::string internal = "";
    #endif
        
	std::string read( std::string path ){
		//sf::FileInputStream stream;
		std::string text = "";
		std::string clear = m_str::replaceSubStr(path,".lua","");

		#if !defined(ANDROID_VERSION)
        for (int i = 0; i < addons::dirs.size(); i++)
        {
//            if( !stream.open( addons::dirs[i] + "/" + path) )
//                continue;
//
//			sf::Int64 fileSize = stream.getSize();
//
//			text.resize(fileSize);
//			stream.read(&text[0], fileSize);
//			return text;

	        std::string data;

	        int size = 0;
	        char *fileData = (char*)LoadFileData( (addons::dirs[i] + "/" + path).c_str(), &size);

	        if( fileData == NULL )
	        	continue;

	        data = std::string(fileData,size);
	        UnloadFileText(fileData);
	        return data;
        }
        #endif

//		if (!stream.open("assets/" + clear) && !stream.open("assets/" + clear + ".lua")) {
		text = fs::read("assets/" + clear);
		if( text != "" )
			return text;

		return "";
//		}else{
//			sf::Int64 fileSize = stream.getSize();
//
//			text.resize(fileSize);
//			stream.read(&text[0], fileSize);
//			return text;
//		}
	}

	std::string readRaw( std::string path ){
//		sf::FileInputStream stream;
//		std::string text = "";
//
//		if (!stream.open(path)) {
//			return "";
//		}else{
//			sf::Int64 fileSize = stream.getSize();
//
//			text.resize(fileSize);
//			stream.read(&text[0], fileSize);
//			return text;
//		}

        std::string data;

        int size = 0;
        char *fileData = (char*)LoadFileData( path.c_str(), &size);

        if( fileData == NULL )
        	return "";

        data = std::string(fileData,size);
        UnloadFileText(fileData);
        return data;
	}

    void write( std::string path, std::string content){
        std::ofstream save_file;
        save_file.open(internal + path);
        save_file << content;
        save_file.close();
    }

	std::vector<std::string> ls( std::string path ){
		std::vector<std::string> temp;
		if( !std::filesystem::is_directory(path) )
			return temp;

        for(auto& p : std::filesystem::directory_iterator(path))
			temp.push_back( m_str::replaceSubStr(p.path().string(),"\\","/") );

		return temp;
	}
}