#include "update.h"
#include "ui_update.h"

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
}

Update::~Update()
{
    delete ui;
}
void Update::updateUI()
{

}

void Update::Show()
{
    updateUI();
    this->show();
}


void Update::on_pushButton_clicked()
{
    ui->lblInfo->clear();
    QString title = ui->txtId->text();
    QString quantity = ui->txtquantity->text();
    QString pp = ui->txtpp->text();
    QString ps = ui->txtsp->text();
    QString dp= ui->txtdp->text();
    QString ds = ui->txtds->text();


    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("update Book set Quantity='" + quantity + "' and DOP='" + dp + "' and DOS='" + ds+ "' and SellingPrice='" + ps + "' and PurchasePrice='" + pp + "'where Title = '" + title+ "'");

    if(!query.exec())
    {
       qDebug() << query.lastError().text() << query.lastQuery();
       ui->lblInfo->setText("Unable to update Item" + query.lastError().text());
    }
    else{
       if(query.numRowsAffected()>0)
       {
            qDebug() << "Item Updated Successfully!";
            ui->lblInfo->setText("Item Updated Successfully!");
       }
       else
       {
        qDebug() << " Unable to update Item";
        ui->lblInfo->setText("Unable to Update Item");
      }
    }
}
