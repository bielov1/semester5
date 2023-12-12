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

    void addEmployee(const std::string& name,
                     int age, const std::string& address,
                     int salary, const std::string& gender,
                     long int passportDetails,
                     const std::string& role);
    void listAllEmployees(QTableWidget *table) ;
    void updateEmployeeId(int employeeId, int id);
    void updateEmployeeAge(int employeeId, int newAge);
    void updateEmployeeName(int employeeId, const std::string& newName);
    void updateEmployeeSalary(int employeeId, int salary);
    void updateEmployeeGender(int employeeId, const std::string& gender);
    void updateEmployeeAddress(int employeeId, const std::string& address);
    void updateEmployeeRole(int employeeId, const std::string& role);
    void updateEmployeePD(int employeeId, int pd);
    void isEmployeed(int employeeId, int hire);

protected:
    Employee* mEmployees[kMaxEmployees];
    int nextSlot;
private:
    int lastEmployeeId;
};
}
#endif // _DATABASE_HPP
