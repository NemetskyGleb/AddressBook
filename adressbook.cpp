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
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &Adressbook::loadEntryData);
    connect(m_entryEditForm, &AdressBookEntry::entryChanged, this, &Adressbook::saveCurrentEntryData);
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

  QListWidgetItem * currentItem = ui->listWidget->currentItem();
  if (currentItem != nullptr) {
      delete currentItem;
  }
}

void Adressbook::loadEntryData(const int index)
{
    if (index > -1 && index < m_entries.count()) {
        m_entryEditForm->fromEntry(m_entries[index]);
    }
}

void Adressbook::saveCurrentEntryData(const Entry &entry)
{
    int rowIndex = ui->listWidget->currentRow();
    if (rowIndex > -1 && rowIndex < m_entries.count()) {
        m_entries[rowIndex] = entry;
        ui->listWidget->currentItem()->setText(entry.fullname());
    }

}
