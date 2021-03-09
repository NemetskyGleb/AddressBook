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
    connect(ui->pushButton_add, &QPushButton::clicked, this, &Adressbook::addEntry);
    connect(ui->pushButton_remove, &QPushButton::clicked, this, &Adressbook::removeEntry);
}

Adressbook::~Adressbook()
{
    delete ui;
}

void Adressbook::addEntry()
{
    Entry entry;
    entry.firstName = "Имя";
    entry.secondName = "Фамилия";
    m_entries.append(entry);
    ui->listWidget->addItem(entry.fullname());
}

void Adressbook::removeEntry()
{

  QList<QListWidgetItem *> selectedItems = ui->listWidget->selectedItems();
  if (!selectedItems.isEmpty()) {
      delete selectedItems.first();
  }
}
