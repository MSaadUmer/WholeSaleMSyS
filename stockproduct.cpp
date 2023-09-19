#include "stockproduct.h"
#define GROSS 144
int stockProduct::getGross_qty() const
{
    return gross_qty;
}

void stockProduct::setGross_qty(int newGross_qty)
{
    gross_qty = newGross_qty;
}

int stockProduct::getQuantity_avalaible() const
{
    return quantity_avalaible;
}

void stockProduct::setQuantity_avalaible(int newQuantity_avalaible)
{
    quantity_avalaible = newQuantity_avalaible;
}

float stockProduct::getProfit_denominator() const
{
    return profit_denominator;
}

void stockProduct::setProfit_denominator(float newProfit_denominator)
{
    profit_denominator = newProfit_denominator;
}

float stockProduct::getProfit_numerator() const
{
    return profit_numerator;
}

void stockProduct::setProfit_numerator(float newProfit_numerator)
{
    profit_numerator = newProfit_numerator;
}

float stockProduct::getPrice() const
{
    return price;
}

void stockProduct::setPrice(float newPrice)
{
    price = newPrice;
}

QString stockProduct::getName() const
{
    return name;
}

void stockProduct::setName(const QString &newName)
{
    name = newName;
}

QString stockProduct::getAvailaibility() const
{
    return availaibility;
}

void stockProduct::setAvailaibility(const QString &newAvailaibility)
{
    availaibility = newAvailaibility;
}

stockProduct::stockProduct(QString name_in, float price_in, int quantity_in, int stock_id, int gross_qty, float N, float D, QString aval)
{
    name = name_in;
    price = price_in;
    quantity_avalaible = quantity_in;
    this->gross_qty = gross_qty;
    availaibility = aval;
    profit_denominator = D;
    profit_numerator = N;
    this->stock_id = stock_id;
}
stockProduct::stockProduct()
{
    ;
}
void stockProduct::setAval(QString Aval)
{
    this->availaibility = Aval;
}
void stockProduct::setQty(int Qty){
    this->quantity_avalaible = Qty;
}
