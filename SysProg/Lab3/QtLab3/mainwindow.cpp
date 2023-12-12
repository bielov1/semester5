#include "mainwindow.h"
#include "Database.hpp"
#include <QtWidgets>
#include <QTableWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), myDB() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    table = new QTableWidget(this);
    table->setColumnCount(9);
    table->setHorizontalHeaderLabels(QStringList() << "ID"
                                                                                                   << "Name"
                                                                                                   << "Age"
                                                                                                   << "Salary"
                                                                                                   << "Gender"
                                                                                                   << "Address"
                                                                                                   << "Classifier"
                                                                                                   <<"PassportDetails"
                                                                                                   << "Role");
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(table);
    this->table = table;



    QPushButton *addButton = new QPushButton("Add Employee", centralWidget);
    QPushButton *updateButton = new QPushButton("Update Employee", centralWidget);
    QPushButton *listButton = new QPushButton("List Employees", centralWidget);
    layout->addWidget(addButton);
    layout->addWidget(updateButton);
    layout->addWidget(listButton);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addEmployee);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::updateEmployee);
    connect(listButton, &QPushButton::clicked, this, &MainWindow::listEmployees);


    setCentralWidget(centralWidget);
    resize(950, 400);
}

MainWindow::~MainWindow() {
    // Деструктор
}

void MainWindow::addEmployee() {
    QDialog dialog(this);
    QFormLayout form(&dialog);

    QLineEdit *nameLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Name:"), nameLineEdit);

    QLineEdit *ageLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Age:"), ageLineEdit);

    QLineEdit *genderLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Gender:"), genderLineEdit);

    QLineEdit *addressLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Address:"), addressLineEdit);

    QLineEdit *salaryLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Salary:"), salaryLineEdit);

    QLineEdit *passportDetailsLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Passport Details:"), passportDetailsLineEdit);

    QLineEdit *roleLineEdit = new QLineEdit(&dialog);
    form.addRow(new QLabel("Role:"), roleLineEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);


    if (dialog.exec() == QDialog::Accepted) {
        std::string name = nameLineEdit->text().toStdString();
        int age = ageLineEdit->text().toInt();
        std::string address = addressLineEdit->text().toStdString();
        int salary = salaryLineEdit->text().toInt();
        std::string gender = genderLineEdit->text().toStdString();
        long int passportDetails = passportDetailsLineEdit->text().toInt();
        std::string role = roleLineEdit->text().toStdString();

        myDB.addEmployee(name, age, address, salary, gender, passportDetails, role);
    }
}


void MainWindow::updateEmployee() {

}

void MainWindow::listEmployees() {
    myDB.listAllEmployees(table);
}
