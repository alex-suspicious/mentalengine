namespace mental{
    //std::map<std::string,sf::Texture*> texturesBuffer;
    std::map<std::string,Font> fontBuffer;
    
    //sf::Texture* loadTexture( std::string name, bool repeat = true ){
    std::string loadFont( std::string name ){
        name = "/fonts/assets" + name;
        if (mental::fontBuffer.find(name) != mental::fontBuffer.end())
            return name;


        // Addons texture loading      
//        for (int i = 0; i < addons::dirs.size(); i++)
//        {
//            if( mental::texturesBuffer[ "assets" + name ]->loadFromFile( addons::dirs[i] + name ) ){
//                mental::texturesBuffer[ "assets" + name ]->setRepeated( repeat );
//                mental::texturesBuffer[ "assets" + name ]->generateMipmap();
                //
//                return mental::texturesBuffer[ "assets" + name ];
//            }
//        }

        auto temp = LoadFontEx( name.c_str(), 32, 0, 250 );
        mental::fontBuffer.insert({ name, temp });

        return name;
    }
    
}