#include "addressbookentry.h"
#include "adressbook.h"

#include <QApplication>
#include <QJsonObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Adressbook addressbook;
    addressbook.show();
//    AdressBookEntry entry;
//    entry.fromJson(entry.loadJsonFromFile("AddressBook.json"));
//    QObject::connect(&entry, &AdressBookEntry::propertiesChanged, &AdressBookEntry::saveAdressBookEntryPropertiesToFile);
    return a.exec();
}
