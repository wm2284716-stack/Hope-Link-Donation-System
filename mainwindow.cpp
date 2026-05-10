#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donation.h" // التأكد من وجود السطر ده

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HopeLink)
{
    ui->setupUi(this);

    // إعداد أعمدة الجدول عند بداية البرنامج
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Donor Name", "Value", "Type"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

// الكود اللي كان ناقص ومسبب الخطأ
void MainWindow::on_btnAdd_clicked()
{
    QString name = ui->nameInput->text();
    float val = ui->valueInput->value();
    QString type = ui->typeCombo->currentText();

    if(name.isEmpty()) return;

    Donation* d;
    if(type == "Cash")
        d = new CashDonation(name, val);
    else
        d = new MedicalDonation(name, val);

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(d->getName()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(d->getValue())));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(d->getType()));

    ui->nameInput->clear();
    ui->valueInput->setValue(0);
}