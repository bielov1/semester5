#include <iostream>

#include "Employee.hpp"

using namespace std;

namespace Records
{
    
    Employee::Employee()
    {
	    FirstAndLastName = "";
        age = 0;
        Salary = 0;
        EmployeesId = 1000;
        fHired = false;
    }

    void Employee :: setEmployeesId()
    {
		EmployeesId += 1;
    }

    void Employee :: setFirstAndLastName(std::string name)
    {
		FirstAndLastName = name;
    }

    void Employee :: setSalary(int inSetSalary)
    {
		Salary = inSetSalary;
    }

    void Employee :: hire()
    {
		fHired = true;
    }

    void Employee :: setAge(int inSetAge)
    {
		age = inSetAge;
    }

    // Accessors

    int Employee :: getEmployeesId()
    {		
		return EmployeesId;
    }

    std::string Employee :: getFirstAndLastName()
    {
		return FirstAndLastName;
    }
}
