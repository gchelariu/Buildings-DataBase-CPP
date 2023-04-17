#include "Building.h"

class PoliceStation: public Building
{
public:
    PoliceStation(string name)
    {
        mBuildingName = name;
        mType = "PoliceStation";
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
