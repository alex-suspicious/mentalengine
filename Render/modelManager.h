namespace mental{
    //std::map<std::string,sf::Texture*> texturesBuffer;
    std::map<std::string,Model> modelsVerteciesBuffer;
    
    //sf::Texture* loadTexture( std::string name, bool repeat = true ){
    Model loadModel( std::string name ){
        name = "/models/" + name;
        if (mental::modelsVerteciesBuffer.find("assets" + name) != mental::modelsVerteciesBuffer.end())
            return mental::modelsVerteciesBuffer[ "assets" + name ];


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

        Model tempModel = LoadModel( ("assets" + name).c_str() );

        //if( tempModel.id <= 0 )
        //    std::cerr << "Failed to load texture: " << "assets" << name << "\n";

        //GenTextureMipmaps( &tempModel );
        mental::modelsVerteciesBuffer.insert({ "assets" + name, tempModel });

        //mental::texturesBuffer[ "assets" + name ]->loadFromFile( "assets" + name );
        //mental::texturesBuffer[ "assets" + name ]->loadFromFile( "assets" + name );
        //mental::texturesBuffer[ "assets" + name ]->setRepeated( repeat );
        //mental::texturesBuffer[ "assets" + name ]->generateMipmap();
        
        return mental::modelsVerteciesBuffer[ "assets" + name ];
    }
    
}