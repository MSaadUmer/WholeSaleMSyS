#include "additem.h"
#include "ui_additem.h"
#include "DataSpace.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QMessageBox>
AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::Show()
{
    this->show();
}

void AddItem::on_btnAdd_clicked()
{
    ui->lblInfo->setText("");
    QString sName = ui->txtName->text().toLower();
    int sQuantity = ui->txtQuantity->text().toInt();
    QString sStatus = ui->cmbStatus->currentText();
    int sSID = ui->stockID->text().toInt();
    int sQty = ui->gQty->text().toInt();
    QString sDPrice = ui->dPrice->text();
    Data.addstockProduct(sName,sDPrice.toFloat(),sQuantity,sSID,sQty,0,0,sStatus);
    qDebug() <<"read was successful " << Data.products.size();
    ui->lblInfo->setText("Item Added Successfully!");
    resetElements();
    QSqlQuery writeQuery(MyDB::getInstance()->getDBInstance());
    MyDB::Write(writeQuery);
//    MyDB::Write(writeQuery);
//    QSqlQuery insertQuery(MyDB::getInstance()->getDBInstance());
//    if(!insertQuery.exec("INSERT INTO stockProducts (name, price, quantity, stockid, gross, denom, num, aval) ""VALUES ('" +sName +"','" +sDPrice + "','"+ sQuantity + "','" +sSID + "','"+ sQty+ "','"+ '0' +"','" + '0' + "','"+ sStatus+"')"))
//    {
//        qDebug() << "Inside";
//        qDebug() << insertQuery.lastError().text() << insertQuery.lastQuery();
//        ui->lblInfo->setText("Unable to Add Item");
//    }
//    else
//    {
//        if(insertQuery.numRowsAffected() > 0)
//        {
//            qDebug() <<"read was successful "<< insertQuery.lastQuery();
//            ui->lblInfo->setText("Item Added Successfully!");
//            resetElements();
//        }
//        else
//            qDebug() <<"Unable to Add new Item";
//     }

}


void AddItem::resetElements()
{
    ui->txtName->clear();
    ui->txtQuantity->clear();
    ui->stockID->clear();
    ui->gQty->clear();
    ui->dPrice->clear();
    //ui->txtPurchasePrice->clear();
}
