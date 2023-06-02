#include "find.h"
#include "ui_find.h"

Find::Find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
    ui->rdoName->setChecked(true);

}

Find::~Find()
{
    delete ui;
}

void Find::on_btnFind_clicked()
{
    QString sValue = ui->txtValue->text();
    QString sCriteriaColum = "";

    if(ui->rdoId->isChecked())
        sCriteriaColum="Id";
    else if (ui->rdoName->isChecked())
        sCriteriaColum="Name";
    else if (ui->rdoQuantity->isChecked())
        sCriteriaColum="Quantity";
    else if (ui->rdoSellingPrice->isChecked())
        sCriteriaColum = "SellingPrice";
    else
        sCriteriaColum = "Name";

    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select * from Book where " +sCriteriaColum+" like '%" + sValue + "%'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
       if(query.numRowsAffected()>0)
       qDebug() << "== success query fetch() : " << query.lastQuery();
       else {
           qDebug() << " No record ! found ";
           qDebug() << " Query is : " << query.lastQuery();
       }
    }
    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->tableView->show();
}



