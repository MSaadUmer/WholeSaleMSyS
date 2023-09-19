#include "finditem.h"
#include "ui_finditem.h"

FindItem::FindItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindItem)
{
    ui->setupUi(this);
//    ui->rdoName->setChecked(true);
}

FindItem::~FindItem()
{
    delete ui;
}
void FindItem::Show()
{
    this->show();
    UpdateUI();
}
void FindItem::on_btnFind_clicked()
{

//    qDebug() << "in init()";
//    QSqlQueryModel * model = new QSqlQueryModel(this);
//    QSqlQuery query( MyDB::getInstance()->getDBInstance());
//    MyDB::Write(query);
//    query.prepare("SELECT * FROM suppliers");
//    if(!query.exec())
//        qDebug() << query.lastError().text() << query.lastQuery();
//    else
//        qDebug() << "== success query fetch()";
//    while(query.next())
//    qDebug()<<query.value(0).toString();
//    model->setQuery(query);
//    ui->tableView->setModel(model);
//    qDebug() << "rows are : " << model->rowCount();
//    ui->tableView->show();
}

void FindItem::UpdateUI()
{
    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);
    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    MyDB::Write(query);
    query.prepare("SELECT * FROM suppliers");
    if(!query.exec())
    qDebug() << query.lastError().text() << query.lastQuery();
    else
    qDebug() << "== success query fetch()";
    while(query.next())
    qDebug()<<query.value(0).toString();
    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->tableView->show();
}
