namespace renderable{
	class base{
	public:
		int layer = 0;
		float depthLayer = 0;
		int id = 0;
		int type;
		int time = 15;
		bool screen = false;
		bool useShader = false;
		bool removed = false;
		std::string shader;
		bool newBorn = true;
		bool interpolation = false;
		bool depthpass = true;
		float angle = 0;
		mental::bounds sizeRect;
		amath::Vector2 scale;
        amath::Vector2 renderPos;
        amath::Vector2 position;
        amath::Vector2 bounds;
        amath::Vector2 origin;
        mental::color color;
        float renderAngle = 0;
        amath::Vector2 angleVector;
        bool screenCords = false;

        ~base(){};
		base(){};

        void setRotation( float newAngle ){
        	this->angle = newAngle;
        }

        float getRotation(){
        	return this->angle;
        }

        void setScale( float X, float Y ){
        	this->scale.x = X;
        	this->scale.y = Y;
        }

        void setPosition( float X, float Y ){
        	this->position.x = X;
        	this->position.y = Y;
        }

        void setPosition( amath::Vector2 newPosition ){
        	this->position = newPosition;
        }

        void setOrigin( float X, float Y ){
        	this->origin.x = X;
        	this->origin.y = Y;
        }

        amath::Vector2 getPosition(){
        	return this->position;
        }

        mental::bounds getLocalBounds(){
			mental::bounds temp = mental::bounds(0,0,(this->sizeRect.width*this->scale.x) ,(this->sizeRect.height*this->scale.y));
			return temp;
        }

		void loadShader( std::string shader ){
			this->shader = mental::loadShader(shader);
			if( this->shader != "" )
				this->useShader = true;
		}

		void setColor( mental::color newColor ){
			this->color = newColor;
		}
		
		void setShaderFloatArray( std::string variable, std::vector<float> arr ){
			const float* dataPtr = arr.data();
			//this->shader->setUniformArray(variable, dataPtr,arr.size());
		}

		void setShaderInt(std::string variable, int parameter){
			//this->shader->setUniform(variable, parameter);
		}

		void setShaderFloat(std::string variable, float parameter){
			//this->shader->setUniform(variable, parameter);
		}

		void setShaderColor(std::string variable, mental::color parameter){
			//this->shader->setUniform(variable, sf::Glsl::Vec4(parameter.r,parameter.g,parameter.b,parameter.a));
		}

		void setRenderPosition(float x, float y){
			if( !this->interpolation ){
				this->setPosition( x,y );
				return;
			}

			this->renderPos = amath::Vector2(x,y);
			if( this->newBorn ){
				this->newBorn = false;
				this->setPosition( x,y );
			}
		}

		void setRenderPosition( amath::Vector2 pos ){
			if( !this->interpolation ){
				this->setPosition( pos.x,pos.y );
				return;
			}

			this->renderPos = amath::Vector2(pos.x,pos.y);
			if( this->newBorn ){
				this->newBorn = false;
				this->setPosition( pos.x,pos.y );
			}
		}

		void setRenderRotation( float angle ){
			if( !this->interpolation ){
				this->setRotation( angle );
				return;
			}

			this->renderAngle = angle;
			if( this->newBorn ){
				this->newBorn = false;
				this->setRotation( angle );
			}
		}

		void update(){
			this->time = std::max(this->time-1,0);
			if( !this->time )
				this->newBorn = false;

			if( !this->interpolation )
				return;

			this->setPosition( this->getPosition().lerp(this->renderPos,0.3f) );
			this->angleVector = amath::Vector2( angleVector ).lerp( amath::Vector2( cos(this->renderAngle/amath::r2d), sin(this->renderAngle/amath::r2d) ),0.3f);

			this->setRotation( atan2(this->angleVector.y,this->angleVector.x)*amath::r2d );
		}

		mental::bounds getGlobalBounds(){
			mental::bounds temp = mental::bounds(0,0,(this->sizeRect.width*this->scale.x),(this->sizeRect.height*this->scale.y));
			return temp;
		}

		mental::bounds getBounds(){
			return this->getGlobalBounds();
		}

		amath::Vector2 getBoundsXY(){
			auto temp = this->getGlobalBounds();
			return amath::Vector2(temp.width, temp.height);
		}

		void draw( float time, int index ){}

	};



	struct sort_by_layer
	{
	    inline bool operator() (const void* renderable1, const void* renderable2)
	    {
	        return ( ((base*)renderable1)->layer < ((base*)renderable2)->layer);
	    }
	};
}