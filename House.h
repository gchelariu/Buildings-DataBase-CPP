#include "Building.h"


class House: public Building
{
    uint16_t mMaxNumber;

public:
    House(string name, uint16_t maxnr)
    {
        mBuildingName = name;
        mMaxNumber = maxnr;
        mType = "House";
        mCitizens.clear();
        mCoordinator = Person();
    }

    Building* operator + (const Person& persoana)
    {
        if(mCoordinator.mAge == 0 && mCoordinator.mName == "" && mCoordinator.mSalary == 0)
            mCoordinator = persoana;
        return this;
    }

    Building* operator - ()
    {
        mCoordinator = Person();
        return this;
    }

    void add (const Person& persoana)
    {
        if(mCitizens.size() < mMaxNumber)
            mCitizens.push_back(persoana);
    }

    void remove (const Person& persoana)
    {
        if(persoana.mAge >= 18)
            for (int i = 0 ; i < mCitizens.size() ; i++)
            {
                if(mCitizens[i] == persoana)
                {
                    mCitizens.erase(mCitizens.begin() + i);
                    break;
                }   
            }
    }

    uint16_t getMax()
    {
        return mMaxNumber;
    }
};
