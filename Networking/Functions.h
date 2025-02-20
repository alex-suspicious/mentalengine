namespace http{

	std::string get( const std::string& uri ){
//	    // Parse URL to get host and path
//	    size_t protocolEnd = uri.find("://");
//	    if (protocolEnd == std::string::npos) return "";
	    //
//	    size_t hostStart = protocolEnd + 3;
//	    size_t pathStart = uri.find("/", hostStart);
	    //
//	    if (pathStart == std::string::npos) {
//	        pathStart = uri.length();
//	    }
	    //
//	    std::string host = uri.substr(hostStart, pathStart - hostStart);
//	    std::string path = pathStart < uri.length() ? uri.substr(pathStart) : "/";
	    //
//	    // Create client
//	    httplib::Client cli(host);
	    //
//	    // Make GET request
//	    auto result = cli.Get(path);
	    //
//	    // Check if request was successful
//	    if (result && result->status == 200) {
//	        return result->body;
//	    }
	    
	    return "";
	}

}
