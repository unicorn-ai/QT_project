#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void on_buttonBox_accepted();
    int num=0;




signals:
    void send_data(int);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    //void on_buttonBox_clicked(QAbstractButton *button);
private:
    Ui::Dialog *ui;
    MainWindow *f;

};


#endif // DIALOG_H
