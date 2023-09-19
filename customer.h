#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class Customer
{
    QString name;
    QString address;
    int id;
    float pending_amount;
    bool defaulter;
public:
    // validity checks are to be performed.
    Customer(QString name_in, QString address_in, int id_in = 0, float pending_amount = 0, bool defaulter_in = false);
    QString getName() const;
    void setName(const QString &newName);
    QString getAddress() const;
    void setAddress(const QString &newAddress);
    int getId() const;
    void setId(int newId);
    float getPending_amount() const;
    void setPending_amount(float newPending_amount);
    bool getDefaulter() const;
    void setDefaulter(bool newDefaulter);
};
#endif // CUSTOMER_H
