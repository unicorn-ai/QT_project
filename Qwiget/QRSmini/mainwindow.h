#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>

//#include <Qstring>
class SerialPort;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort *serilaPort;
    QTimer *timer;

public slots:
/* 声明一个槽函数 */
void on_openBt_clicked();
void on_closeBt_clicked();
void serilaPortReadyRead_Slot();
void on_clearBt_clicked();
void slotReadData();
void serialPort_readyRead();

private slots:
void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray buffer;
};
#endif // MAINWINDOW_H
