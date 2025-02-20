namespace mental{
	class color
	{
	public:
		int r, g, b, a;

		color(){
			this->r = 255;
			this->g = 255;
			this->b = 255;
			this->a = 255;
		};

		color( int nr, int ng, int nb ){
			this->r = nr;
			this->g = ng;
			this->b = nb;
			this->a = 255;
		};

		color( int nr, int ng, int nb, int na ){
			this->r = nr;
			this->g = ng;
			this->b = nb;
			this->a = na;
		};

		Color raylib(){
			return (Color){this->r,this->g,this->b,this->a};
		}
	};
}