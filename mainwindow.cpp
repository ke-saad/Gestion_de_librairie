#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include<QtSql/QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>
#include<mydb.h>
#include "acceuil.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/HP/bookShop5.sqlite");
    if(db.open()){
        qDebug()<<("Connection");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_Btnconn_clicked()
//{

    //QSqlQuery query;
   // if(query.exec("SELECT * FROM Admin "))
       //  {
              //    if(query.next()){
             //     qDebug()<<("logged in");

        // }


//}
//}

void MainWindow::on_btnconn_clicked()
{
    QString username,password;
    username = ui->txtusername->text();
    password = ui->txtpassword->text();



    if(username =="admin" && password =="admin123"){
        QMessageBox::information(this, "connexion" ,"username and password true");
        this->hide();
        Acceuil d;
        d.setModal(true);
        d.exec();
    }
    else {
        QMessageBox::warning(this,"connexion","username or password wrong");
    }
}
