#include "f_conversion.hpp"
namespace zf
{
    bool toInt(std::string str, int& value)
    {
        std::istringstream buffer(str);
        int temp;
        buffer >> temp;
        if(str != toString(temp)) //if the converted value is different then return 0 (similar to atoi)
        {
            return false;
        }
        value = temp;
        return true;
    }

    std::string toString(int i)
    {
        std::stringstream sstr;
        sstr << i;
        std::string str1 = sstr.str();
        return str1;
    }
    std::string toStringSigned(int i)
    {
        std::stringstream sstr;
        sstr << i;
        std::string str1 = sstr.str();
        if(i > 0)
        {
            str1 = "+" + str1;
        }
        return str1;
    }
}
