#ifndef SUPPLIERS_H
#define SUPPLIERS_H
#include "stockproduct.h"
#include "QString"

class Suppliers : public stockProduct
{
    QString supplier_name;
    QString address;
    int supplier_id;
    float pendingAmount;
public:
    // will create a product object -- Robust Constructor will manage lowercase the name
    Suppliers(QString name_in, QString address_in, int supplier_id_in = 0, int stock_id_in = 0, float pending_amount_in = 0);
    QString getSupplier_name() const;
    void setSupplier_name(const QString &newSupplier_name);
    QString getAddress() const;
    void setAddress(const QString &newAddress);
    int getSupplier_id() const;
    void setSupplier_id(int newSupplier_id);
    float getPendingAmount() const;
    void setPendingAmount(float newPendingAmount);
};

#endif // SUPPLIERS_H
