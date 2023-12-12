#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <QMessageBox>
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


void Database::updateEmployeeId(int employeeId, int id) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setEmployeesId(id);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeeAge(int employeeId, int newAge) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setAge(newAge);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeeSalary(int employeeId, int salary) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setSalary(salary);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeeGender(int employeeId, const std::string& gender) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setGender(gender);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeeName(int employeeId, const std::string& newName) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setFirstAndLastName(newName);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeeAddress(int employeeId, const std::string& address) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setAddress(address);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeeRole(int employeeId, const std::string& role) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setRole(role);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::updateEmployeePD(int employeeId, int pd) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            mEmployees[i]->setPasspDetails(pd);
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
}

void Database::isEmployeed(int employeeId, int hire) {
    for (int i = 0; i < nextSlot; ++i) {
        if (mEmployees[i]->getEmployeesId() == employeeId) {
            if(hire == 1) {
                    mEmployees[i]->hire();
            } else if (hire == 0) {
                mEmployees[i]->fire();
            } else {
                std::cerr << "Please select a cell to update." << std::endl;
            }
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeId << " not found." << std::endl;
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

    for(int i = 0; i < nextSlot; i++) {
        if(mEmployees[i]->getEmployeesId() > lastEmployeeId) {
            lastEmployeeId = mEmployees[i]->getEmployeesId();
        }
    }

    int newEmployeeId = lastEmployeeId + 1;
    newEmployee->setEmployeesId(newEmployeeId);

    mEmployees[nextSlot++] = newEmployee;
}


void Database::listAllEmployees(QTableWidget *table) {
    table->setRowCount(0);
    table->setColumnCount(9);
    table->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "Age" << "Salary"
                                                   << "Gender" << "Address" << "Classifier"
                                                   << "Passport details" << "Hired");

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
