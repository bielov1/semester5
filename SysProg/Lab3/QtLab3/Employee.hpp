#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

#include <iostream>
#include <QTableWidget>
/*
 * Employee.hpp
 * Written by Oleh Bielov
 */
namespace Records
{
class Employee
{
public:
    Employee();


    void promote(int perc);
    void demote(int perc);
    void hire();
    void fire();
    void listEmployeesInfo();

    //Accessors and setters
    void setFirstAndLastName(std::string name);
    std::string getFirstAndLastName();

    void setEmployeesId(int eId);
    int getEmployeesId();

    void setSalary(int inSetSalary);
    int getSalary();

    bool isHired();

    void setAge(int inSetAge);
    int getAge();

    void setGender(std::string gen);
    std::string getEmployeesGeneder();

    void setAddress(std::string addr);
    std::string getEmployeesAddress();

    void setRole(std::string role);
    std::string getEmployeesRole();

    void setPasspDetails(long int pd);
    long int getEmployeesPasspDetails();

private:
    std::string FirstAndLastName;
    std::string Address;
    std::string Gender;
    std::string Role;
    int EmployeesId;
    int age;
    int Salary;
    long int passpdetails;
    bool fHired;
};
}

#endif // _EMPLOYEE_HPP
