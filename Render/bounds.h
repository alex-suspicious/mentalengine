namespace mental{
	class bounds{
	public:
		float top = 0;
		float left = 0;
		float width = 0;
		float height = 0;

		bounds(){};
		bounds(float top, float left, float width, float height){
			this->top = top;
			this->left = left;
			this->width = width;
			this->height = height;
		};
		bounds(amath::Vector2 pos, amath::Vector2 size){
			this->top = pos.y;
			this->left = pos.x;
			this->width = size.x;
			this->height = size.y;
		};

	};
}