namespace mental{
	class rect
	{
	public:
		amath::Vector2 position;
		amath::Vector2 size;
		luaClasses::FlexibleClass* owner;
		bool hasOwner = false;

		rect(){
			mental::collisionRectBuffer.push_back(this);
			this->position = amath::Vector2(0,0);
			this->size = amath::Vector2(0,0);
		};

		rect( float x, float y, float width, float heigth ){
			mental::collisionRectBuffer.push_back(this);
			this->position = amath::Vector2(x,y);
			this->size = amath::Vector2(width,heigth);
		};

		void setOwner( luaClasses::FlexibleClass* newOwner ){
			this->owner = newOwner;
			this->hasOwner = true;
		}

		~rect(){
	        for (int i = 0; i < mental::collisionRectBuffer.size(); i++)
	        {
	            if( (rect*)mental::collisionRectBuffer[i] == this ){
	            	//delete mental::collisionRectBuffer[i];
	                mental::collisionRectBuffer.erase(mental::collisionRectBuffer.begin() + i);
	                break;
	            }
	        }
		};

		void setPosition( float x, float y ){
			this->position.x = x;
			this->position.y = y;
		}

		void setPositionByVectorLua( amath::Vector2 vec2 ){
			this->position = vec2;
		}

		void setSize( float x, float y ){
			this->size.x = x;
			this->size.y = y;
		}

		void setSizeByVectorLua( amath::Vector2 vec2 ){
			this->size = vec2;
		}

		amath::Vector2 getPosition(){
			return this->position;
		}

		amath::Vector2 getSize(){
			return this->size;
		}

	};
}