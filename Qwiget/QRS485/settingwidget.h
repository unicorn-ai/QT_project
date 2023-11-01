#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H
/**
 * @fileName      settingwidget.h
 * @brief         串口属性设置窗口UI
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
#include <QSerialPortInfo>

class SettingWidget : public QWidget
{
    Q_OBJECT


public:
    explicit SettingWidget(QWidget *parent = 0);

    void initComBox();                              //初始化下拉框组件
    void initLabel();                               //初始化下拉框左边的标签
    void initLayout();                              //布局

    QLabel          *       ttycomLab;              //串口节点名字选择标签
    QLabel          *       baudrateLab;            //波特率选择标签
    QLabel          *       checkbitLab;            //校验位选择标签
    QLabel          *       databitLab;             //数据位选择标签
    QLabel          *       stopbitLab;             //停止位选择标签
    QComboBox       *       ttycomComBox;           //串口节点名字下拉框
    QComboBox       *       baudrateComBox;         //波特率下拉框
    QComboBox       *       checkbitComBox;         //校验位下拉框
    QComboBox       *       databitComBox;          //数据为下拉框
    QComboBox       *       stopbitComBox;          //停止位下拉框
    QPushButton     *       settingBtn;             //打开串口并设置属性参数按钮
    QGridLayout     *       settingLayout;          //窗口布局
    int                     desktopWidth;           //屏幕长度
    int                     desktopHeight;          //屏幕宽度

signals:

public slots:

};

#endif // SETTINGWIDGET_H
