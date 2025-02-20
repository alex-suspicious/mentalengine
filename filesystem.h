namespace fs{
	std::map<std::string, std::string> files;
	std::string key = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

	std::string encrypt(std::string msg, std::string const& key)
	{
	    if(!key.size())
	        return msg;
	    
	    for (std::string::size_type i = 0; i < msg.size(); ++i)
	        msg[i] ^= key[i%key.size()];
	    return msg;
	}
	
	std::string decrypt(std::string const& msg, std::string const& key)
	{
	    return encrypt(msg, key);
	}

	std::string read( std::string path ){
		//std::cout << "search " << path << "\n";
		auto it = files.find(path);
		if (it != files.end())
			return it->second;

		//std::cout << "FAIL" "\n";
        std::string data;
        //sf::FileInputStream stream;

        int size = 0;
        char *fileData = (char*)LoadFileData(path.c_str(), &size);

        if( fileData == NULL )
        	return "";

        data = std::string(fileData,size);
        UnloadFileText(fileData);

		return data;
	} 

	void init(){
		std::string name = "assets/logic";
        std::string fsCode;
        std::string fsCodeDec;
        std::vector<std::string> splitted;
        //sf::FileInputStream stream;

        int size = 0;
        char *fileData = (char*)LoadFileData(name.c_str(), &size);

        if( std::filesystem::is_directory(name) )
        	return;

        if( fileData == NULL )
        	return;


        //if (!stream.open(name))
        //    return;

        //sf::Int64 fileSize = stream.getSize();
        //if( fileSize == -1 )
        //	return;

        //fsCode.resize(fileSize);
        //stream.read(&fsCode[0], fileSize);

        fsCode = std::string(fileData,size);
        UnloadFileText(fileData);

        fsCodeDec = decrypt(fsCode, key);

        //std::cerr << fsCodeDec;
        //return;
        splitted = m_str::split(fsCodeDec,'\n');

        std::string tempFile = "";
        std::string tempFilepath = "";
        std::string tempLine = "";
        for (int i = 0; i < splitted.size()+1; i++){
            tempLine = splitted[i];
            
            if( m_str::includes(tempLine, "flebin ") || i == splitted.size() ){
            	if( tempFilepath != "" ){
            		files.emplace (std::make_pair (tempFilepath, tempFile));
            		//std::cout << tempFilepath << "\n";
            	}
            	tempFile = "";
            	tempFilepath = m_str::replaceSubStr(tempLine,"flebin ","");
            }else{
            	tempFile += tempLine + "\n";
            }
        }

        tempLine = "";
        tempFile = "";
        fsCode = "";
        fsCodeDec = "";
        tempFilepath = "";
        splitted.clear();
	}
}