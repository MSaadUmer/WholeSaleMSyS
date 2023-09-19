#include "returneditems.h"
#include "ui_returneditems.h"
#include "DataSpace.h"
ReturnedItems::ReturnedItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReturnedItems)
{
    ui->setupUi(this);
}

ReturnedItems::~ReturnedItems()
{
    delete ui;
}

void ReturnedItems::Show()
{
    show();
}

void ReturnedItems::on_btnAdd_clicked()
{
    ui->lblInfo->setText("");
    QString sName = ui->txtName->text();
    QString sAddress = ui->txtAddress->text();
    int sSupID = ui->txtSID->text().toInt();
    float sPA = ui->gQty->text().toFloat();
    int sSID = ui->stockID->text().toInt();
    Data.addSuppliers(sName,sAddress,sSupID,sSID,sPA);
    qDebug() <<"read was successful " << Data.suppliers.size();
    ui->lblInfo->setText("Item Added Successfully!");
//    QSqlQueryModel * model = new QSqlQueryModel(this);
//    QSqlQuery query( MyDB::getInstance()->getDBInstance());
//    MyDB::Write(query);
    ui->gQty->clear();
    ui->stockID->clear();
    ui->txtAddress->clear();
    ui->stockID->clear();
    ui->txtSID->clear();
}

