namespace scene{
	//std::vector<> tilesets;
	

	void load( std::string path ){
	    std::string testXml = file::read("scenes/" + path);
	    pugi::xml_document doc;
	    pugi::xml_parse_result result = doc.load_string(testXml.c_str());
	    
	    luaFunctions::print( "+Loading the scene" + path );
	    if (!result){
	    	luaFunctions::print( "!Can't load the scene, parsing error!" );
	        return;
	    }
	    luaFunctions::print( "+Scene was parsed!" );

	    std::string allCode = "";

	    pugi::xml_node map = doc.child("map");
	    if( map.attribute("backgroundcolor") ){
			char *str = (char*)map.attribute("backgroundcolor").value();
			int r, g, b;
			sscanf(str, "#%02x%02x%02x", &r, &g, &b);

	    	allCode += "sky.setColor( mnt.color("+std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+",255) )\n";
	    }

	    renderable::tiles tempTiles = renderable::tiles();
	    for (pugi::xml_node map_tileset: map.children("tileset"))
	    {
	    	//std::cerr << map_tileset.attribute("source").value();

			std::string tileset = scene::loadTileset(map_tileset.attribute("source").value());

			tempTiles.addTileset(tileset, std::stoi( map_tileset.attribute("firstgid").value() ) );
	    }

	    int y_order = 0;
        if( map.child("properties") ){
	        for (pugi::xml_node property: map.child("properties").children("property")){
	        	std::string name = property.attribute("name").value();
	        	std::string value = property.attribute("value").value();

	        	if( name == "y-order" ){
	        		tempTiles.y_order = true;
		    		y_order = std::stoi(value);
	        	}

	        	//y-order
	        }
	    }

	    int layer_id = 0;
	    for (pugi::xml_node map_layer: map.children("layer"))
	    {
	    	int temp_layer_affector = 0;

	        if( map_layer.child("properties") ){
		        for (pugi::xml_node property: map_layer.child("properties").children("property")){
		        	std::string name = property.attribute("name").value();
		        	std::string value = property.attribute("value").value();

		        	if( name == "layer" )
			    		temp_layer_affector = std::stoi(value);
		        }
		    }

		    layer_id+=100;

		    for (pugi::xml_node map_data: map_layer.children("data"))
		    {
			    for (pugi::xml_node data_chunk: map_data.children("chunk"))
			    {
			    	int chunk_width = std::stoi(data_chunk.attribute("width").value());
			    	int chunk_height = std::stoi(data_chunk.attribute("height").value());

			    	int chunk_x = std::stoi(data_chunk.attribute("x").value());
			    	int chunk_y = std::stoi(data_chunk.attribute("y").value());

			    	std::string chunk_values = data_chunk.child_value();
			    	chunk_values = m_str::replaceSubStr(chunk_values,"\n","");
			    	auto chunk_values_splitted = m_str::split(chunk_values,',');

				    //std::cerr << chunk_values;

			    	std::vector<std::vector<int>> chunk_matrix;

			    	for (int y = 0; y < chunk_values_splitted.size(); y+=chunk_width)
			    	{
			    		std::vector<int> chunk_line;
			    		for (int x = 0; x < chunk_width; x++)
				    	{
				    		chunk_line.push_back( std::stoi( chunk_values_splitted[y+x] ) );
				    	}

				    	chunk_matrix.push_back(chunk_line);
				    	chunk_line.clear();
			    	}

					tempTiles.addChunk( chunk_matrix, chunk_x, chunk_y, layer_id + temp_layer_affector );
			    }
		    }
		}

	    tempTiles.finish();


	    for (pugi::xml_node objectgroup: map.children("objectgroup"))
	    {
	    	int temp_layer_affector = 0;

	        if( objectgroup.child("properties") ){
		        for (pugi::xml_node property: objectgroup.child("properties").children("property")){
		        	std::string name = property.attribute("name").value();
		        	std::string value = property.attribute("value").value();

		        	if( name == "layer" )
			    		temp_layer_affector = std::stoi(value);
		        }
		    }

	    	for (pugi::xml_node object: objectgroup.children("object"))
		    {
		    	amath::Vector2 objPos = amath::Vector2(0,0);

		        if( object.attribute("x") ){
		        	objPos.x = std::stof(object.attribute("x").value());
		        	objPos.y = std::stof(object.attribute("y").value());
		        }

		        bool created = false;

		        if( object.child("point") ){
		        	created = true;
			        std::string randomName = m_str::randomSafe(25);
			        std::string code = randomName + " = " + object.attribute("type").value() + "()\n";

			        if( object.child("properties") ){
				        for (pugi::xml_node property: object.child("properties").children("property")){
				        	std::string name = property.attribute("name").value();
				        	std::string value = property.attribute("value").value();

				        	name[0] = toupper(name[0]);
					    	code += randomName + ":set" + name + "("+value+")\n";
				        }
				    }

				    code += randomName + ":setPos(mnt.vector2("+std::to_string(objPos.x)+","+std::to_string(objPos.y)+"))\n";

			        allCode += "\n" + code;
		        }

		        if( object.child("text") ){
		        	created = true;
		        	pugi::xml_node textEl = object.child("text");

			        std::string randomName = m_str::randomSafe(25);
			        std::string code = randomName + " = mnt.text(\"" + textEl.child_value() + "\")\n";

			        if( object.child("properties") ){
				        for (pugi::xml_node property: object.child("properties").children("property")){
				        	std::string name = property.attribute("name").value();
				        	std::string value = property.attribute("value").value();

				        	name[0] = toupper(name[0]);
					    	code += randomName + ":set" + name + "("+value+")\n";
				        }
				    }

				    code += randomName + ":setPos(mnt.vector2("+std::to_string(objPos.x)+","+std::to_string(objPos.y)+"))\n";

			        allCode += "\n" + code;
		        }

		    	if( object.child("polygon") || object.attribute("width") && !object.attribute("gid") ){
		    		created = true;
		    		pugi::xml_node polygon = object.child("polygon");

			    	mental::brush* tempBrush = new mental::brush();
			    	std::vector<amath::Vector2> points;

			    	if( polygon ){
			    		std::vector<std::string> pointsVectorString = m_str::split(polygon.attribute("points").value(),' ');

				    	for (int i = 0; i < pointsVectorString.size(); i++)
				    	{
				    		std::vector<std::string> pointXY = m_str::split(pointsVectorString[i],',');
				    		points.push_back( amath::Vector2( std::stof(pointXY[0]), std::stof(pointXY[1]) ) );
				    	}
				    }
			    	else{
			    		float widthBrush = std::stof(object.attribute("width").value());
			    		float heightBrush = std::stof(object.attribute("height").value());

			    		points.push_back( amath::Vector2( 0, 0 ) );
			    		points.push_back( amath::Vector2( widthBrush, 0 ) );
			    		points.push_back( amath::Vector2( widthBrush, heightBrush ) );
			    		points.push_back( amath::Vector2( 0, heightBrush ) );
			    	}

			    	tempBrush->points = points;
			    	tempBrush->done();

			        if( object.child("properties") ){
				        for (pugi::xml_node property: object.child("properties").children("property")){
				        	std::string name = property.attribute("name").value();
				        	std::string value = property.attribute("value").value();
				        	//std::cerr << name << ": " << value << "\n";

				        	if( name == "texture" )
					    		tempBrush->polygon->setTexture( mental::loadTexture( value ) );

				        	if( name == "layer" )
					    		tempBrush->polygon->layer = std::stof(value);

					    	//if( name == "depth" )
					    	//	tempBrush->polygon->depth = std::stof(value);

					    	if( name == "sensor" )
					    		tempBrush->body->setSensor( value == "true" );

				        }
				    }

		        	tempBrush->polygon->setPosition( objPos );
		        	if( tempBrush->collision )
		        		tempBrush->body->setPosition( objPos );
		    	}

		    	if( !created ){
		        	int gid = std::stoi(object.attribute("gid").value());

		        	if( gid ){
						auto [firstgid, tilesetString] = tempTiles.getClosestTileset(gid);
						if( tilesetString == "" )
							continue;

						auto tilesetEntity = scene::tilesets[tilesetString];
						auto [uvPosX, uvPosY] = tempTiles.getUvPos(gid-firstgid,tilesetEntity->columns);

		        		auto width = std::stof(object.attribute("width").value());
		        		auto height = std::stof(object.attribute("height").value());
		        		auto rotation = 0;

		        		if( object.attribute("rotation") )
		        			rotation = std::stof(object.attribute("rotation").value());

		        		mental::dynamic* sprite_obj = new mental::dynamic(tilesetEntity->source);

		        		sprite_obj->sprite->setTextureRect(mental::bounds(uvPosY*tilesetEntity->tileHeight,uvPosX*tilesetEntity->tileWidth,tilesetEntity->tileWidth,tilesetEntity->tileHeight));

		        		sprite_obj->sprite->setOrigin( 0,tilesetEntity->tileHeight );
	

		        		sprite_obj->setRotation(rotation);
		        		sprite_obj->setPositionByVector(objPos);
		        		sprite_obj->setScaleXY(width/tilesetEntity->tileWidth,height/tilesetEntity->tileHeight);
		        		//sprite_obj->sprite->newBorn = false;
		        		//sprite_obj->sprite->textureLoaded = true;

		        		if( y_order )
		        			sprite_obj->setLayer(layer_id + objPos.y + temp_layer_affector);
		        		else
		        			sprite_obj->setLayer(layer_id + temp_layer_affector);

				        if( object.child("properties") ){
					        for (pugi::xml_node property: object.child("properties").children("property")){
					        	std::string name = property.attribute("name").value();
					        	std::string value = property.attribute("value").value();
					        	//std::cerr << name << ": " << value << "\n";

					        	if( name == "layer" ){
					        		if( y_order )
						    			sprite_obj->setLayer(layer_id+std::stoi(value) + objPos.y + temp_layer_affector);
					        		else
						    			sprite_obj->setLayer(layer_id+std::stoi(value) + temp_layer_affector);
					        	}

					        }
					    }

		        		//std::cerr << "levels/" + tilesetEntity->source << "\n";
		        	}
		    	}
			}
			layer_id+=100;
	    }
	    
	    luaFunctions::loadString(allCode);
	    luaFunctions::print( "+Scene is fully loaded!" );
	}

	void lua(){
		luabridge::getGlobalNamespace(luaInit::luaState)
		.beginNamespace("scene")
			.addFunction ("load", &scene::load)
		.endNamespace ();
	}
}
