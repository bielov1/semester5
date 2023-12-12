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

    void updateEmployeeField(int employeeId, int column, const QString &value);
    void addEmployee(const std::string& name,
                     int age, const std::string& address,
                     int salary, const std::string& gender,
                     long int passportDetails,
                     const std::string& role);
    void listAllEmployees(QTableWidget *table) ;
    void doFireEmployee(int inEmployeesId);
protected:
    Employee* mEmployees[kMaxEmployees];
    int nextSlot;
private:
    int lastEmployeeId;
};
}
#endif // _DATABASE_HPP
