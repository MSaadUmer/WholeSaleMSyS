#include "suppliers.h"

QString Suppliers::getSupplier_name() const
{
    return supplier_name;
}

void Suppliers::setSupplier_name(const QString &newSupplier_name)
{
    supplier_name = newSupplier_name;
}

QString Suppliers::getAddress() const
{
    return address;
}

void Suppliers::setAddress(const QString &newAddress)
{
    address = newAddress;
}

int Suppliers::getSupplier_id() const
{
    return supplier_id;
}

void Suppliers::setSupplier_id(int newSupplier_id)
{
    supplier_id = newSupplier_id;
}

float Suppliers::getPendingAmount() const
{
    return pendingAmount;
}

void Suppliers::setPendingAmount(float newPendingAmount)
{
    pendingAmount = newPendingAmount;
}

Suppliers::Suppliers(QString name_in, QString address_in, int supplier_id_in, int stock_id_in, float pending_amount_in)
{
    this->supplier_name = name_in;
    this->address = address_in;
    this->supplier_id = supplier_id_in;
    this->pendingAmount = pending_amount_in;
    this->stock_id = stock_id_in;
    //stockProduct(QString name_in, int price_in, int quantity_in, int stock_id, int gross_qty, float N, float D, bool aval);

};
