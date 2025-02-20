namespace renderable{

	class model{
	public:
		int layer = 0;
		float depthLayer = 0;
		int id = 0;
		int time = 15;
		//sf::Shader* shader;
		bool screen = false;
		bool useShader = false;
		bool removed = false;
		bool newBorn = true;
		bool interpolation = false;
		bool depthpass = true;
		float angle = 0;
		mental::bounds textureRect;
		amath::Vector3 scale;
        amath::Vector2 renderPos;
        amath::Vector3 position;
        amath::Vector2 bounds;
        Model model_mesh;
        mental::color color;
        
        float pitch = 0;
        float yaw = 0;
        float roll = 0;

        amath::Vector2 angleVector;
        //sf::ConvexShape polygon;
        Texture2D texture;
        bool convex_shape = false;
        bool screenCords = false;

        //~model(){
        	//delete &this->polygon;
        	//points.clear();
        //};


		model( std::string modelName ){
			this->model_mesh = mental::loadModel( modelName );

//			Texture2D first = mental::loadTexture("models/" + m_str::split(modelName,'.')[0] + "/1.png");
//			if( first.id > 0 )
//				this->model_mesh.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = first;
//
//			Texture2D second = mental::loadTexture("models/" + m_str::split(modelName,'.')[0] + "/2.png");
//			if( second.id > 0 )
//				this->model_mesh.materials[1].maps[MATERIAL_MAP_DIFFUSE].texture = second;
//
//			Texture2D third = mental::loadTexture("models/" + m_str::split(modelName,'.')[0] + "/3.png");
//			if( third.id > 0 )
//				this->model_mesh.materials[2].maps[MATERIAL_MAP_DIFFUSE].texture = third;



			this->color = mental::color(255,255,255,255);
			mental::modelsBuffer.push_back(this);
		};

		model(){
			this->color = mental::color(255,255,255,255);
			mental::modelsBuffer.push_back(this);
		};

        void setRotation( float newAngle ){
        	this->angle = newAngle;
        }

        float getRotation(){
        	return this->angle;
        }

        void setScale( float X, float Y, float Z ){
        	this->scale.x = X;
        	this->scale.y = Y;
        	this->scale.z = Z;
        }

        void setPosition( float X, float Y, float Z ){
        	this->position.x = X;
        	this->position.y = Y;
        	this->position.z = Z;
        }

        void setPosition( amath::Vector3 newPosition ){
        	this->position = newPosition;
        }

        void setPositionXYZ( float X, float Y, float Z ){
        	this->position.x = X;
        	this->position.y = Y;
        	this->position.z = Z;
        }

        void setPositionByVectorLua( amath::Vector3 newPosition ){
        	this->position = newPosition;
        }

        void setPositionByVector2DLua( amath::Vector2 newPosition ){
        	this->position = amath::Vector3(newPosition.x,newPosition.y,0);
        }

        void setTextureRect( mental::bounds placeholder ){
        	this->textureRect = placeholder;
        }

        void setOrigin( float X, float Y ){

        }

        amath::Vector3 getPosition(){
        	return this->position;
        }

        mental::bounds getLocalBounds(){
			mental::bounds temp = mental::bounds(0,0,(this->texture.width*this->scale.x) ,(this->texture.height*this->scale.y));
			return temp;
        }

		void loadShader( std::string shader ){
			this->useShader = true;
			//this->shader = mental::loadShader(shader);
		}

		void setTexture( Texture2D texture_ptr ){
			this->texture = texture_ptr;

			this->textureRect.width = this->texture.width;
			this->textureRect.height = this->texture.height;
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

		mental::bounds getGlobalBounds(){
			mental::bounds temp = mental::bounds(0,0,0,0);
			return temp;
		}

		mental::bounds getBounds(){
			//if( this->convex_shape )
			//	return this->polygon.getGlobalBounds();
			//else
			return this->getGlobalBounds();
		}


		//void drawing( sf::RenderTexture* target, float time, sf::View matrix, sf::View screenSpaceView, sf::Texture* buffer = nullptr, sf::Shader* customShader = nullptr ){
		void draw( float time ){
            //amath::Vector2 tempVector = amath::Vector2(this->position).lerp( amath::Vector2(luaInit::campos), this->depthLayer/100.0f );

            this->model_mesh.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*this->pitch, DEG2RAD*this->yaw, DEG2RAD*this->roll });
			DrawModelEx(this->model_mesh, this->position.raylib(), Vector3(), 0, this->scale.raylib(), WHITE);

		}

	};

}
