#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

#include <iostream>

namespace Records
{
	class Employee
    {
    public: 
		Employee();

    #if 1
		void promote();
        void demote();
        void hire();
        void fire();
        void listEmployeesInfo();

        //Accessors and setters
        void setFirstAndLastName();
        std::string getFirstAndLastName();

        void setEmployeesId();
        int getEmployeesId();

        void setSalary();
        int getSalary();

        bool isHired();
        
    private:
        std::string FirstAndLastName;
        int EmployeesId;
        int Salary;
        bool fHired;
    #endif
    };
}

#endif // _EMPLOYEE_HPP
