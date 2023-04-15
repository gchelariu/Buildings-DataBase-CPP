using namespace std;

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Building.h"

class Hospital: public Building
{
public:
    Hospital (string name)
    {
        mBuildingName = name;
        mType = "Hospital";
        mCitizens.clear();
        mEmployees.clear();
    }

    Building* operator + (const Person& persoana)
    {
        mEmployees.push_back(persoana);
        return this;
    }

    Building* operator - (const Person& persoana)
    {
        for (int i = 0 ; i < mEmployees.size(); i++)
            if(mEmployees[i] == persoana)
            {
                mEmployees.erase(mEmployees.begin() + i);
                break;
            }
        return this;
    }

    void add (const Person& persoana)
    {
        mCitizens.push_back(persoana);
    }

    void remove (const Person& persoana)
    {
        for (int i = 0 ; i < mCitizens.size(); i++)
            if(mCitizens[i] == persoana)
            {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
    }
};