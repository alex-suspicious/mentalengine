namespace mental{
    //std::map<std::string,sf::Texture*> texturesBuffer;
    std::map<std::string,Texture2D> texturesBuffer;
    std::map<std::string,Image> imageToTextureBuffer;


    //sf::Texture* loadTexture( std::string name, bool repeat = true ){
    std::string loadTexture( std::string name, bool repeat = true ){
        name = "/textures/" + name;
        
        if (mental::texturesBuffer.find("assets" + name) != mental::texturesBuffer.end())
            return "assets" + name;

        if (mental::imageToTextureBuffer.find("assets" + name) != mental::imageToTextureBuffer.end())
            return "assets" + name;


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

        //std::lock_guard<std::mutex> guard(render::renderMutex);
        imageToTextureBuffer.insert({ "assets" + name, LoadImage( ("assets" + name).c_str() ) });

        return "assets" + name;
    }

    mental::bounds loadTextureBounds( std::string name, bool repeat = true ){
        name = "/textures/" + name;
        
        if (mental::texturesBuffer.find("assets" + name) != mental::texturesBuffer.end())
            return mental::bounds(0,0,mental::texturesBuffer["assets" + name].width,mental::texturesBuffer["assets" + name].height);

        if (mental::imageToTextureBuffer.find("assets" + name) != mental::imageToTextureBuffer.end())
            return mental::bounds(0,0,mental::imageToTextureBuffer["assets" + name].width,mental::imageToTextureBuffer["assets" + name].height);


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

        //std::lock_guard<std::mutex> guard(render::renderMutex);
        Image tempImage = LoadImage( ("assets" + name).c_str() );
        imageToTextureBuffer.insert({ "assets" + name, tempImage});

        return mental::bounds(0,0,tempImage.width,tempImage.height);
    }
    
}