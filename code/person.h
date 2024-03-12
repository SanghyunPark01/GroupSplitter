#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string _msName = "";
    bool _mbGender = true; // true: male, false: female
    int _mnGroup = -1;
public:
    Person(std::string name, bool gender)
    {
        _msName = name;
        _mbGender = gender;
    }
    void setGroup(int n);
    std::string getName(void);
    bool getGender(void);
    int getGroup(void);

};

#endif // PERSON_H
