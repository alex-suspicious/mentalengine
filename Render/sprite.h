namespace renderable{

	class sprite: public renderable::base{
	public:
        bool textureLoaded = false;
        std::string texture = "";
        bool convex_shape = false;

        ~sprite(){};

		sprite( std::string textureName ){
			this->type = 1;
			
			this->texture = "assets/textures/" + textureName;
			this->scale.x = 1;
			this->scale.y = 1;
			this->color = mental::color(255,255,255,255);
			if( mental::texturesBuffer.find("assets/textures/" + textureName) != mental::texturesBuffer.end() )
				this->textureLoaded = true;

			this->sizeRect = mental::loadTextureBounds( textureName );
		};

		sprite(){
			this->type = 1;

			this->scale.x = 1;
			this->scale.y = 1;
			this->color = mental::color(255,255,255,255);
		};

        void setTextureRect( mental::bounds placeholder ){
        	this->sizeRect = placeholder;

			this->origin.x = this->sizeRect.width/2;
			this->origin.y = this->sizeRect.height/2;
        }

		void setTexture( std::string texture_ptr ){
			this->texture = texture_ptr;
			if( mental::texturesBuffer.find(texture_ptr) != mental::texturesBuffer.end() )
				this->textureLoaded = true;

			this->sizeRect.width = mental::imageToTextureBuffer[this->texture].width;
			this->sizeRect.height = mental::imageToTextureBuffer[this->texture].height;

			this->origin.x = this->sizeRect.width/2;
			this->origin.y = this->sizeRect.height/2;
		}

		void setTextureStr( std::string texture_name ){
			this->texture = "assets/textures/" + texture_name;
			if( mental::texturesBuffer.find("assets/textures/" + texture_name) != mental::texturesBuffer.end() )
				this->textureLoaded = true;

			this->sizeRect = mental::loadTextureBounds( texture_name );
			this->origin.x = this->sizeRect.width/2;
			this->origin.y = this->sizeRect.height/2;
		}

		void draw( float time, int index ){
			if( !this->textureLoaded )
				return;

			if( this->useShader ){
				SetShaderValue(mental::shadersBuffer[this->shader],GetShaderLocation(mental::shadersBuffer[this->shader], "time"),&time,SHADER_UNIFORM_FLOAT);
				BeginShaderMode( mental::shadersBuffer[this->shader] );
			}

			//rlPushMatrix();
				//rlTranslatef(0.0f, 0.0f, (this->depthLayer*15) - ((float)this->layer)*0.15f);

				DrawTexturePro(mental::texturesBuffer[this->texture],
					{ this->sizeRect.left, this->sizeRect.top, static_cast<float>(this->sizeRect.width), static_cast<float>(this->sizeRect.height) },
					{ this->position.x, this->position.y, this->sizeRect.width*this->scale.x, this->sizeRect.height*this->scale.y },
					{ this->origin.x*this->scale.x ,this->origin.y*this->scale.y},
					this->angle, 
					color.raylib());
			//rlPopMatrix();

            if( global::debug ){
				rlPushMatrix();
                    //rlTranslatef(0,0, this->depthLayer*15 );
	            	DrawLineEx((this->position - amath::Vector2((this->sizeRect.width*this->scale.x)/2, (this->sizeRect.height*this->scale.y)/2)).raylib(), (this->position + amath::Vector2(cos(this->id)*50 - (this->sizeRect.width*this->scale.x)/2,sin(this->id)*50 - (this->sizeRect.height*this->scale.y)/2)).raylib(), 3, RED);
	            	DrawRectangleLines(this->position.x - (this->sizeRect.width*this->scale.x)/2, this->position.y - (this->sizeRect.height*this->scale.y)/2, this->sizeRect.width*this->scale.x, this->sizeRect.height*this->scale.y, RED);

	                rlPushMatrix();
	                    //rlTranslatef(cos(this->id)*50 - (this->sizeRect.width*this->scale.x)/2,sin(this->id)*50 - (this->sizeRect.height*this->scale.y)/2, -15);
	                    rlTranslatef(cos(this->id)*50 - (this->sizeRect.width*this->scale.x)/2,sin(this->id)*50 - (this->sizeRect.height*this->scale.y)/2, 0);
	                    DrawText(TextFormat("INDEX: %0i", index), this->position.x, this->position.y, 20, RED);
	                rlPopMatrix();
                rlPopMatrix();
            }

			if( this->useShader )
				EndShaderMode();
		}

	};

}
