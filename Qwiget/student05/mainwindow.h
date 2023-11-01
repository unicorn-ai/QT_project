#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mergeCells(const QString& cell);
    QString  ac_d();
    int all_control=0;
private slots:
    //void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();



    void on_pushButton_5_clicked();



private:
    Ui::MainWindow *ui;
    QAxObject * sheet;
};
#endif // MAINWINDOW_H
