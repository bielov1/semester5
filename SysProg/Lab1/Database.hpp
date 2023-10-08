#ifndef _DATABASE_HPP
#define _DATABASE_HPP

#include <iostream>
#include "Employee.hpp"

namespace Records{
	class Database
	{
	    const static int kMaxEmployees = 10;
        const static int kFirstEmployeesNumber = 1000;
	public:
    	Database();
      	~Database();
		#if 0
        Employee& updateEmployeesInfo();
        Employee& addEmployee();
		#else
        void updateEmployeesInfo();
        void addEmployee();
        #endif
    protected:
        Employee mEmployees[kMaxEmployees];
        int nextEmployeesNumber;
        int nextSlot;
	};
}
#endif // _DATABASE_HPP
