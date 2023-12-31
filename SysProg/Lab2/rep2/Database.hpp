#ifndef _DATABASE_HPP
#define _DATABASE_HPP


#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Employee.hpp"

/*
 * Database.hpp
 * Written by Oleh Bielov
 */
namespace Records{
	class Database
	{
	    const static int kMaxEmployees = 50;
	public:
    	Database();
      	~Database();
        
        void updateEmployeesInfo(int inEmployeesId);
        Employee* addEmployee();
        int findIds();
        void listAllEmployees();
        int findRole();
        void doFireEmployee(int inEmployeesId);
        Employee* readEmployeeDetails();
        int long getPositiveNumber(const std::string &prompt);
        void  useExistingData();
    protected:
        Employee* mEmployees[kMaxEmployees];
        int classifiers[5];
        int nextSlot;
	};
}
#endif // _DATABASE_HPP
