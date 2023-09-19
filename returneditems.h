#ifndef RETURNEDITEMS_H
#define RETURNEDITEMS_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class ReturnedItems;
}

class ReturnedItems : public QDialog
{
    Q_OBJECT

public:
    explicit ReturnedItems(QWidget *parent = nullptr);
    ~ReturnedItems();
    void Show();
private slots:
    void on_btnAdd_clicked();

private:
    Ui::ReturnedItems *ui;
};

#endif // RETURNEDITEMS_H
