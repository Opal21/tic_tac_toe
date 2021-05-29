#include "lib.hpp"

void save_header(std::ofstream& stream, const char* header, int length)
{
    stream.write(header, length);
}

bool check_header(std::istream& stream, const char* header, int length)
{
    for (int i = 0; i < length; ++i)
    {
        char buffer = 0;
        stream.read(&buffer, sizeof(buffer));
        if (buffer != header[i])
        {
            return false;
        }
    }
    return true;
}