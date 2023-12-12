// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextEdit>
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
    void saveFile();

private:
    Records::Database myDB;
    QTableWidget* table;
    QTextEdit *textEdit;
     int selectedEmployeeId;
};

#endif // MAINWINDOW_H
