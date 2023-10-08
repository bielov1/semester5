#include <iostream>

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

    void Database :: updateEmployeesInfo()
    {
        //Employee& theEmployee = mEmployees[kFirstEmployeesNumber++];
        //return theEmployee;
    }

    void Database :: addEmployee()
    {
		if(nextSlot >= kMaxEmployees){
            std::cerr << "There is no more room to add the new employee!" << std::endl;
            throw std::runtime_error("no more space for employee");
        }

        Employee& theEmployee = mEmployees[nextSlot++];
        
    }

}
