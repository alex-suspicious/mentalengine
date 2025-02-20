namespace m_str{
	std::string replaceSubStr(
	    std::string str,
	    const std::string &subStr,
	    const std::string &replacement)
	{
	    // Search for the given substring in string
	    size_t pos = str.find(subStr);
	    // Iterate till index position of substring is valid
	    while (pos != std::string::npos)
	    {
	        // Replace the first occurrence of substring in string
	        // from position pos onwards
	        str.replace(pos, subStr.length(), replacement);
	        // Get the index position of next occurrence of substring in string
	        pos = str.find(subStr, pos + replacement.length());
	    }

	    return str;
	}

	bool includes( std::string &str, std::string sub ){
		return str.find(sub) != std::string::npos;
	}

	bool includesRaw( std::string str, std::string sub ){
		return str.find(sub) != std::string::npos;
	}


	std::vector<std::string> split(std::string s, char del)
	{
		std::vector<std::string> res;
	    std::stringstream ss(s);
	    std::string word;
	    while (!ss.eof()) {
	        getline(ss, word, del);
	        res.push_back(word);
	    }
	    return res;
	}

	std::string random(int length) {
	    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	    static const int charsetSize = sizeof(charset) - 1;

	    std::mt19937 generator(std::random_device{}());
	    std::uniform_int_distribution<int> distribution(0, charsetSize - 1);

	    std::string randomString;
	    randomString.reserve(length);

	    for (int i = 0; i < length; ++i) {
	        randomString.push_back(charset[distribution(generator)]);
	    }

	    return randomString;
	}

	std::string randomSafe(int length) {
	    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	    static const int charsetSize = sizeof(charset) - 1;

	    std::mt19937 generator(std::random_device{}());
	    std::uniform_int_distribution<int> distribution(0, charsetSize - 1);

	    std::string randomString;
	    randomString.reserve(length);

	    for (int i = 0; i < length; ++i) {
	        randomString.push_back(charset[distribution(generator)]);
	    }

	    return randomString;
	}
}