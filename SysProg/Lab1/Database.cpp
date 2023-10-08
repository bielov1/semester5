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
							
            } else {
                std::cout << "Cannot find an employee with " << inEmployeesId << " id" <<  std::endl;
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
	    // You could add input validation here, e.g., age > 0

	    std::cout << "What's the salary? ";
	    std::cin >> sal;
	    // You could add input validation here too, e.g., salary >= 0

	    mEmployees[nextSlot] = new Employee();
	    Employee* theEmployee = mEmployees[nextSlot++];

	    theEmployee->setEmployeesId();
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

}
