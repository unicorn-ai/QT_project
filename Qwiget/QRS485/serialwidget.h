#ifndef SERIALWIDGET_H
#define SERIALWIDGET_H

/**
 * @fileName      serialwidget.h
 * @brief         数据接收发送编辑界面，串口控制主界面
 * @author        topeet
 * @date          2021-04-26
 */

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QFont>

#include "settingwidget.h"

class SerialWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SerialWidget(QWidget *parent = 0);

    void initUI();

public:
    QPushButton     *       sendBtn;                //发送数据按钮
    QPushButton     *       settingBtn;             //设置属性按钮
    QPushButton     *       cleanBtn;               //清除接收框按钮
    QLabel          *       parameterInfoLab;       //属性显示标签
    QLineEdit       *       sendLineEdit;           //发送数据编辑栏
    QPlainTextEdit  *       recvPlainEdit;          //接收数据窗口

signals:

public slots:
    void cleanRecvEditSlot();                       //清除接收框数据

private:
    QVBoxLayout     *       editLayout;             //左侧数据编辑窗口布局
    QVBoxLayout     *       btnLayout;              //右侧按钮和属性显示布局
    QHBoxLayout     *       serialLayout;           //主窗口布局
    QFont                   font;                   //字体
    int                     desktopWidth;           //屏幕长度
    int                     desktopHeight;          //屏幕宽度
};

#endif // SERIALWIDGET_H
