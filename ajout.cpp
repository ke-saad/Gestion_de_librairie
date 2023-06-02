#include "ajout.h"
#include "ui_ajout.h"
#include <QDebug>
#include<QtSql/QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>
#include"acceuil.h"
#include "QFileDialog"
#include "mydb.h"
Ajout::Ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajout)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QSqlDatabase db;
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/HP/bookShop5.sqlite");
    if(db.open()){
        qDebug()<<("Connection");
    }
}

Ajout::~Ajout()
{
    delete ui;
}
void Ajout::Show()
{
    this->show();
}

//void Ajout::on_pushButton_clicked()
//{
   // ui->lblInfo->setText("");

   // QString sName = ui->txtName->text();
    //QString sQuantity = ui->txtQuantity->text();
    //QString sStatus = ui->cmbStatus->currentText();
    //QString sDOP = ui->txtDOP->text();
    //QString sDOS = ui->txtDOS->text();
    //QString sSellingPrice = ui->txtSellingPrice->text();
    //QString sPurchasePrice = ui->txtPurchasePrice->text();

    //QSqlQuery query(MyDB::getInstance()->getDBInstance());
    //query.clear();
    //query.prepare("insert into cppbuzz_items(Name, Quantity, Status, DOP, DOS, SellingPrice, PurchasePrice) values ('" +sName +"','" +sQuantity + "','"+ sStatus + "','" +sDOP + "','"+ sDOS+ "','"+sSellingPrice+ "','"+ sPurchasePrice + "')");

    //if(!query.exec())
    //{
      //  qDebug() << query.lastError().text() << query.lastQuery();
        //ui->lblInfo->setText("Unable to Add Item");
    //}
   // else
    //{
      //  if(query.numRowsAffected() > 0)
        //{
          //  qDebug() <<"read was successful "<< query.lastQuery();
            //ui->lblInfo->setText("Item Added Successfully!");
            //resetElements();
        //}
        //else
          //  qDebug() <<"Unable to Add new Item";
     //}


//}

void Ajout::on_btnAdd_clicked()
{
    //Acceuil conn;
    QString name,quantity,status,dop,dos,sellingprice,purchaseprice;
    name = ui-> txtName->text();
   // sName = ui->txtName->text();
    quantity = ui->txtQuantity->text();
    //status= ui->cmbStatus->currentText();
    dop= ui->txtDOP->text();
    dos = ui->txtDOS->text();
    sellingprice= ui->txtSellingPrice->text();
    purchaseprice = ui->txtPurchasePrice->text();
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.clear();
    query.prepare("insert into Book (Title,Quantity, Status, DOP, DOS, SellingPrice, PurchasePrice ) values"
                  " ('" +name +"','" +quantity + "','" +dop + "','"+ dos+ "','"+sellingprice+ "','"+ purchaseprice + "')");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
      QMessageBox::warning(this, "Add" ,"Book was not added successfully");
    }
    else
    {
        if(query.numRowsAffected() > 0)
        {
            qDebug() <<"read was successful "<< query.lastQuery();
            QMessageBox::information(this, "Add" ,"Book added successfully");
            resetElements();
        }
        else
            qDebug() <<"Unable to Add new Item";
     }

}

void Ajout::resetElements()
{
    ui->txtName->clear();
    ui->txtQuantity->clear();
    ui->txtDOP->clear();
    ui->txtDOS->clear();
    ui->txtSellingPrice->clear();
    ui->txtPurchasePrice->clear();
}
    //ui->setupUi(this);
    //ui->setupUi(this);
    //QSqlDatabase db;
   // db= QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("C:/Users/HP/bookShop5.sqlite");
    //if(db.open()){
        //qDebug()<<("Connection");
    //}

        //QSqlQuery query;
        //QSqlQuery query(db::getInstance()->getDBInstance());
         //query.clear();
         //query.exec("insert into Book (Title,Quantity, Status, DOP, DOS, SellingPrice, PurchasePrice ) values"
               // " ('" +name +"','" +quantity + "','" +dop + "','"+ dos+ "','"+sellingprice+ "','"+ purchaseprice + "')");

    // if(!conn.exec())
         //{
           //qDebug() << query.lastError().text() << query.lastQuery();
             //ui->lblInfo->setText("Unable to Add Item");
           //QMessageBox::warning(this, "Add" ,"Book was not added successfully");
           //this->hide();
          // Acceuil d;
          // d.setModal(true);
          // d.exec();
         //}
         //else
        // {
            // if(query.numRowsAffected() > 0)
             //{
               // qDebug() <<"read was successful "<< query.lastQuery();
                 //ui->lblInfo->setText("Item Added Successfully!");
             //QMessageBox::information(this, "Add" ,"Book added successfully");
              //  }
             //resetElements();
            // }
             //else
     //{
               //  qDebug() <<"Unable to Add new Item";
        //  }

//}
// conn.exec();



