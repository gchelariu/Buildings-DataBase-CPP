#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Person
{
   string mName;
   uint16_t mAge;
   double mSalary;

   Person()
   {
       mAge = 0 ;
       mSalary = 0;
       mName = "";
   } 

   Person(string name, uint16_t age, double salary)
   {
       mName = name;
       mAge = age;
       mSalary = salary;
   }

   bool operator == (const Person& persoana) const 
   {
        if(this -> mName == persoana.mName && this->mAge == persoana.mAge && this->mSalary == persoana.mSalary)
            return true;
        return false;
   }

   bool operator < (const Person& persoana) const
   {
        if(this->mName < persoana.mName)
            return true;
        return false;
   }
};

#endif