#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include "dialog.h"
#include<QDialog>
//#include<mydb.h>
#include <QMainWindow>
#include<QtSql/QSql>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_Btnconn_clicked();

    void on_btnconn_clicked();

private:


    Ui::MainWindow *ui;
    //QSqlDatabase db;
};

#endif // MAINWINDOW_H
