#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>
#include "mydb.h"
namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = nullptr);
    void Show();
    ~Update();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Update *ui;
    void updateUI();
};

#endif // UPDATE_H
