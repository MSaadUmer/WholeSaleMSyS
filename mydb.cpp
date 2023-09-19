#include "mydb.h"
#include "DataSpace.h"

MyDB* MyDB::instance = nullptr;

MyDB::MyDB()
{
    init();
}

void MyDB::init()
{
    qDebug() << "in init()";
    db = QSqlDatabase::addDatabase("QSQLITE", "Data");
    db.setDatabaseName("C:/DataBases/wholeSale.db");

    if(QFile::exists("C:/DataBases/wholeSale.db"))
            qDebug() << "DB file exist";
        else
           qDebug() << "DB file doesn't exists";

        if (!db.open())
            qDebug() << db.lastError().text();
        else
            qDebug() << "Database loaded successfull!";
        QSqlQuery start(db);
        qDebug() << start.lastError();
        start.exec("CREATE TABLE IF NOT EXISTS stockProducts (name TEXT PRIMARY KEY, price TEXT, quantity TEXT, stockid TEXT, gross TEXT, denom TEXT, num TEXT, aval TEXT, profit TEXT)");
        qDebug() << "Table created";
        qDebug() << start.lastError().text() << start.lastQuery();
        //Customer::Customer(QString name_in, QString address_in, int id_in , float pending_amount, bool defaulter_in)
        start.exec("CREATE TABLE IF NOT EXISTS customers (name TEXT PRIMARY KEY, address TEXT, id TEXT, PA TEXT, defaulter TEXT)");
        qDebug() << start.lastError().text() << start.lastQuery();
        start.exec("CREATE TABLE IF NOT EXISTS suppliers (name TEXT PRIMARY KEY, address TEXT, supplier_id TEXT, stock_id TEXT, PA TEXT)");
        qDebug() << start.lastError().text() << start.lastQuery();


}

MyDB *MyDB::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new MyDB();

    return instance;
}

QSqlDatabase MyDB::getDBInstance()
{
    qDebug() <<"in getDBInstance()";
    return db;
}

void MyDB::ResetInstance()
{
      qDebug() << "deleting instance of MyDB";
      delete instance;
      instance = nullptr;
}

void MyDB::Write(QSqlQuery &query)
{
      int i = 0;
      qDebug() << "In Write";
      query.clear();
      query.exec("DELETE FROM stockProducts");
      qDebug() << query.lastError();
      QString name;
      QString price;
      QString quantity;
      QString stockid;
      QString gross;
      QString denom;
      QString num;
      QString aval;
      QString profit;
      float temp;
      qDebug() << Data.products.size();
      for (i = 0; i < Data.products.size(); i++)
      {
        name = Data.products[i].getName();
        price = QString::number(Data.products[i].getPrice());
        quantity = QString::number(Data.products[i].getQuantity_avalaible());
        stockid = QString::number(Data.products[i].stock_id);
        gross = QString::number(Data.products[i].getGross_qty());
        denom = QString::number(Data.products[i].getProfit_denominator());
        num = QString::number(Data.products[i].getProfit_numerator());
        aval = Data.products[i].getAvailaibility();
        if (Data.products[i].getProfit_denominator()==0)
        {
            profit = QString::number(0);
        }
        else
        {
            temp = (Data.products[i].getProfit_numerator()/Data.products[i].getProfit_denominator());
            temp /= Data.products[i].getPrice();
            if (temp > 1.0f)
            {
                temp = (temp-1)*100;
                profit = QString::number(temp);
            }
            else
            {
                temp = -(1-temp)*100;
                profit = QString::number(temp);
            }
        }
        query.exec("INSERT INTO stockProducts (name, price, quantity, stockid, gross, denom, num, aval, profit) ""VALUES ('" +name +"','" +price + "','"+ quantity + "','" +stockid + "','"+ gross+ "','"+ denom +"','" + num + "','"+ aval+"','"+profit+"')");
        qDebug() << query.lastError().text();
      }
      query.clear();
      query.exec("DELETE FROM customers");
      QString address;
      QString personID;
      QString pending_amount;
      QString defaulter;
      qDebug() << Data.customers.size();
      for (i = 0; i < Data.customers.size(); i++)
      {
        name = Data.customers[i].getName();
        address = Data.customers[i].getAddress();
        personID = QString::number(Data.customers[i].getId());
        pending_amount = QString::number(Data.customers[i].getPending_amount());
        defaulter = (Data.customers[i].getDefaulter() == true) ? "Yes" : "No";
        query.exec("INSERT INTO customers (name, address, id, PA, defaulter)" "VALUES ('"+ name+"','"+address+"','"+personID+"','"+pending_amount+"','"+defaulter+"')");
        qDebug() << query.lastError().text() << query.lastQuery();

      }
      query.clear();
      query.exec("DELETE FROM suppliers");
       qDebug() << Data.suppliers.size();
      for (i = 0; i <Data.suppliers.size(); i++)
      {
        name = Data.suppliers[i].getSupplier_name();
        address = Data.suppliers[i].getAddress();
        personID = QString::number(Data.suppliers[i].getSupplier_id());
        pending_amount = QString::number(Data.suppliers[i].getPendingAmount());
        stockid = QString::number(Data.suppliers[i].stock_id);
        query.exec("INSERT INTO suppliers (name, address, supplier_id, stock_id, PA)" "VALUES ('"+ name+"','"+address+"','"+personID+"','"+stockid+"','"+pending_amount+"')");
        qDebug()  << query.lastError()<<query.lastQuery();
      }
      qDebug () << "Exit Write()";
}

void MyDB::Read(QSqlQuery &query)
{
      qDebug() << "In Read()";
      query.clear();
      query.exec("SELECT * FROM stockProducts");
      QString name;
      float price;
      int quantity;
      int stockid;
      int gross;
      float denom;
      float num;
      QString aval;
      Data.products.clear();
      while(query.next())
      {
        name = query.value(0).toString();
        price = query.value(1).toFloat();
        quantity = query.value(2).toInt();
        stockid = query.value(3).toInt();
        gross = query.value(4).toInt();
        denom = query.value(5).toFloat();
        num = query.value(6).toFloat();
        aval = query.value(7).toString();
        Data.addstockProduct(name,price,quantity,stockid,gross,num,denom,aval);
      }
      query.clear();
      query.exec("SELECT * FROM customers");
      QString address;
      int id;
      float PA;
      bool defaulter;
      Data.customers.clear();
      while(query.next())
      {
        name = query.value(0).toString();
        address = query.value(1).toString();
        id = query.value(2).toInt();
        PA = query.value(3).toFloat();
        defaulter = query.value(4).toString() == "Yes" ? true: false;
        Data.addCustomer(name,address,id,PA,defaulter);
      }
      query.clear();
      query.exec("SELECT * FROM suppliers");
      int supplierid;
      Data.suppliers.clear();
      while (query.next())
      {
        name = query.value(0).toString();
        address = query.value(1).toString();
        supplierid = query.value(2).toInt();
        stockid = query.value(3).toInt();
        PA = query.value(4).toFloat();
        Data.addSuppliers(name,address,supplierid,stockid,PA);
      }
            qDebug() << "Exit Read()";
}

MyDB::~MyDB()
{
   qDebug() << "closing database connection";
   db.close();
}
