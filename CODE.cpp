#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "CityHall.h"
#include "Hospital.h"
#include "PoliceStation.h"
#include "House.h"
#include "Block.h"

int main()
{
    string comanda, deAdaugat;
    int nrCity = 0, nrHospital = 0, nrPolice = 0, nrHouse = 0, nrBlock = 0, nrPatients = 0;
    vector <Person> admin, blockAdmin, houseAdmin;
    double salaryDoc = 0, salaryCop = 0, salaryMayor = 0, salaryCity = 0 , avgPuscarie = 0;
    vector <Building *> retinDate;
    vector <uint16_t> maxLoc;
    while (cin >> comanda)
    {
        if(comanda == "add")
        {
            cin>>deAdaugat;

            if(deAdaugat == "CityHall")
            {
                string name;
                cin>> name;
                retinDate.push_back(new CityHall(name));
                nrCity++;
                //cout<<"plm"<<endl;
            }

            if(deAdaugat == "Hospital")
            {
                string name;
                cin>>name;
                retinDate.push_back(new Hospital(name));
                nrHospital++;
            }

            if(deAdaugat == "PoliceStation")
            {
                string name;
                cin>>name;
                retinDate.push_back(new PoliceStation(name));
                nrPolice++;
            }

            if(deAdaugat == "House")
            {
                string name; uint16_t nrMax;
                cin>>name>>nrMax;
                maxLoc.push_back(nrMax);
                retinDate.push_back(new House(name,nrMax));
                nrHouse++;
            }

            if(deAdaugat == "Block")
            {
                string name; uint16_t nrEtaje, nrMax;
                cin>>name>>nrEtaje>>nrMax;
                retinDate.push_back(new Block(name, nrEtaje, nrMax));
                nrBlock++;
            }

            if(deAdaugat == "coordinator")
            {
                string name, buildingName;
                uint16_t age;
                double salary;
                cin>>name>>age>>salary>>buildingName;
                Person persoanaCurenta(name,age,salary);
                for(int i = 0 ; i < retinDate.size() ; i++)
                {
                    if(buildingName == retinDate[i]->getBuildingName())
                    {
                        retinDate[i] = *retinDate[i] + persoanaCurenta;
                    }
                }
            }

            if(deAdaugat == "employee")
            {
                string name, buildingName;
                uint16_t age;
                double salary;
                cin>>name>>age>>salary>>buildingName;
                Person persoanaCurenta(name,age,salary);
                for(int i = 0 ; i < retinDate.size(); i++)
                {
                    if(buildingName == retinDate[i]->getBuildingName())
                    {
                        retinDate[i] = *retinDate[i] + persoanaCurenta;
                    }
                }
            }

            if(deAdaugat == "citizen")
            {
                string name, buildingName;
                uint16_t age;
                double salary;
                cin>>name>>age>>salary>>buildingName;
                Person persoanaCurenta(name,age,salary);
                for(int i = 0 ; i < retinDate.size() ; i++)
                {
                    if(buildingName == retinDate[i]->getBuildingName())
                    {
                        retinDate[i]->add(persoanaCurenta);
                    }
                }
            }
        }

        if(comanda == "remove")
        {
            cin>>deAdaugat;
            string name, buildingName;
            cin>>name>>buildingName;
            for(int i = 0 ; i < retinDate.size() ; i++)
            {
                if(retinDate[i]->getBuildingName() == buildingName)
                {
                    if(deAdaugat == "employee")
                    {
                        for(int j = 0 ; j < retinDate[i]->getEmployeesSize(); j++)
                        {
                            if(name == retinDate[i] -> getEmployee(j).mName)
                                retinDate[i] = *retinDate[i] - retinDate[i]->getEmployee(j);
                        }
                    }

                    if(deAdaugat == "citizen")
                    {
                        for(int j = 0 ; j < retinDate[i]->getCitizensSize() ; j++)
                        {
                            if(name == retinDate[i]->getCitizen(j).mName)
                                retinDate[i]->remove(retinDate[i]->getCitizen(j));
                        }
                    }

                    if(deAdaugat == "coordinator")
                    {
                        retinDate[i] = -*retinDate[i];
                    }
                }
            }
        }
    }

    // for (int i = 0 ; i < retinDate.size(); i++)
    //         cout<<retinDate[i]->getBuildingName()<<" "<<retinDate[i]->getType()<<endl;

    if(nrCity>=3 && nrHospital>=2 && nrPolice>=3 && nrHouse >=8 && nrBlock >= 4)
    {
        cout<<"Type: Capital"<<endl;
    }
    else
    {
        if(nrCity >= 2 && nrHospital >= 1 && nrPolice >= 2 && nrHouse >= 4 && nrBlock >=1)
            cout<<"Type: Town"<<endl;
        else
            cout<<"Type: Village"<<endl;
    }

    double nrDoc = 0 , nrCop = 0, nrMayors = 0, nrHallEmp = 0, nrPuscarie = 0;

    for(int i = 0 ; i < retinDate.size() ; i++)
    {
        if(retinDate[i]->getType() == "Hospital")
        {
            nrPatients += retinDate[i]->getCitizensSize();
            nrDoc += retinDate[i] -> getEmployeesSize();
            for(int j = 0 ; j < retinDate[i]->getEmployeesSize() ; j++)
            {
                salaryDoc += retinDate[i]->getEmployee(j).mSalary;
            }
        }

        if(retinDate[i]->getType() == "PoliceStation")
        {
            nrPuscarie += retinDate[i]->getCitizensSize();
            nrCop += retinDate[i] ->getEmployeesSize();
            for(int j = 0 ; j < retinDate[i]->getEmployeesSize() ; j++)
            {
                salaryCop += retinDate[i]->getEmployee(j).mSalary;
            }
            for(int j = 0 ; j < retinDate[i]->getCitizensSize() ; j++)
            {
                avgPuscarie += retinDate[i]->getCitizen(j).mAge;
            }
        }

        if(retinDate[i]->getType() == "CityHall")
        {
            if(retinDate[i]->getCoordinator().mName != "")
                nrMayors++;
            nrHallEmp += retinDate[i]->getCitizensSize();
            salaryMayor += retinDate[i]->getCoordinator().mSalary;
            for(int j = 0 ; j < retinDate[i]->getCitizensSize() ; j++)
            {
                salaryCity += retinDate[i]->getCitizen(j).mSalary;
            }
        }
    }

    
    cout << "Number of patients in hospitals: " <<nrPatients<< endl;
    if (salaryDoc == 0) 
        cout << "Average salary for doctors: 0" <<endl;
    else 
        cout << "Average salary for doctors: " << salaryDoc /  nrDoc<<endl;
    if (salaryCop == 0) 
        cout << "Average salary for cops: 0" << endl;
    else 
        cout << "Average salary for cops: " << salaryCop / nrCop << endl;
    if 
        (salaryMayor == 0) cout << "Average salary for mayors: 0" << endl;
    else 
        cout << "Average salary for mayors: " << salaryMayor /  nrMayors << endl;
    if 
        (salaryCity == 0) cout << "Average salary for city hall employees: 0" << endl;
    else 
        cout << "Average salary for city hall employees: " << salaryCity / nrHallEmp<<endl;
    if 
        (avgPuscarie == 0) cout << "Average age of busted in police stations: 0" << endl;
    else 
        cout << "Average age of busted in police stations: " <<  avgPuscarie / nrPuscarie << endl;

    for(int i = 0 ; i < retinDate.size() ; i++)
    {
        // cout<<retinDate[i]->getBuildingName()<<" "<<retinDate[i]->getType()<<endl;
        if(retinDate[i]->getType() == "House")
        {
            if(retinDate[i]->getCitizensSize() + 1 <= maxLoc[0])
            {
                if(retinDate[i]->getCoordinator().mName == ""){
                cout<<"Number of people in House "<<retinDate[i]->getBuildingName()<<": "<<retinDate[i]->getCitizensSize() <<endl;
                }
                else
                {
                    houseAdmin.push_back(retinDate[i]->getCoordinator());
                    cout<<"Number of people in House "<<retinDate[i]->getBuildingName()<<": "<<retinDate[i]->getCitizensSize() + 1 <<endl;
                }
                maxLoc.erase(maxLoc.begin());
            }
            else{
                cout<<"Number of people in House "<<retinDate[i]->getBuildingName() <<": "<< maxLoc[0]<<endl;
                maxLoc.erase(maxLoc.begin());
            }
        }
        else
        {
            
            if(retinDate[i]->getType() == "Block")
            {
                int nrLoc = 0;
                if(retinDate[i]->getCoordinator().mName != ""){
                    blockAdmin.push_back(retinDate[i]->getCoordinator());
                    nrLoc++;
                }
                for(int j = 0 ; j < retinDate[i]->getCitizensSize() ; j++)
                {
                    if(retinDate[i]->getCitizen(j) == Person())
                     break;
                    else
                     nrLoc++;
                }
                cout<<"Number of people in Block "<<retinDate[i]->getBuildingName()<<": "<<nrLoc<<endl;
            }
        }
    }

    for(int i = 0; i < houseAdmin.size(); i++)
    {
        for(int j = 0 ; j < blockAdmin.size(); j++)
            if(houseAdmin[i].mName == blockAdmin[j].mName)
                admin.push_back(houseAdmin[i]);
    }

    cout<<"Administrators of house and block: ";
    if(admin.size() == 0)
        cout<<"Nobody"<<endl;
    else{
        for(int i = 0 ; i < admin.size() ; i++)
            cout<<admin[i].mName<<" ";
        cout<<endl;
    }
} 
