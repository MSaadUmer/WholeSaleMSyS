#include "updateitem.h"
#include "ui_updateitem.h"
#include "DataSpace.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QMessageBox>

UpdateItem::UpdateItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateItem)
{
    ui->setupUi(this);
}

UpdateItem::~UpdateItem()
{
    delete ui;
}

void UpdateItem::updateUI()
{

}

void UpdateItem::Show()
{
    updateUI();
    this->show();
}

void UpdateItem::on_pushButton_clicked()
{
    ui->lblInfo->clear();
    QString sId = ui->txtId->text();
    QString sStatus = ui->cmbStatus->currentText();
    QString SQty = ui->txtQty->text();
    ui->txtId->clear();
    ui->txtQty->clear();
    bool check = false;
    qDebug() << "the stock is: " << Data.products.size();
    for (int i = 0; i < Data.products.size(); i++)
    {
        qDebug() << "the stock id is:" << Data.products[i].stock_id;
        if (Data.products[i].stock_id == sId.toInt())
        {
            Data.products[i].setAval(sStatus);
            Data.products[i].setQty(SQty.toInt());
            check=true;
        }
    }
    if (check)
    {
        ui->lblInfo->setText("Item Updated Successfully!");
    }
    else
    {
        ui->lblInfo->setText("Unable to Update Item");
    }
    qDebug() << "okokokokok";



//    QSqlQuery query( MyDB::getInstance()->getDBInstance());
//    query.prepare("update cppbuzz_items set Status='" + sStatus + "' where Id = '" + sId + "'");

//    if(!query.exec())
//    {
//       qDebug() << query.lastError().text() << query.lastQuery();
//       ui->lblInfo->setText("Unable to update Item" + query.lastError().text());
//    }
//    else{
//       if(query.numRowsAffected()>0)
//       {
//            qDebug() << "Item Updated Successfully!";
//            ui->lblInfo->setText("Item Updated Successfully!");
//       }
//       else
//       {
//        qDebug() << " Unable to update Item";
//        ui->lblInfo->setText("Unable to Update Item");
//      }
//    }
}
