
namespace mental{
    namespace save{

        void write( std::string path, std::string content){
            std::ofstream save_file;
            save_file.open(file::internal + path);
            save_file << content;
            save_file.close();
        }

        std::string read( std::string path ){
            std::ifstream outfile;
            outfile.open(file::internal + path);
            if (outfile.is_open())
            {
                std::string content((std::istreambuf_iterator<char>(outfile)),
                             std::istreambuf_iterator<char>());
                outfile.close();
                return content;
            }else{
                return "";
                outfile.close();
            }
        }

    }
}