#ifndef STOCKPRODUCT_H
#define STOCKPRODUCT_H
#include <QString>
#define GROSS 144
class stockProduct
{
    QString name;
    float price;
    int quantity_avalaible;
    int gross_qty;
    QString availaibility;
    float profit_denominator;
    float profit_numerator;

public:
    int stock_id;
    // will be same for the table of suppliers
    // will create a product object -- Robust Constructor will manage lowercase the name
    // update weighted-average by multiplying with previous denominator..............
    stockProduct(QString name_in, float price_in, int quantity_in, int stock_id, int gross_qty, float N, float D, QString aval);
    stockProduct();
    void setQty(int Qty);
    void setAval(QString aval);

    int getGross_qty() const;
    void setGross_qty(int newGross_qty);
    int getQuantity_avalaible() const;
    void setQuantity_avalaible(int newQuantity_avalaible);
    float getProfit_denominator() const;
    void setProfit_denominator(float newProfit_denominator);
    float getProfit_numerator() const;
    void setProfit_numerator(float newProfit_numerator);
    float getPrice() const;
    void setPrice(float newPrice);
    QString getName() const;
    void setName(const QString &newName);
    QString getAvailaibility() const;
    void setAvailaibility(const QString &newAvailaibility);
};
#endif // STOCKPRODUCT_H
