using namespace std;

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Building.h"

class Block: public Building
{
    uint16_t mMaxNumberPerFloor;

public:
    Block(string name, uint16_t nrEtaje, uint16_t nrMax)
    {
        mBuildingName = name;
        mType = "Block";
        mMaxNumberPerFloor = nrMax;
        mCitizens.clear();
        mCoordinator = Person();
        for (int i = 0 ; i < nrEtaje * mMaxNumberPerFloor ; i++)
            mCitizens.push_back(Person());
    }

    Building* operator + (const Person& persoana)
    {
        if(mCoordinator.mAge == 0 && mCoordinator.mSalary == 0 && mCoordinator.mName == "")
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
        for(int i = 0 ; i < mCitizens.size() ; i++)
            if(mCitizens[i] == Person())
            {
                mCitizens[i] = persoana;
                break;
            }
    }

    void remove (const Person& persoana)
    {
        if(persoana.mAge >= 18)
            for (int i = 0 ; i < mCitizens.size() ; i++)
            {
                if(mCitizens[i] == persoana)
                {
                    mCitizens[i] = Person();
                    break;
                }   
            }
    }

};