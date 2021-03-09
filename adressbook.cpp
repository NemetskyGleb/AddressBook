#include "adressbook.h"
#include "ui_adressbook.h"
#include "addressbookentry.h"


Adressbook::Adressbook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Adressbook)
{
    ui->setupUi(this);
    m_entryEditForm = new AdressBookEntry(ui->centralwidget);
    ui->mainLayout->addWidget(m_entryEditForm);
}

Adressbook::~Adressbook()
{
    delete ui;
}
