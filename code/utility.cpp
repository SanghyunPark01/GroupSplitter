#include "utility.h"
#include <iostream>
bool checkValidNumber(std::string s_)
{
    if(s_ == "-1")return true;

    for(int i = 0; i < s_.size(); i++)
    {
        if(s_[i] != '0' && s_[i] != '1' && s_[i] != '2' && s_[i] != '3'
                && s_[i] != '4' && s_[i] != '5' && s_[i] != '6'
                && s_[i] != '7' && s_[i] != '8' && s_[i] != '9')return false;
    }
    return true;
}

