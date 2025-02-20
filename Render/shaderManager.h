const std::string vertexShader = \
    "void main()" \
    "{" \
    "    ..." \
    "}";

const std::string fragmentShader = \
    "void main()" \
    "{" \
    "    ..." \
    "}";

namespace mental{
    std::map<std::string,Shader> shadersBuffer;

    //#if defined(GLES)
    //    std::string shaderFormat = ".gles";
    //#else
    //#endif

    std::string shaderFormat = ".gls";
    
    //
    std::string loadShader( std::string name ){
        name = "shaders/" + name + shaderFormat;
        if (mental::shadersBuffer.find(name) != mental::shadersBuffer.end())
            return name;

        std::string tempFragment = "";
        std::string tempVertex = "";
        std::string tempLine = "";
        int type = 0;

        std::string text = file::read(name);
        std::vector<std::string> splitted;

        if (name == "")
            return "";
        
        splitted = m_str::split(text,'\n');

        for (int i = 0; i < splitted.size(); i++){
            tempLine = splitted[i];
            
            if( tempLine == "begin vertex;" ){
                type = 1; continue; }
            else if( tempLine == "begin fragment;" ){
                type = 2; continue; }
 
            switch( type ){
                case 1:
                    tempVertex += tempLine + "\n";
                    break;
                case 2:
                    tempFragment += tempLine + "\n";
                    break;
                default:
                    break;
            }
        }


        //std::cout << name;
        //std::cout << "\nVERTEX\n" << tempVertex << '\n';
        //std::cout << "FRAGMENT\n" << tempFragment << '\n';


        if( tempVertex != "" && tempFragment != "" )
            mental::shadersBuffer.insert({ name, LoadShaderFromMemory(tempVertex.c_str(), tempFragment.c_str()) });
        else if( tempVertex == "" && tempFragment != "" )
            mental::shadersBuffer.insert({ name, LoadShaderFromMemory(0, tempFragment.c_str()) });
        else if( tempVertex != "" && tempFragment == "" )
            mental::shadersBuffer.insert({ name, LoadShaderFromMemory(tempVertex.c_str(), 0) });
            
        //mental::shadersBuffer[ name ]->loadFromMemory(tempVertex, tempFragment);

        return name;
    }

    Shader loadShaderRaw( std::string name ){
        name = "assets/shaders/" + name + shaderFormat;
        if (mental::shadersBuffer.find(name) != mental::shadersBuffer.end())
            return mental::shadersBuffer[ name ];

        std::string tempFragment = "";
        std::string tempVertex = "";
        std::string tempLine = "";
        int type = 0;

        std::string text = file::read(name);
        std::vector<std::string> splitted;

        if (name == "")
            return mental::shadersBuffer[0];
        
        splitted = m_str::split(text,'\n');

        for (int i = 0; i < splitted.size(); i++){
            tempLine = splitted[i];
            
            if( tempLine == "begin vertex;" ){
                type = 1; continue; }
            else if( tempLine == "begin fragment;" ){
                type = 2; continue; }
 
            switch( type ){
                case 1:
                    tempVertex += tempLine + "\n";
                    break;
                case 2:
                    tempFragment += tempLine + "\n";
                    break;
                default:
                    break;
            }
        }

        //mental::shadersBuffer[ name ]->loadFromMemory(tempVertex, tempFragment);

        if( tempVertex != "" && tempFragment != "" )
            return LoadShaderFromMemory(tempVertex.c_str(), tempFragment.c_str());
        else if( tempVertex == "" && tempFragment != "" )
            return LoadShaderFromMemory(0, tempFragment.c_str());
        else if( tempVertex != "" && tempFragment == "" )
            return LoadShaderFromMemory(tempVertex.c_str(), 0);

    }
    
}