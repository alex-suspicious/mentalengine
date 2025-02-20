namespace mental{
	class rect
	{
	public:
		float top;
		float left;
		float height;
		float width;

		rect( float newTop,float newLeft,float newHeight,float newWidth ){
			this->top = newTop;
			this->left = newLeft;
			this->height = newHeight;
			this->width = newWidth;
		};
	};
}