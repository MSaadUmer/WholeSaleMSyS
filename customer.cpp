#include "customer.h"

QString Customer::getName() const
{
    return name;
}

void Customer::setName(const QString &newName)
{
    name = newName;
}

QString Customer::getAddress() const
{
    return address;
}

void Customer::setAddress(const QString &newAddress)
{
    address = newAddress;
}

int Customer::getId() const
{
    return id;
}

void Customer::setId(int newId)
{
    id = newId;
}

float Customer::getPending_amount() const
{
    return pending_amount;
}

void Customer::setPending_amount(float newPending_amount)
{
    pending_amount = newPending_amount;
}

bool Customer::getDefaulter() const
{
    return defaulter;
}

void Customer::setDefaulter(bool newDefaulter)
{
    defaulter = newDefaulter;
}

Customer::Customer(QString name_in, QString address_in, int id_in , float pending_amount, bool defaulter_in)
{
    name = name_in;
    address = address_in;
    id = id_in;
    pending_amount = pending_amount;
    defaulter = defaulter_in;
}
