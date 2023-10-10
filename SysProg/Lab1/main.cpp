//Систене програмування. ЛР1 "Технології розробки системних програм для POSIX ОС"
//
//Варіант №1 Інформаційна система Бібліотеки.
//Клас
//Працівники (Код співробітника, ПІБ, Вік, Стать, Адреса, Паспортні дані,
// Код посади)[10 запитів]
//Передбачити функціональність додавання інформації, вивід інформації на консоль
//Передбачити фкнціональність поведінки класу, в залежності від значення певних членів класу
//Під час тестування на етапі виконання створити екземпляр класу на купі пам'яті і на стеку
//
//Бєлов Олег Данилович, IO-11, 10.10.2023
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
    cout << "5. Autofill" << endl;
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
        int emId;
        switch(selection){
        case 1:
			emId = myDB.findIds();
            myDB.updateEmployeesInfo(emId);
            break;
        case 2:
            myDB.listAllEmployees();
            break;
        case 3:
            myDB.addEmployee();
            break;
        case 4:
            emId = myDB.findIds();
            myDB.doFireEmployee(emId);
            break;
        case 5:
            myDB.useExistingData();
            break;
        case 0:
            done = true;
            break;
        default:
            cout << "Unknown choice" << endl;
        }
        
    }
    return 0;
}	
