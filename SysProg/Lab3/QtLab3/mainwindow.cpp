#include "mainwindow.h"
#include "Database.hpp"
#include <QtWidgets>
#include <QTableWidget>
#include <QFileDialog>


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
    table->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::AnyKeyPressed);
    layout->addWidget(table);
    this->table = table;


    QPushButton *addButton = new QPushButton("Add Employee", centralWidget);
    QPushButton *updateButton = new QPushButton("Update Employee", centralWidget);
    QPushButton *listButton = new QPushButton("List Employees", centralWidget);
    QPushButton *saveButton = new QPushButton("Save File", this);


    layout->addWidget(addButton);
    layout->addWidget(updateButton);
    layout->addWidget(listButton);
    layout->addWidget(saveButton);


    connect(addButton, &QPushButton::clicked, this, &MainWindow::addEmployee);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::updateEmployee);
    connect(listButton, &QPushButton::clicked, this, &MainWindow::listEmployees);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveFile);


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
    QTableWidgetItem *selectedItem = table->selectedItems().isEmpty() ? nullptr : table->selectedItems().first();

    if (selectedItem) {
        int employeeId = table->item(selectedItem->row(), 0)->text().toInt();
        int column = selectedItem->column();

        bool ok;
        QString newText = QInputDialog::getText(this, tr("Update Employee"),
                                                tr("Enter new value:"), QLineEdit::Normal,
                                                selectedItem->text(), &ok);
        if (ok && !newText.isEmpty()) {
            switch (column) {
            case 0: // Айді
                myDB.updateEmployeeId(employeeId, newText.toInt());
                break;
            case 1: // Ім'я
                myDB.updateEmployeeName(employeeId, newText.toStdString());
                break;
            case 2: //  Вік
                myDB.updateEmployeeAge(employeeId, newText.toInt());
                break;
                // додайте обробку для інших стовпців
            case 3: //  зарплата
                myDB.updateEmployeeSalary(employeeId, newText.toInt());
                break;
            case 4: // Гендер
                myDB.updateEmployeeGender(employeeId, newText.toStdString());
                break;
            case 5: // Адреса
                myDB.updateEmployeeAddress(employeeId, newText.toStdString());
                break;
            case 6: // Посада
                myDB.updateEmployeeRole(employeeId, newText.toStdString());
                break;
            case 7: // Паспортні дані
                myDB.updateEmployeePD(employeeId, newText.toInt());
                break;
            case 8: // Звільнення
                myDB.isEmployeed(employeeId, newText.toInt());
                break;
            }
            // Оновлюємо відображення у таблиці
            selectedItem->setText(newText);
        }
    } else {
        QMessageBox::warning(this, tr("Selection Error"),
                             tr("Please select a cell to update."));
    }
}

void MainWindow::listEmployees() {
    myDB.listAllEmployees(table);
}


void MainWindow::saveFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", "/home/oda/Programming/oda/semester5/SysProg/Lab3/QtLab3", "Text files (*.txt);;All files (*.*)");
    if (!fileName.isEmpty()) {
        QFile myFile(fileName);
        if (myFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            myDB.save(fileName.toStdString());
            myFile.close();
        }
    }
}

