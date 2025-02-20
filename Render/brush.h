namespace renderable{

	class brush: public renderable::base{
	public:
        std::vector<amath::Vector2> points;

        bool textureLoaded = false;
        std::string texture;
        bool convex_shape = false;

        ~brush(){
        	points.clear();
        };

		brush( std::string textureName ){
			this->type = 2;

			this->texture = "assets/textures/" + textureName;
			this->scale.x = 1;
			this->scale.y = 1;
			this->color = mental::color(255,255,255,255);
			if( mental::texturesBuffer.find("assets/textures/" + textureName) != mental::texturesBuffer.end() )
				this->textureLoaded = true;

			this->sizeRect = mental::loadTextureBounds( textureName );
		};

		brush(){
			this->type = 2;

			this->scale.x = 1;
			this->scale.y = 1;
			this->color = mental::color(255,255,255,255);
		};


        void setTextureRect( mental::bounds placeholder ){
        	this->sizeRect = placeholder;
        }
        
		void setTexture( std::string texture_ptr ){
			this->texture = texture_ptr;
			if( mental::texturesBuffer.find(texture_ptr) != mental::texturesBuffer.end() )
				this->textureLoaded = true;

			this->sizeRect.width = mental::imageToTextureBuffer[this->texture].width;
			this->sizeRect.height = mental::imageToTextureBuffer[this->texture].height;
		}

		void setTextureStr( std::string texture_name ){
			this->texture = "assets/textures/" + texture_name;
			if( mental::texturesBuffer.find("assets/textures/" + texture_name) != mental::texturesBuffer.end() )
				this->textureLoaded = true;

			this->sizeRect = mental::loadTextureBounds( texture_name );
		}

        void convex( std::vector<amath::Vector2> newPoints ){
			this->convex_shape = true;
			this->points = newPoints;
			//this->points.push_back(this->points[0]);

			for (int i = 0; i < this->points.size(); i++)
			{
				if( this->points[i].x > this->bounds.x )
					this->bounds.x = this->points[i].x;
				if( this->points[i].y > this->bounds.y )
					this->bounds.y = this->points[i].y;
			}
        }

		void draw( float time, int index ){
			if( !this->textureLoaded )
				return;

			if( this->useShader ){
				SetShaderValue(mental::shadersBuffer[this->shader],GetShaderLocation(mental::shadersBuffer[this->shader], "time"),&time,SHADER_UNIFORM_FLOAT);
				BeginShaderMode( mental::shadersBuffer[this->shader] );
			}

			rlPushMatrix();
				//rlTranslatef(this->position.x, this->position.y, (this->depthLayer*15) - ((float)layer)*0.01f );
				rlTranslatef(this->position.x, this->position.y, 0 );
				rlRotatef(this->angle, 0.0f, 0.0f, 1.0f);

			    rlSetTexture(mental::texturesBuffer[this->texture].id);

			    rlBegin(RL_QUADS);

			        rlColor4ub(this->color.r, this->color.g, this->color.b, this->color.a);

			        for (int i = 0; i < this->points.size()-1; i++)
			        {
			            int reverse = (this->points.size()-1) - i;

			            rlTexCoord2f(this->points[i].x*0.004, this->points[i].y*0.004);
			            rlVertex2f(this->points[i].x,this->points[i].y);

			            rlTexCoord2f(this->points[ reverse ].x*0.004, this->points[ reverse ].y*0.004);
			            rlVertex2f(this->points[ reverse ].x, this->points[ reverse ].y);

			            rlTexCoord2f(this->points[i+1].x*0.004, this->points[i+1].y*0.004);
			            rlVertex2f(this->points[i + 1].x, this->points[i + 1].y);

			            rlTexCoord2f(this->points[i+1].x*0.004, this->points[i+1].y*0.004);
			            rlVertex2f(this->points[i + 1].x, this->points[i + 1].y);
			        }
			    rlEnd();
			rlPopMatrix();

		    rlSetTexture(0);

			if( this->useShader )
				EndShaderMode();

			return;


			if( this->useShader )
				EndShaderMode();
		}

	};

}
