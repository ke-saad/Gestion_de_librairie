#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>
#include "mainwindow.h"
#include"acceuil.h"
#include "mydb.h"

namespace Ui {
class Ajout;
}

class Ajout : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = nullptr);
    void Show();
    ~Ajout();

private slots:
    void on_pushButton_clicked();

    void on_btnAdd_clicked();

private:
    Ui::Ajout *ui;
     void resetElements();
};

#endif // AJOUT_H
