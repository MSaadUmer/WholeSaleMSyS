#include "spoileditems.h"
#include "ui_spoileditems.h"
#include "DataSpace.h"
SpoiledItems::SpoiledItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpoiledItems)
{
    ui->setupUi(this);
}

SpoiledItems::~SpoiledItems()
{
    delete ui;
}

void SpoiledItems::Show()
{
    this->show();
}
void SpoiledItems::Close()
{
    this->close();
}
void SpoiledItems::on_btnAdd_clicked()
{
    for (int i = 0; i< Data.products.size(); i++)
    {
        qDebug() << Data.products[i].stock_id;
    }
    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    MyDB::Read(query);
    ui->lblInfo->setText("");
    int SSID = ui->stockID->text().toInt();
    int QTY = ui->Qty->text().toInt();
    float Price = 0.0f;
    if (ui->price->text()!="")
    {
        Price = ui->price->text().toFloat();
    }
    bool found = false;
    for (int i = 0; i < Data.products.size(); i++)
    {
        if (Data.products[i].stock_id == SSID)
        {
            if (Data.products[i].getQuantity_avalaible() < QTY*Data.products[i].getGross_qty())
            {
                ui->lblInfo->setText("Unable below level");
                ui->stockID->clear();
                ui->Qty->clear();
                return;
                break;
            }
            else
            {
                Data.products[i].setQuantity_avalaible(Data.products[i].getQuantity_avalaible()-(QTY*Data.products[i].getGross_qty()));
                Data.products[i].setProfit_denominator(Data.products[i].getProfit_denominator()+(QTY*Data.products[i].getGross_qty()));
                qDebug() << Data.products[i].getProfit_denominator();
                if (Price != 0.0f)
                    Data.products[i].setProfit_numerator(Data.products[i].getProfit_numerator()+(Price*(QTY*Data.products[i].getGross_qty())));
                else
                    Data.products[i].setProfit_numerator(Data.products[i].getProfit_numerator()+(Data.products[i].getPrice()*(QTY*Data.products[i].getGross_qty())));
                qDebug() << Data.products[i].getProfit_numerator();
                found = true;
                break;
            }
        }
    }
    if (found)
        ui->lblInfo->setText("Successful");
    else
        ui->lblInfo->setText("Not Found");
}
void SpoiledItems::updateUI()
{
//    QSqlQueryModel * model = new QSqlQueryModel(this);

//    QSqlQuery query( MyDB::getInstance()->getDBInstance());
//    query.prepare("select * from cppbuzz_items where Status='Spoiled'");

//    if(!query.exec())
//       qDebug() << query.lastError().text() << query.lastQuery();
//    else
//       qDebug() << "== success query fetch()";

//    while(query.next())
//    qDebug()<<query.value(0).toString();

//    model->setQuery(query);
//    ui->tableView->setModel(model);
//    qDebug() << "rows are : " << model->rowCount();
//    ui->tableView->show();

}



