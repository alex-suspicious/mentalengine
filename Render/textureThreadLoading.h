namespace textureThread{

    void asyncLoadTextureBuffer(){
        if( !mental::imageToTextureBuffer.size() )
            return;

        std::lock_guard<std::mutex> guard(render::renderMutex);

        for (auto const& [key, val] : mental::imageToTextureBuffer)
        {
            Texture2D tempTexture = LoadTextureFromImage( val );

            if( tempTexture.id <= 0 ){
                std::cerr << "Failed to load texture: " << key << "\n";
                continue;
            }

            GenTextureMipmaps( &tempTexture );
            //usleep(5000);
            mental::texturesBuffer.insert({ key, tempTexture });
            UnloadImage(val);
        }
        mental::imageToTextureBuffer.clear();

        for (int i = 0; i < mental::renderablesBuffer.size(); i++)
        {
            renderable::base* temp = (renderable::base*)mental::renderablesBuffer[i];
            if( !temp->screen && !temp->removed ){

                switch( temp->type ){
                    case 2:{
                        renderable::brush* tempObj = (renderable::brush*)mental::renderablesBuffer[i];
                        if( mental::texturesBuffer.find(tempObj->texture) != mental::texturesBuffer.end() )
                            tempObj->textureLoaded = true;
                    }
                    case 1:{
                        renderable::sprite* tempObj = (renderable::sprite*)mental::renderablesBuffer[i];
                        if( mental::texturesBuffer.find(tempObj->texture) != mental::texturesBuffer.end() )
                            tempObj->textureLoaded = true;
                    } 
                }
            }
        }

    }

}