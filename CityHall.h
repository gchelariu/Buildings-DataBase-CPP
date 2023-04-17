#include "Building.h"

struct CityHall: public Building
{
    CityHall (string name)
    {
        mBuildingName = name;
        mType = "CityHall";
        mCitizens.clear();
        mCoordinator = Person();
    }

    Building* operator + (const Person& persoana)
    {
        if (mCoordinator.mName == "" && mCoordinator.mAge == 0 && mCoordinator.mSalary == 0)
            mCoordinator = persoana;
        Building* primarie;
        primarie = this;
        return primarie;
    }

    Building* operator - ()
    {
        mCoordinator = Person();
        return this;
    }

    void add (const Person& persoana)
    {
        mCitizens.push_back(persoana);
    }

    void remove (const Person& persoana)
    {
        for(int i = 0; i < mCitizens.size() ; i++)
        {
            if(mCitizens[i] == persoana)
            {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
        }
    }
};
