#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Database.hpp"
#include <map>


/*
 * Database.cpp
 * Written by Oleh Bielov
 */
using namespace std;
namespace Records
{
int nextSlot;
Database::Database()
{
    lastEmployeeId = 1000;
    nextSlot = 0;
}

Database::~Database()
{
    std::cout << "Shutting down..." << std::endl;
}

void Database::updateEmployeeField(int employeeId, int column, const QString &value) {


}
void Database::addEmployee(const std::string& name, int age, const std::string& address, int salary, const std::string& gender, long int passportDetails, const std::string& role) {
    if (nextSlot >= kMaxEmployees) {
        cerr << "There is no more room to add the new employee!" << endl;
        return;
    }

    Employee* newEmployee = new Employee;
    newEmployee->setFirstAndLastName(name);
    newEmployee->setAge(age);
    newEmployee->setAddress(address);
    newEmployee->setSalary(salary);
    newEmployee->setGender(gender);
    newEmployee->setPasspDetails(passportDetails);
    newEmployee->setRole(role);
    newEmployee->hire();

    int newEmployeeId = ++lastEmployeeId;
    newEmployee->setEmployeesId(newEmployeeId);

    mEmployees[nextSlot++] = newEmployee;
}



void Database::doFireEmployee(int inEmployeesId)
{
    for(int i = 0; i < nextSlot; ++i){
        if(mEmployees[i]->getEmployeesId() == inEmployeesId)
            mEmployees[i]->fire();
    }

}

void Database::listAllEmployees(QTableWidget *table) {
    // Clear the table before populating it
    table->setRowCount(0);


    // Set table headers
    table->setColumnCount(9);
    table->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "Age" << "Salary"
                                                   << "Gender" << "Address" << "Classifier"
                                                   << "Passport details" << "Hired");

    // Loop through employees and add data to the table
    for (int i = 0; i < nextSlot; ++i) {
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(QString::number(mEmployees[i]->getEmployeesId())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(mEmployees[i]->getFirstAndLastName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(mEmployees[i]->getAge())));
        table->setItem(i, 3, new QTableWidgetItem(QString::number(mEmployees[i]->getSalary())));
        table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(mEmployees[i]->getEmployeesGeneder())));
        table->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(mEmployees[i]->getEmployeesAddress())));
        table->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(mEmployees[i]->getEmployeesRole())));
        table->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(std::to_string(mEmployees[i]->getEmployeesPasspDetails()))));
        table->setItem(i, 8, new QTableWidgetItem(QString::number(mEmployees[i]->isHired())));
    }
}

}
