#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @fileName      mainwindow.h
 * @brief         程序主界面，串口读写操作
 * @author        topeet
 * @date          2021-04-26
 */

#include <QMainWindow>
#include <QStackedWidget>
#include <QSerialPort>
#include <QMessageBox>
#include <QString>
#include <QSocketNotifier>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include "animation.h"
#include "serialwidget.h"
#include "settingwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initTopWidget();

private:
    bool openSerialDevice(char * name);                         //打开串口设备
    bool setSerialAttribute(int devfd,QString speedString,QString checkbitString,QString stopbitString,QString databitString);

protected slots:
    void toSettingPageSlot();                                   //切换到属性设置界面槽函数
    void toDataPageSlot();                                      //切换到数据编辑显示界面槽函数
    void sendDataSlot();                                        //发送数据槽函数
    void recvDataSlot();                                        //接收数据槽函数

public:
    SerialWidget            *           serialWidget;           //串口数据显示主界面
    SettingWidget           *           settingWidget;          //串口属性设置界面

private:
    Animation               *           enterExitanimation;     //进场和出场动画
    QLabel                  *           topLabel;               //顶层栏
    QStackedWidget          *           serialParentWidget;     //用于界面切换
    QSocketNotifier         *           notifier;               //用于监听串口读事件
    int                                 desktopWidth;           //屏幕长度
    int                                 desktopHeight;          //屏幕宽度
    int                                 fd;                     //串口设备节点
    int                                 fd2;                     //485控制IO节点
    char                    *           devName;                //串口设备节点
    QPushButton *pb1;

};

#endif // MAINWINDOW_H
