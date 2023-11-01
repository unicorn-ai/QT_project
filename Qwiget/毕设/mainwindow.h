#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QHostAddress>
#include <qmqtt.h>
#include <QTimer>
#include <QTime>
#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int tablewidget_row,tablewidget_column;
    //报警阈值
    static int max_temper_alarm,max_ISO_alarm,max_voltage_alarm,max_current_alarm,
               min_temper_alarm,min_ISO_alarm,min_voltage_alarm,min_current_alarm;
//    int max_temper_alarm=14,max_ISO_alarm=24,max_voltage_alarm=24,max_current_alarm=14,
//        min_temper_alarm=5,min_ISO_alarm=5,min_voltage_alarm=5,min_current_alarm=5;

    double temper=0,ISO=0,voltage=0,current=0;
    int num=0,s_d1[8];//s_d[8]={1,1,2,2,3,3,4,4}
static int num3;
static int s_d[8];


static int num1;//全局变量储存随机值
static double SO2[40];
static double WEN[10];
static double SHI[10];
static double SHUI[10];

//static double x_time;
    //mqtt部分
    void clientMqtt();

private slots:
    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked(int s);

    void on_pushButton_2_clicked();
    void do_sd();
    //MQTT部分
    void onMQTT_Received(QMQTT::Message);
    void onMQTT_subscribed( QString, quint8);
    void onMQTT_unSubscribed( QString );
    void send_message(QString data);

//    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();


    void get_data(int);


//    void on_pushButton_4_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    QList <QScreen *> list_screen;
    int screenHeigh = 648;
    int screenWidth = 1152;
//    int screenHeigh = 720;
//    int screenWidth = 1280;
//    int screenHeigh = 1080;
//    int screenWidth = 1920;

    int sw_w = 1152;
    int sw_H= 500;
    int sw2_w = 1152;
    int sw2_H= 500;
    int Device_alarm_number=1;
    void ui_init();
    Ui::MainWindow *ui;
    void roundPeogreInit();
    void Device_alarm();
    QVector<QCPTextElement *> titel;
    QVector<QCustomPlot*> lineSty,asd;
double x_time;
    void lineInit();



    //MQTT部分
    QTimer *timer_mqtt;
    QMQTT::Client *client; // 创建QMQTT 客户端

};
#endif // MAINWINDOW_H
