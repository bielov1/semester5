#include <iostream>
#include <string>
#include <limits>
#include "Database.hpp"
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
                std::cout << "What's the type of info would you like to update?" << std::endl;
                std::cout << "1. Employees ID" << std::endl;
                std::cout << "2. Employees fullname" << std::endl;
                std::cout << "3. Employees age" << std::endl;

                std::cin >> choice;

                switch(choice){
                case 1:
                {
                    int newId;
                    std::cout << "Enter new employees ID: ";
                    std::cin >> newId;
                    mEmployees[i]->setEmployeesId(newId);
                    break;
                }
                case 2:
                    {
                    std::string newFullname;
                    std::cout << "Enter new employees fullname: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			    	std::getline(std::cin, newFullname);
                    mEmployees[i]->setFirstAndLastName(newFullname);
                    break;
                    }
                case 3:
                    {
					int newAge;
                    std::cout << "Enter new employees age: ";
                    std::cin >> newAge;
                    mEmployees[i]->setAge(newAge);
                    break;
                    }
                default:
                    std::cout << "Unknown selection" << std::endl;
					updateEmployeesInfo(inEmployeesId);
                }
            }
        }
    }

   Employee* Database :: addEmployee()
    {
		if(nextSlot >= kMaxEmployees){
            std::cerr << "There is no more room to add the new employee!" << std::endl;
            throw std::runtime_error("no more space for employee");
        }

        std::string fullname;
		int age;
    	int sal;

    	std::cout << "Enter fullname: ";
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	std::getline(std::cin, fullname);

	    std::cout << "Employee's age? ";
   		 std::cin >> age;

	    std::cout << "What's the salary? ";
	    std::cin >> sal;
	   

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
        std::cout << "  ID    Name" << std::endl;
		for(int i = 0; i < nextSlot; ++i){
            std::cout << mEmployees[i]->getEmployeesId() << "   " << mEmployees[i]->getFirstAndLastName() << std::endl;         
        }

        std::cout << "Enter employees id that you want to update info" << std::endl;
        std::cin >> id;

        return id;
    }

    void Database :: listAllEmployees()
    {
		std::cout << "  ID        Name         Age     Salary" << std::endl;
		for(int i = 0; i < nextSlot; ++i){
            std::cout << "\n";
            std::cout << mEmployees[i]->getEmployeesId() << "  ";
            std::cout << mEmployees[i]->getFirstAndLastName() << "  ";
            std::cout << mEmployees[i]->getAge() << "  ";
            std::cout << mEmployees[i]->getSalary() << "  ";
            std::cout << "\n";
        }

    }

}
