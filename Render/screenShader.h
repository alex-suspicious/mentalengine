namespace screen{
	class Shader{
		public:
		//sf::Shader *native;
		std::string name = "";
		bool enabled = true;

		Shader( std::string name ){
			this->name = name;
			//this->native = mental::loadShader(name);
		};
	};
}