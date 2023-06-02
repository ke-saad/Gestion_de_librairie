#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QDialog>

namespace Ui {
class Acceuil;
}

class Acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit Acceuil(QWidget *parent = nullptr);
    ~Acceuil();

private slots:
    void on_btnadd_clicked();

    void on_btnupdate_clicked();

    void on_btndelete_clicked();

    void on_btnfind_clicked();

    void on_btnavaillable_clicked();

    void on_btnexpired_clicked();

    void on_btnreturned_clicked();

private:
    Ui::Acceuil *ui;
};

#endif // ACCEUIL_H
