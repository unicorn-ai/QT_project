#include "serialwidget.h"
#include <QApplication>
#include <QDesktopWidget>

SerialWidget::SerialWidget(QWidget *parent) : QWidget(parent)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    font.setPixelSize(desktopWidth/60);
    this->setFont(font);

    initUI();

}

/**
 * @brief SerialWidget::initSettingUI
 * @note  组件初始化,布局
 */
void SerialWidget::initUI()
{
    sendLineEdit = new QLineEdit(this);
    sendLineEdit->setText("topeet RS485 test\r\n");

    recvPlainEdit = new QPlainTextEdit(this);
    recvPlainEdit->setReadOnly(true);

    editLayout = new QVBoxLayout;
    editLayout->addWidget(sendLineEdit);
    editLayout->addWidget(recvPlainEdit);

    settingBtn = new QPushButton("设置参数",this);
    sendBtn = new QPushButton("发送数据",this);
    cleanBtn =  new QPushButton("清除窗口",this);

    parameterInfoLab = new QLabel(this);
    parameterInfoLab->setText("   请先设置参数");

    btnLayout = new QVBoxLayout;
    btnLayout->addWidget(sendBtn,1);
    btnLayout->addWidget(settingBtn,1);
    btnLayout->addWidget(cleanBtn,1);
    btnLayout->addWidget(parameterInfoLab,5);

    serialLayout = new QHBoxLayout(this);
    serialLayout->addLayout(editLayout,5);
    serialLayout->addLayout(btnLayout,1);

    connect(cleanBtn,SIGNAL(clicked()),this,SLOT(cleanRecvEditSlot()));
}

/**
 * @brief SerialWidget::cleanRecvEditSlot
 * @note  清除接收框内容
 */
void SerialWidget::cleanRecvEditSlot()
{
    recvPlainEdit->clear();
}

