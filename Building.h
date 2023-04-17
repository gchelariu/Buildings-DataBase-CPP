#ifndef BUILDING_H
#define BUILDING_H

#include "Person.h"

class Building
{
protected:
    string mBuildingName, mType;
    Person mCoordinator;
    vector <Person> mEmployees, mCitizens;

public:
    Building (string buidilngNmae, string type)
    {
        mBuildingName =buidilngNmae;
        mType = type;
    } 

    Building()
    {

    }

    virtual void add(const Person& persoana) = 0;
    virtual void remove(const Person& persoana) = 0;
    virtual Building* operator + (const Person& persoana) = 0;
    
    virtual Building* operator - ()
    {
        return nullptr;
    }

    virtual Building* operator - (const Person& persoana)
    {
        return nullptr;
    }

    string getBuildingName () const
    {
        return mBuildingName;
    }

    string getType () const
    {
        return mType;
    }

    uint16_t getEmployeesSize() const
    {
        return mEmployees.size();
    }

    uint16_t getCitizensSize() const
    {
        return mCitizens.size();
    }

    Person getEmployee (uint16_t index) const
    {
        return mEmployees[index];
    }

    Person getCitizen (uint16_t index) const
    {
        return mCitizens[index];
    }

    Person getCoordinator () const
    {
        return mCoordinator;
    }
};

#endif
