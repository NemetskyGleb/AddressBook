#ifndef ENTRY_H
#define ENTRY_H
#include <QString>

struct Entry {
    QString firstName;
    QString secondName;
    QString thirdName;

    QString adress;
    QString homePhoneNumber;
    QString mobilePhoneNumber;
    QString other;

    QString fullname() const;
};

#endif // ENTRY_H
