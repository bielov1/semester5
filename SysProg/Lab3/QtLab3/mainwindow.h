// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
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
    // Other private members if needed
};

#endif // MAINWINDOW_H
