// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "Database.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addEmployee();
    void updateEmployee();
    void listEmployees();

private:
    Records::Database myDB;
    QTableWidget* table;
     int selectedEmployeeId;
};

#endif // MAINWINDOW_H
