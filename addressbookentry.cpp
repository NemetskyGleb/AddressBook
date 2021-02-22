#include "addressbookentry.h"
#include "ui_addressbookentry.h"


AdressBookEntry::AdressBookEntry(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdressBookEntry)
{
    ui->setupUi(this);
    ui->pushButton_save->setText("Сохранить*");
    connect(ui->pushButton_save, &QPushButton::clicked, this, &AdressBookEntry::save);
    connect(ui->lineEdit_FirstName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_SecondName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_thirdName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_address, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_add_tel, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_mobile_tel,&QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->plainTextEdit_other, &QPlainTextEdit::textChanged, this, &AdressBookEntry::markUnsavedChanges);
}
void AdressBookEntry::save() {
    ui->pushButton_save->setText("Сохранить");
}

void AdressBookEntry::markUnsavedChanges() {
    ui->pushButton_save->setText("Сохранить*");
}

AdressBookEntry::~AdressBookEntry()
{
    delete ui;
}

