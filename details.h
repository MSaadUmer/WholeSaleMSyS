#ifndef DETAILS_H
#define DETAILS_H
#include <QString>


class details
{
    QString name;
    QString address;
public:

    details();
    virtual QString getSupplier_name() const = 0;
    void setName(const QString &newName);
    QString getAddress() const;
    void setAddress(const QString &newAddress);
};

#endif // DETAILS_H
