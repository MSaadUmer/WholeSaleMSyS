#include "datatables.h"
#include <QtCore>
void DataTables::addstockProduct(QString name_in, float price_in, int quantity_in, int stock_id, int gross_qty, float N, float D, QString aval)
{
    stockProduct New(name_in, price_in, quantity_in, stock_id, gross_qty, N, D, aval);
    this->products.push_back(New);
}
void DataTables::addSuppliers(QString name_in, QString address_in, int supplier_id_in, int stock_id_in, float pending_amount_in)
{
    Suppliers New(name_in, address_in, supplier_id_in, stock_id_in, pending_amount_in);
    this->suppliers.push_back(New);
}
void DataTables::addCustomer(QString name_in, QString address_in, int id_in, float pending_amount, bool defaulter_in)
{
    Customer New(name_in, address_in, id_in , pending_amount , defaulter_in);
    this->customers.push_back(New);
}
