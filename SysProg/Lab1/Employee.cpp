#include <iostream>

#include "Employee.hpp"

using namespace std;

namespace Records
{
    Employee::Employee()
    {
	    FirstAndLastName = "";
        EmployeesId = -1;
        Salary = 0;
        fHired = false;
    }
}
