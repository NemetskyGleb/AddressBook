#include "addressbookentry.h"
#include "adressbook.h"

#include <QApplication>
#include <QJsonObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Adressbook ab;
    ab.show();
//    AdressBookEntry entry;
//    entry.fromJson(entry.loadJsonFromFile("AddressBook.json"));
//    entry.show();
//    QObject::connect(&entry, &AdressBookEntry::propertiesChanged, &AdressBookEntry::saveAdressBookEntryPropertiesToFile);
    return a.exec();
}
