#include "details.h"

QString details::getSupplier_name() const
{
    return name;
}

void details::setName(const QString &newName)
{
    name = newName;
}

QString details::getAddress() const
{
    return address;
}

void details::setAddress(const QString &newAddress)
{
    address = newAddress;
}

details::details()
{

}
