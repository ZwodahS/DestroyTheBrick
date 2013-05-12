#ifndef _ZF_COMMON_F_CONVERSION_H_
#define _ZF_COMMON_F_CONVERSION_H_
#include <iostream>
#include <sstream>
#include <string>
namespace zf
{
    bool toInt(std::string str, int &value);
    std::string toString(int i);
    std::string toStringSigned(int i);
}
#endif
