#include "person.h"

void Person::setGroup(int n)
{
    _mnGroup = n;
}
std::string Person::getName(void)
{
    return _msName;
}
bool Person::getGender(void)
{
    return _mbGender;
}
int Person::getGroup(void)
{
    return _mnGroup;
}
