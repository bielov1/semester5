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
        void setFirstAndLastName(std::string name);
        std::string getFirstAndLastName();

        void setEmployeesId();
        int getEmployeesId();

        void setSalary(int inSetSalary);
        int getSalary();

        bool isHired();

        void setAge(int inSetAge);
        int getAge();
        
    private:
        std::string FirstAndLastName;
        int EmployeesId;
        int age;
        int Salary;
        bool fHired;
    #endif
    };
}

#endif // _EMPLOYEE_HPP
