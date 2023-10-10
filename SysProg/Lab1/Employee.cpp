#include <iostream>

#include "Employee.hpp"

using namespace std;

namespace Records
{
    
    Employee::Employee()
    {
	    FirstAndLastName = "";
        Address = "";
        Gender = "";
        age = -1;
        Salary = -1;
        EmployeesId = 1000;
        passpdetails = 0;
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

    void Employee :: setAge(int inSetAge)
    {
		age = inSetAge;
    }

    void Employee :: setGender(std::string gen)
    {
		Gender = gen;
    }

    void Employee :: setAddress(std::string addr)
    {
		Address = addr;
    }

    void Employee :: setRole(int role)
    {
		Role = role;
    }

    void Employee :: setPasspDetails(long int pd)
    {
		passpdetails = pd;
    }

    void Employee :: hire()
    {
		fHired = true;
    }

    void Employee :: fire()
    {
        
		fHired = false;
    }

    void Employee :: promote(int perc)
    {
        int curr = getSalary();
        int newSal = curr + curr*((double)perc/100);
        std::cout << newSal << std::endl;
	    setSalary(newSal); 
    }

    void Employee :: demote(int perc)
    {
   		int curr = getSalary();
        int newSal = curr - curr*((double)perc/100);
        std::cout << newSal << std::endl;
	    setSalary(newSal); 
        
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

    bool Employee :: isHired()
    {
		return fHired;
    }

    std::string Employee :: getEmployeesGeneder()
    {
		return Gender;
    }

    std::string Employee :: getEmployeesAddress()
    {
		return Address;
    }

    int Employee :: getEmployeesRole()
    {
		return Role;
    }

    long int Employee :: getEmployeesPasspDetails()
    {
		return passpdetails;
    }
}
