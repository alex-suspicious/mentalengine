namespace luaInterval{
	//sf::Clock clock;
	std::map<float, luabridge::LuaRef> awaitings;
	std::vector<luabridge::LuaRef> selfs;


	void create(luabridge::LuaRef method, float seconds, luabridge::LuaRef self){
		awaitings.emplace( std::make_pair(GetTime()*1000 + seconds, method ) );
		selfs.push_back(self);
	}

	void fire() {
		if( awaitings.size() < 1 )
			return;

		std::lock_guard<std::mutex> guard(thread::luaMutex);
	    float currentTime = GetTime()*1000;

	    // Create an iterator for awaitings
	    auto it = awaitings.begin();

	    // Iterate through the map
	    for (size_t i = 0; it != awaitings.end(); ) {
	        // Check if the current time is greater than or equal to the time stored in the map
	        if (currentTime >= it->first) {
	            // Invoke the Lua function with the corresponding self
	            if (selfs[i].isNil()) {
	                it->second();
	            } else {
	                it->second(selfs[i]);
	            }

	            // Erase the executed entry from the awaitings map
	            it = awaitings.erase(it);
	            // Erase the corresponding self from the selfs vector
	            selfs.erase(selfs.begin() + i);
	        } else {
	            ++it;
	            ++i;
	        }
	    }
	}
}