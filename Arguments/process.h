namespace arguments{
	std::string help_message = "\
--help				- Returns the help information.\n\
--say=text			- Returns text to the terminal.\n\
--lua=code			- Runs the Lua code.\n\
--skip-logo			- Skips the MentalGames logo.\n\
--scene=scenename		- Loads the scene file ( no matter game scene or addon one )\n\
--debug				- Forces the debug mode.\n\
--windowed			- Opens the game in a window.\n\
--w=width			- Set the width of the window.\n\
--h=height			- Set the height of the window.";

    std::map<std::string, std::function<void(std::string)>> methods = {
        {"--help", [](std::string value = "") {
            std::cerr << help_message << std::endl;
            exit(1);
        }},

        {"--say", [](std::string value = "") {
            std::cerr << value << std::endl;
            exit(1);
        }},

        {"--lua", [](std::string value = "") {
        	luaFunctions::loadString(value);
            exit(1);
        }},

        {"--skip-logo", [](std::string value = "") {
            global::skip_logo = true;
        }},

		{"--scene", [](std::string value = "") {
            global::load_map = value;
        }},

		{"--debug", [](std::string value = "") {
            global::debug = true;
        }},

        {"--windowed", [](std::string value = "") {
            global::windowed = true;
        }},

        {"--w", [](std::string value = "") {
            global::windowed_width = std::stoi(value);
        }},

        {"--h", [](std::string value = "") {
            global::windowed_height = std::stoi(value);
        }}
    };

	void process( int argc, char* argv[] ){
		for (int i = 0; i < argc; i++)
		{
			auto name = std::string(argv[i]);
			std::string value = "";

			if( m_str::includesRaw(name, "=") ){
				std::vector<std::string> splitted = m_str::split(name, '=');
				name = splitted[0];
				value = splitted[1];
			}

			auto temp = methods.find( name );
			if( temp == methods.end() )
				continue;

			methods[name](value);
		}
	}
}