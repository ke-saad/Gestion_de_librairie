#include "acceuil.h"
#include "ui_acceuil.h"
#include "ajout.h"
#include "find.h"
#include "delete.h"
#include "update.h"

Acceuil::Acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acceuil)
{
    ui->setupUi(this);
}

Acceuil::~Acceuil()
{
    delete ui;
}

void Acceuil::on_btnadd_clicked()
{
    Ajout d;
    d.setModal(true);
    d.exec();
}

void Acceuil::on_btnupdate_clicked()
{
    Update d;
    d.setModal(true);
    d.exec();
}

void Acceuil::on_btndelete_clicked()
{
    Delete d;
    d.setModal(true);
    d.exec();
}

void Acceuil::on_btnfind_clicked()
{
    Find d;
    d.setModal(true);
    d.exec();
}

//void Acceuil::on_btnavaillable_clicked()
//{

//}

//void Acceuil::on_btnexpired_clicked()
//{

//}

//void Acceuil::on_btnreturned_clicked()
//{

//}
