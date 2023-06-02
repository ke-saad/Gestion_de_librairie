#ifndef FIND_H
#define FIND_H

#include <QDialog>
#include "mydb.h"
namespace Ui {
class Find;
}

class Find : public QDialog
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = nullptr);
    ~Find();

private slots:
    void on_btnFind_clicked();

private:
    Ui::Find *ui;
};

#endif // FIND_H
