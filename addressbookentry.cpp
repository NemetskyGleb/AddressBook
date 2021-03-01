#include "addressbookentry.h"
#include "ui_addressbookentry.h"
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>

AdressBookEntry::AdressBookEntry(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdressBookEntry)
{
    ui->setupUi(this);
    connect(ui->lineEdit_FirstName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_SecondName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_thirdName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_address, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_add_tel, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->lineEdit_mobile_tel,&QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
    connect(ui->plainTextEdit_other, &QPlainTextEdit::textChanged, this, &AdressBookEntry::markUnsavedChanges);

    connect(ui->pushButton_save, &QPushButton::clicked, this, &AdressBookEntry::save);
}

void AdressBookEntry::save()
{
    if(m_hasUnsavedChanges) {
        ui->pushButton_save->setText("Сохранить");
        emit propertiesChanged(toJson());
        m_hasUnsavedChanges = false;
    }
}

void AdressBookEntry::markUnsavedChanges()
{
    ui->pushButton_save->setText("Сохранить*");
    m_hasUnsavedChanges = true;
}

AdressBookEntry::~AdressBookEntry()
{
    delete ui;
}

void AdressBookEntry::fromJson(const QJsonObject& properties) {
    ui->lineEdit_FirstName->setText(properties["firstName"].toString());
    ui->lineEdit_SecondName->setText(properties["secondName"].toString());
    ui->lineEdit_thirdName->setText(properties["thirdName"].toString());
    ui->lineEdit_address->setText(properties["adress"].toString());
    ui->lineEdit_add_tel->setText(properties["homePhoneNumber"].toString());
    ui->lineEdit_mobile_tel->setText(properties["mobilePhoneNumber"].toString());
    ui->plainTextEdit_other->blockSignals(true);
    ui->plainTextEdit_other->setPlainText(properties["other"].toString());
    ui->plainTextEdit_other->blockSignals(false);
}

void AdressBookEntry::saveJsonToFile(const QString &filename, const QJsonObject &json)
{
    QFile file(filename);
    if (file.open(QFile::WriteOnly)) {
       QJsonDocument document(json);
       file.write(document.toJson());
       file.close();
    }
}

QJsonObject AdressBookEntry::loadJsonFromFile(const QString &filename)
{
    QJsonObject json;
    QFile file(filename);
    if (file.open(QFile::ReadOnly)) {
       QJsonDocument document = QJsonDocument::fromJson(file.readAll());
       json = document.object();
       file.close();
    }
    return json;
}

void AdressBookEntry::saveAdressBookEntryPropertiesToFile(const QJsonObject& properties) {
    saveJsonToFile("AddressBook.json", properties);
}

QJsonObject AdressBookEntry::toJson() const {
    QJsonObject properties;
    properties["firstName"] = ui->lineEdit_FirstName->text();
    properties["secondName"] = ui->lineEdit_SecondName->text();
    properties["thirdName"] = ui->lineEdit_thirdName->text();
    properties["adress"] = ui->lineEdit_address->text();
    properties["homePhoneNumber"] = ui->lineEdit_add_tel->text();
    properties["mobilePhoneNumber"] = ui->lineEdit_mobile_tel->text();
    properties["other"] = ui->plainTextEdit_other->toPlainText();
    return properties;
}
