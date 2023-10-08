#include <iostream>

#include "Employee.hpp"

using namespace std;

namespace Records
{
    
    Employee::Employee()
    {
	    FirstAndLastName = "";
        age = -1;
        Salary = -1;
        EmployeesId = 1000;
        fHired = false;
    }

    void Employee :: setEmployeesId(int eId)
    {
		EmployeesId = eId;
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

    int Employee :: getAge()
    {
		return age;
    }

    int Employee :: getSalary()
    {
		return Salary;
    }
}
