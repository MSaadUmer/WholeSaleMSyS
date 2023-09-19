#ifndef DATATABLES_H
#define DATATABLES_H
#include "stockproduct.h"
#include "suppliers.h"
#include "customer.h"
#include <QVector>
class DataTables
{
    public:
    // push_back(), pop_back() methods are built-in for Dynamic Array like system
    QVector <Suppliers> suppliers;
    QVector <Customer> customers;
    QVector <stockProduct> products;

    // just create an object and call push_back()
    // must add to the quantity if product already present lowecase comparison
    void addstockProduct(QString name_in, float price_in, int quantity_in, int stock_id, int gross_qty, float N = 0, float D = 0, QString aval= "Avalaible");
    // will iterate over the products vector checking that if qty is bellow corresponding gross then availaiblity will be set to false(red-flag) else true;
    void addSuppliers(QString name_in, QString address_in, int supplier_id_in = 0, int stock_id_in = 0, float pending_amount_in = 0);
    // pre-checks then call pushback()
    void addCustomer(QString name_in, QString address_in, int id_in = 0, float pending_amount = 0, bool defaulter_in = false);
    // Displays profits
    // to fetch an element from the products subjecting to addition to the cart....

};
#endif // DATATABLES_H
