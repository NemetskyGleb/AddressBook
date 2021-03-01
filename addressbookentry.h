#ifndef ADRESSBOOKENTRY_H
#define ADRESSBOOKENTRY_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AdressBookEntry; }
QT_END_NAMESPACE

class AdressBookEntry : public QWidget
{
    Q_OBJECT

public:
    AdressBookEntry(QWidget *parent = nullptr);
    ~AdressBookEntry();
    void fromJson(const QJsonObject& properties);
    void saveJsonToFile(const QString& filename, const QJsonObject& json);
    void saveAdressBookEntryPropertiesToFile(const QJsonObject& properties);
    QJsonObject  loadJsonFromFile(const QString& filename);
    QJsonObject toJson() const;
signals:
    void propertiesChanged(const QJsonObject& properties);
public slots:
    void save();
private slots:
    void markUnsavedChanges();
private:
    Ui::AdressBookEntry *ui;
    bool m_hasUnsavedChanges = false;
};
#endif // ADRESSBOOKENTRY_H
