namespace scene{

	class tileset{
	public:
		std::string source = "";
		std::string texture = "";
		int width;
		int height;

		int tileWidth;
		int tileHeight;

		int tileCount;
		int columns;
	};	

	std::map<std::string,tileset*> tilesets;

	std::string loadTileset( std::string path ){
		if( tilesets.find(path) != tilesets.end() )
			return path;

		auto splitted_slash = m_str::split(path,'/');
		std::string filePath = m_str::replaceSubStr(path,"../../textures/", "");

		std::string fileName = splitted_slash[splitted_slash.size()-1];
		std::string texturePath = m_str::replaceSubStr(filePath,"/" + fileName,"");

		std::cerr << "textures/" + filePath << "\n";

		std::string tilesetXml = file::read("textures/" + filePath);
			
	    pugi::xml_document doc;
	    pugi::xml_parse_result result = doc.load_string(tilesetXml.c_str());
	    luaFunctions::print( "+Loading the tileset " + path );
	    if (!result){
	    	luaFunctions::print( "!Can't load the tileset, parsing error!" );
	        return "";
	    }
	    luaFunctions::print( "+Tileset was parsed!" );

	    pugi::xml_node tileset_node = doc.child("tileset");
	    if( !tileset_node )
	    	return "";

	    pugi::xml_node image_node = tileset_node.child("image");
	    if( !image_node )
	    	return "";

	    tileset* temp_tileset = new tileset();

	    temp_tileset->width = std::stoi( image_node.attribute("width").value() );
	    temp_tileset->height = std::stoi( image_node.attribute("height").value() );

	    temp_tileset->tileWidth = std::stoi( tileset_node.attribute("tilewidth").value() );
	    temp_tileset->tileHeight = std::stoi( tileset_node.attribute("tileheight").value() );

	    temp_tileset->tileCount = std::stoi( tileset_node.attribute("tilecount").value() );
	    temp_tileset->columns = std::stoi( tileset_node.attribute("columns").value() );

	    temp_tileset->source = texturePath + "/" + image_node.attribute("source").value();
	    std::cerr << "TEXTURE: " << temp_tileset->source << "\n";
	    temp_tileset->texture = mental::loadTexture( temp_tileset->source );
	    usleep(20000);
	    
	    //std::cerr << temp_tileset->texture;
	    tilesets.insert({path,temp_tileset});

		return path;
	}
}