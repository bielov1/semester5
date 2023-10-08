#include <iostream>

#include "Database.hpp"


using namespace std;
using namespace Records;
int displayMenu()
{
	int selection;

    cout << endl;
    cout << "Employee Database" << endl;
    cout << "|----------------|" << endl;
    cout << "1. Update employees info" << endl;
    cout << "2. List all employees" << endl;
    cout << "3. Hire a new employee"<< endl;
    cout << "4. Fire an employee" << endl;
    cout << "0. Quit" << endl;
    cout << endl;
    cout << "-->";

    cin >> selection;

    return selection;
}	


int main()
{
    Database myDB;
	bool done = false;

    while(!done){
		int selection = displayMenu();
        switch(selection){
        case 1:
            myDB.updateEmployeesInfo();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Unknown choice" << endl;
        }
        
    }
    return 0;
}	
