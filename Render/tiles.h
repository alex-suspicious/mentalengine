namespace renderable{

	class tiles: public renderable::base{
	public:
		bool ready = false;
		bool y_order = false;
		std::map<int,std::string> tilesets;
		std::vector<int> gids;
		std::vector<int> layer_ids;
		std::vector<std::vector<std::vector<int>>> tilemap;
		std::vector<std::pair<int,int>> chunks_pos;

        ~tiles(){};

		tiles(){
			//this->type = 4;
			//mental::renderablesBuffer.push_back( this );
		};

		std::pair<int,std::string> getClosestTileset(int input) {
			auto it = this->tilesets.upper_bound(input);
			if (it == this->tilesets.begin()) {
				return {0,""};
			}
			--it;
			return {it->first,it->second};
		}

		std::pair<int, int> getUvPos( int gid, int columns ){
		    int x = gid % columns;
		    int y = gid / columns;
		    return {x, y};
		}

		void addTileset( std::string tileset, int firstgid ){
			this->gids.push_back(firstgid);
			this->tilesets.insert({firstgid,tileset});
		}

		void addChunk( std::vector<std::vector<int>> chunk, int x, int y, int layer_id ){
			this->tilemap.push_back(chunk);
			this->chunks_pos.push_back({x,y});
			this->layer_ids.push_back(layer_id);
		}

		int getGid( int index ){
			return index;
		}

		void finish(){
			this->ready = true;

			for (int z = 0; z < this->tilemap.size(); z++)
			{
				auto [xAffector, yAffector] = this->chunks_pos[z]; 

				for (int y = 0; y < this->tilemap[z].size(); y++)
				{
					for (int x = 0; x < this->tilemap[z][y].size(); x++)
					{

						int tile_gid = this->tilemap[z][y][x];
						//std::cerr << tile_gid << " ";

						auto [firstgid, tilesetString] = this->getClosestTileset(tile_gid);
						if( tilesetString == "" )
							continue;

						auto tilesetEntity = scene::tilesets[tilesetString];
						auto [uvPosX, uvPosY] = this->getUvPos(tile_gid-firstgid,tilesetEntity->columns);


						//std::cerr << uvPosX << " " << uvPosY << "\n";
//						DrawTexturePro(mental::texturesBuffer[ tilesetEntity->texture ],
//							{ uvPosX*tilesetEntity->tileWidth, uvPosY*tilesetEntity->tileHeight, tilesetEntity->tileWidth, tilesetEntity->tileHeight },
//							{ (x+xAffector)*tilesetEntity->tileWidth, (y+yAffector)*tilesetEntity->tileHeight, tilesetEntity->tileWidth, tilesetEntity->tileHeight },
//							{ 0 ,0},
//							0, 
//							WHITE);

		        		mental::dynamic* sprite_obj = new mental::dynamic(tilesetEntity->source);

		        		sprite_obj->sprite->setTextureRect(mental::bounds(uvPosY*tilesetEntity->tileHeight,uvPosX*tilesetEntity->tileWidth,tilesetEntity->tileWidth,tilesetEntity->tileHeight));

		        		sprite_obj->sprite->setOrigin( 0,tilesetEntity->tileHeight );
	

		        		//sprite_obj->setRotation(rotation);
		        		sprite_obj->setPositionByVector(amath::Vector2((x+xAffector)*tilesetEntity->tileWidth, (y+yAffector)*tilesetEntity->tileHeight + tilesetEntity->tileHeight));
		        		//sprite_obj->setScaleXY(width/tilesetEntity->tileWidth,height/tilesetEntity->tileHeight);
		        		//sprite_obj->sprite->newBorn = false;
		        		//sprite_obj->sprite->textureLoaded = true;
		        		if( this->y_order )
		        			sprite_obj->setLayer(this->layer_ids[z] + ((y+yAffector)*tilesetEntity->tileHeight));
		        		else
		        			sprite_obj->setLayer(this->layer_ids[z]);
					}
					//std::cerr << "\n";
				}
			}

		}

		void draw( float time, int index ){
			if( !this->ready )
				return;
			if( this->tilesets.size() < 1 )
				return;


			//auto tileset = getClosestTileset;

			rlPushMatrix();
			for (int z = 0; z < this->tilemap.size(); z++)
			{
				auto [xAffector, yAffector] = this->chunks_pos[z]; 

				for (int y = 0; y < this->tilemap[z].size(); y++)
				{
					for (int x = 0; x < this->tilemap[z][y].size(); x++)
					{

						int tile_gid = this->tilemap[z][y][x];
						//std::cerr << tile_gid << " ";

						auto [firstgid, tilesetString] = this->getClosestTileset(tile_gid);
						if( tilesetString == "" )
							continue;

						auto tilesetEntity = scene::tilesets[tilesetString];
						auto [uvPosX, uvPosY] = this->getUvPos(tile_gid-firstgid,tilesetEntity->columns);


						//std::cerr << uvPosX << " " << uvPosY << "\n";
						DrawTexturePro(mental::texturesBuffer[ tilesetEntity->texture ],
							{ uvPosX*tilesetEntity->tileWidth, uvPosY*tilesetEntity->tileHeight, tilesetEntity->tileWidth, tilesetEntity->tileHeight },
							{ (x+xAffector)*tilesetEntity->tileWidth, (y+yAffector)*tilesetEntity->tileHeight, tilesetEntity->tileWidth, tilesetEntity->tileHeight },
							{ 0 ,0},
							0, 
							WHITE);
					}
					//std::cerr << "\n";
				}
			}
			rlPopMatrix();


		}

	};

}
