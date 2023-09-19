#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddItem = new AddItem(this);
    ptrItemReport = new ItemsReport(this);
    ptrSpoiledItems = new SpoiledItems(this);
    ptrSoldITems = new SoldItems(this);
    ptrExpiredItems = new ExpiredItems(this);
    ptrReturnedItems = new ReturnedItems(this);
    ptrAvailableItems = new AvailableItems(this);
    ptrUpdateItem = new UpdateItem(this);
    ptrFindItem = new FindItem(this);
    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    MyDB::Read(query);

this->setFixedSize(400, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrAddItem;
    delete ptrItemReport;
    delete ptrSpoiledItems;
    delete ptrSoldITems;
    delete ptrExpiredItems;
    delete ptrReturnedItems;
    delete ptrFindItem;
    delete ptrUpdateItem;
    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    MyDB::Write(query);
    MyDB::ResetInstance();
}

void MainWindow::on_btnAddItem_clicked()
{
    ptrAddItem->Show();
}

void MainWindow::on_btnUpdateItem_clicked()
{
    ptrUpdateItem->Show();
}

void MainWindow::on_btnSoldItems_clicked()
{
    ptrSoldITems->Show();
}

void MainWindow::on_btnReport_clicked()
{
    ptrItemReport->Show();
}

void MainWindow::on_btnExpiredItems_clicked()
{
    ptrExpiredItems->Show();
}

void MainWindow::on_btnAvailableItems_clicked()
{
    ptrAvailableItems->Show();
}

void MainWindow::on_btnSpoiledItem_clicked()
{
    ptrSpoiledItems->Show();
}

void MainWindow::on_btnReturnItems_clicked()
{
    ptrReturnedItems->Show();
}

void MainWindow::on_btnFindItem_clicked()
{
    ptrFindItem->Show();
}

void MainWindow::on_Backbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Signupbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_createaccbtn_clicked()
{

    QString UserName = ui->UserName_2->text();
    QString Password = ui->Password_2->text();
    QString sPassword = ui->Password_3->text();
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS users ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "username TEXT, "
                               "password TEXT)";

    if (!query.exec(createTableQuery))
    {
        qDebug() << "Table creation failed: " << query.lastError().text();
    }

    qDebug() << "Table created successfully.";
    UserName = UserName.trimmed();
    Password = Password.trimmed();

    // Check if the username or password is empty
    if (UserName.isEmpty() || Password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Username or password cannot be empty.");
        return;
    }
    if (Password == sPassword)
    {
        QSqlQuery insertQuery(MyDB::getInstance()->getDBInstance());
        insertQuery.clear();
        insertQuery.prepare("INSERT INTO users (username, password) VALUES('" + UserName + "','" + Password + "')");
        if (insertQuery.exec())
        {
            QMessageBox::information(this, "Success", "Account Created");
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Passwords do not match!");
    }
}

void MainWindow::on_Loginbtn_clicked()
{
    QString UserNameL = ui->UserName->text();
    QString PasswordL = ui->Password->text();
    QSqlQuery Findquery(MyDB::getInstance()->getDBInstance());
    Findquery.clear();
    Findquery.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    Findquery.bindValue(":username", UserNameL);
    Findquery.bindValue(":password", PasswordL);
    if (Findquery.exec() && Findquery.next())
    {
        // Login successful
        QMessageBox::information(this, "Success", "Login successful!");
        // TODO: Add code to open the next window or perform further actions
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        // Login failed
        QMessageBox::warning(this, "Error", "Invalid username or password.");
    }
}

void MainWindow::on_Backbtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Password_cursorPositionChanged(int arg1, int arg2)
{

}

