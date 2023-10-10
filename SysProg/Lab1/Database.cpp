#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Database.hpp"
#include <map>


/*
 * Database.cpp
 * Written by Oleh Bielov
 */
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
        std::cout << "Shutting down..." << std::endl;
    }

    void Database :: updateEmployeesInfo(int inEmployeesId)
    {
        
        for(int i = 0; i < nextSlot; ++i){
			if(mEmployees[i]->getEmployeesId() == inEmployeesId &&
               mEmployees[i]->isHired()){
                int choice;
                cout << "What's the type of info would you like to update?" << endl;
                cout << "1. Employees ID" << endl;
                cout << "2. Employees fullname" << endl;
                cout << "3. Employees age" << endl;
                cout << "4. Employees gender" << endl;
                cout << "5. Employees address" << endl;
                cout << "6. Employees Classifier" << endl;
                cout << "7. Employees Passport Details" << endl;
                cout << "8. Promote employee" << endl;
                cout << "9. Dempote employee" << endl;

                cin >> choice;

                switch(choice){
                case 1:
                {
                    int newId;
                    cout << "Enter new employees ID: ";
                    while(!(cin >> newId) || newId <= 0){
        				cout << "Invalid ID. Please enter a positive number: ";
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
    				}
                    mEmployees[i]->setEmployeesId(newId);
                    break;
                }
                case 2:
                {
                    string newFullname;
                    cout << "Enter new employees fullname: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    	getline(cin, newFullname);
                    mEmployees[i]->setFirstAndLastName(newFullname);
                    break;
                }
                case 3:
                {
					int newAge;
                    cout << "Enter new employees age: ";
                    while(!(cin >> newAge) || newAge <= 0){
        				cout << "Invalid age. Please enter a positive number: ";
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
    				}
                    mEmployees[i]->setAge(newAge);
                    break;
                }
                case 4:
                {
                    string newGen;
                    cout << "Enter new employees gender: ";
                    cin >> newGen;
                    mEmployees[i]->setGender(newGen);
                    break;
                }
                case 5:
                {
                    string newAddr;
                    cout << "Enter new employees address: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    	getline(cin, newAddr);
                    mEmployees[i]->setAddress(newAddr);
                    break;
                }
                case 6:
                {
                    int role;
                    cout << "Enter new employees classifier: ";
                    role = findRole();
                    mEmployees[i]->setRole(role);
                    break;
                }
                case 7:
                {
                    long int pd;
                    cout << "Enter new employees passtort details: ";
                    while(!(cin >> pd) || pd <= 0){
        				cout << "Invalid passport id. Please enter a positive number: ";
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
    				}
                    mEmployees[i]->setPasspDetails(pd);
                    break;
                }
                case 8:
                {
                    int perc;
					cout << "Promote by percentage: ";
                    while(!(cin >> perc) || perc <= 0){
        			    cout << "Invalid age. Please enter a positive number: ";
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
    				}
                   
                    mEmployees[i]->promote(perc);
                    break;
                }
                case 9:
                {
					int perc;
					cout << "Demote by percentage: ";
                    while(!(cin >> perc) || perc <= 0){
        				cout << "Invalid age. Please enter a positive number: ";
        				cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
    				}
                    mEmployees[i]->demote(perc);
                    break;
                }
                default:
                {
                    cout << "Unknown selection" << std::endl;
					break;
                }
                }
            } else {
                    cout << "Unfortunately employee with id " << inEmployeesId << "is fired" << endl;
            	}
        }
    }

   Employee* Database :: addEmployee()
    {
		if(nextSlot >= kMaxEmployees){
            cerr << "There is no more room to add the new employee!" << endl;
			return nullptr;
            //throw runtime_error("no more space for employee");
        }

        Employee* theEmployee = readEmployeeDetails();
        mEmployees[nextSlot] = theEmployee;
        static int id = 1000;
        theEmployee->setEmployeesId(id++);

        
        nextSlot++;
        return theEmployee;
    }	

	long int Database::getPositiveNumber(const string &prompt) {
    	long int num;
    	do {
        	cout << prompt;
        	cin >> num;
        	if (!cin || num <= 0) {
            	cout << "Invalid input. Please enter a positive number: ";
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	}
    	} while (num <= 0);
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	return num;
	}

    
	Employee* Database::readEmployeeDetails()
    {
		string fullname, address, gender;
    	int age, sal, classifier;
    	long int pd;

		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	
        
		cout << "Enter employee's full name: ";
    	getline(cin, fullname);

    	cout << "Enter employee's address: ";
    	getline(cin, address);

    	cout << "Enter employee's gender: ";
    	getline(cin, gender);

    	age = getPositiveNumber("Enter employee's age: ");
    	sal = getPositiveNumber("Enter employee's salary: ");
        pd = getPositiveNumber("Enter employee's passprot details: ");
        
        classifier = findRole();
        
	    Employee* theEmployee = new Employee;        

	    theEmployee->setFirstAndLastName(fullname);
	    theEmployee->setAge(age);
 	    theEmployee->setSalary(sal);
        theEmployee->setGender(gender);
        theEmployee->setPasspDetails(pd);
        theEmployee->setAddress(address);
        theEmployee->setRole(classifier);
	    theEmployee->hire();
        
	    return theEmployee;	   
    }
    
    int Database :: findRole()
    {
        int choice;
        bool done = false;

        map<int, string> roles = {
        	{33, "Library Chief"},
        	{21, "Librarian"},
        	{724, "Editor"},
        	{8, "Director"},
        	{88, "Deputy Director"}
   		 };

    	cout << endl;
    	for(const auto& role : roles) {
        	cout << role.second << " has code \"" << role.first << "\"" << endl;
   		 }
		cout << "Enter the employee's role that you want to set from the list above." << endl;
    cout << "Role? ";
        while(!done){	        	
			cin >> choice;
        	if(roles.find(choice) != roles.end()) {
       		     done = true;
        	} else {
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	cout << "Invalid role. Please enter the number from the list." << endl;
        	}
        }
        return choice;
    }
    

    int Database::findIds()
    {
		int id;
        int colOne = 8;
        int colSec = 16;
        cout << setw(colOne) << left << "ID"
             << setw(colSec) << left << "Name" << endl;
		for(int i = 0; i < nextSlot; ++i){
            if(mEmployees[i]->isHired()){
            	cout << setw(colOne) << left
                     << mEmployees[i]->getEmployeesId();
     	        cout << setw(colSec) << left
                     << mEmployees[i]->getFirstAndLastName() << endl;
            }
        }

        cout << "Enter employees id that you want to update info" << endl;
        cin >> id;

        return id;
    }


	void Database::doFireEmployee(int inEmployeesId)
    {
	    for(int i = 0; i < nextSlot; ++i){
			if(mEmployees[i]->getEmployeesId() == inEmployeesId)
				mEmployees[i]->fire();
        }

    }

    void Database::listAllEmployees()
    {
        int colOne = 8;
        int colSec = 16;
        int colThird = 5;
        int colFourth = 8;
        int colFifth = 8;
        int colSix = 16;
        int colSev = 12;
        int colEight = 20; 
        int colNine = 6;
        cout << setw(colOne) << left << "ID"
             << setw(colSec) << left << "Name"
             << setw(colThird) << left << "Age"
             << setw(colFourth) << left << "Salary"
             << setw(colFifth) << left << "Gender"
             << setw(colSix) << left << "Address"
             << setw(colSev) << left << "Classifier"
             << setw(colEight) << left << "Passport details"
             << setw(colNine) << left << "Hired" << endl;
        
		for(int i = 0; i < nextSlot; ++i){
            cout << setw(colOne) << left << mEmployees[i]->getEmployeesId();
            cout << setw(colSec) << left <<mEmployees[i]->getFirstAndLastName();
            cout << setw(colThird) << left << mEmployees[i]->getAge();
            cout << setw(colFourth) << left << mEmployees[i]->getSalary();
            cout << setw(colFifth) << left << mEmployees[i]->getEmployeesGeneder();
            cout << setw(colSix) << left << mEmployees[i]->getEmployeesAddress();
            cout << setw(colSev) << left << mEmployees[i]->getEmployeesRole();
            cout << setw(colEight) << left << mEmployees[i]->getEmployeesPasspDetails();
            cout << setw(colNine) << left << mEmployees[i]->isHired() << endl;
        }

    }

}
