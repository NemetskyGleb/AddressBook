#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QMainWindow>
#include "entry.h"


class AdressBookEntry;



namespace Ui {
class Adressbook;
}

class Adressbook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Adressbook(QWidget *parent = nullptr);
    ~Adressbook();

private:
    Ui::Adressbook *ui;
    AdressBookEntry *m_entryEditForm = nullptr;
    QVector<Entry> m_entries;

};

#endif // ADRESSBOOK_H