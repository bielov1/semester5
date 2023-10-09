#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Database.hpp"

using namespace std;

namespace Records
{
    int nextEmployeesNumber;
    int nextSlot;
    Database::Database()
    {
        
        nextEmployeesNumber = kFirstEmployeesNumber;
        nextSlot = 0;
    }

    Database::~Database()
    {
        std::cout << "Shutting down" << std::endl;
    }

    void Database :: updateEmployeesInfo(int inEmployeesId)
    {
        
        for(int i = 0; i < nextSlot; ++i){
			if(mEmployees[i]->getEmployeesId() == inEmployeesId){
                int choice;
                cout << "What's the type of info would you like to update?" << endl;
                cout << "1. Employees ID" << endl;
                cout << "2. Employees fullname" << endl;
                cout << "3. Employees age" << endl;
                cout << "4. Promote employee" << endl;
                cout << "5. Dempote employee" << endl;

                cin >> choice;

                switch(choice){
                case 1:
                {
                    int newId;
                    cout << "Enter new employees ID: ";
                    cin >> newId;
                    mEmployees[i]->setEmployeesId(newId);
                    break;
                }
                case 2:
                    {
                    string newFullname;
                    cout << "Enter new employees fullname: ";
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			    	getline(std::cin, newFullname);
                    mEmployees[i]->setFirstAndLastName(newFullname);
                    break;
                    }
                case 3:
                    {
					int newAge;
                    cout << "Enter new employees age: ";
                    cin >> newAge;
                    mEmployees[i]->setAge(newAge);
                    break;
                    }
                case 4:
                    {
                    int perc;
					cout << "Promote by percentage: ";
                    cin >> perc;
                    mEmployees[i]->promote(perc);
                    break;
                    }
                case 5:
                    {
					int perc;
					cout << "Demote by percentage: ";
                    cin >> perc;
                    mEmployees[i]->demote(perc);
                    break;
                    }
                default:
                    cout << "Unknown selection" << std::endl;
					break;
                }
            }
        }
    }

   Employee* Database :: addEmployee()
    {
		if(nextSlot >= kMaxEmployees){
            cerr << "There is no more room to add the new employee!" << endl;
			return {};
            //throw runtime_error("no more space for employee");
        }

        string fullname;
		int age;
    	int sal;

    	cout << "Enter fullname: ";
    	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	getline(std::cin, fullname);

	    cout << "Employee's age? ";
   		cin >> age;

	    cout << "What's the salary? ";
	    cin >> sal;
	   

	    mEmployees[nextSlot] = new Employee();
	    Employee* theEmployee = mEmployees[nextSlot++];

		static int id = 1000;
        
	    theEmployee->setEmployeesId(id++);
	    theEmployee->setFirstAndLastName(fullname);
	    theEmployee->setAge(age);
 	    theEmployee->setSalary(sal);
	    theEmployee->hire();

	    return theEmployee;		
    }

    int Database :: findIds()
    {
		int id;
        int colOne = 8;
        int colSec = 16;
        cout << setw(colOne) << left << "ID"
             << setw(colSec) << left << "Name" << endl;
		for(int i = 0; i < nextSlot; ++i){
            cout << setw(colOne) << left << mEmployees[i]->getEmployeesId();
            cout << setw(colSec) << left << mEmployees[i]->getFirstAndLastName() << endl;         
        }

        cout << "Enter employees id that you want to update info" << endl;
        cin >> id;

        return id;
    }


	void Database :: doFireEmployee(int inEmployeesId)
    {
	    for(int i = 0; i < nextSlot; ++i){
			if(mEmployees[i]->getEmployeesId() == inEmployeesId)
				mEmployees[i]->fire();
        }

    }
    
    void Database :: listAllEmployees()
    {
        int colOne = 8;
        int colSec = 16;
        int colThird = 5;
        int colFourth = 8;
        int colFifth = 6;
        cout << setw(colOne) << left << "ID"
                  << setw(colSec) << left << "Name"
            	  << setw(colThird) << left << "Age"
            	  << setw(colFourth) << left << "Salary"
            	  << setw(colFifth) << left << "Hired" << endl;
        
		for(int i = 0; i < nextSlot; ++i){
            cout << setw(colOne) << left << mEmployees[i]->getEmployeesId();
            cout << setw(colSec) << left <<mEmployees[i]->getFirstAndLastName();
            cout << setw(colThird) << left << mEmployees[i]->getAge();
            cout << setw(colFourth) << left << mEmployees[i]->getSalary();
            cout << setw(colFifth) << left << mEmployees[i]->isHired() << endl;
        }

    }

}
