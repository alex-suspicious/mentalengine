class StringStreamBuffer : public std::streambuf {
    public:
        std::string str() const { return m_stream.str(); }
        void clear() { m_stream.str(""); m_stream.clear(); }

    protected:
        // Override the overflow method to capture each character
        int overflow(int c) override {
            if (c != EOF) {
                m_stream.put(static_cast<char>(c));
            }
            return c;
        }

        // Override sync to know when output is flushed
        int sync() override {
            onOverflowEnd();  // Call our custom handler when flushing
            return 0;
        }
    private:
        std::ostringstream m_stream;

        // Custom handler for when overflow ends
        void onOverflowEnd() {
            // Here you could process the message
            auto temp = m_stream.str();
            temp.pop_back();

            luaFunctions::print( "!" + temp );
            // Clear after processing
            clear();
        }
};

class NullBuffer : public std::streambuf {
    public:
        int overflow(int c) override { return c; }
};

class NullStream : public std::ostream {
    public:
        NullStream() : std::ostream(&m_sb) {}
    private:
        NullBuffer m_sb;
};