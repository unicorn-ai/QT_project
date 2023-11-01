#include "settingwidget.h"
#include <QApplication>
#include <QDesktopWidget>


SettingWidget::SettingWidget(QWidget *parent) : QWidget(parent)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    initComBox();
    initLabel();
    initLayout();

    settingBtn->setText(" 打开串口");
}


/**
 * @brief SettingWidget::initComBox
 * @note  下拉框组件初始化
 */
void SettingWidget::initComBox()
{
    ttycomComBox  = new QComboBox(this);
    baudrateComBox = new QComboBox(this);
    checkbitComBox = new QComboBox(this);
    stopbitComBox = new QComboBox(this);
    databitComBox = new QComboBox(this);

    ttycomComBox->clear();
    QStringList serialNamePort;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serialNamePort << info.portName();
    }
    ttycomComBox->addItems(serialNamePort);

    baudrateComBox->addItem("4800");
    baudrateComBox->addItem("9600");
    baudrateComBox->addItem("19200");
    baudrateComBox->addItem("38400");
    baudrateComBox->addItem("57600");
    baudrateComBox->addItem("115200");
    baudrateComBox->addItem("230400");
    baudrateComBox->addItem("460800");
    baudrateComBox->setCurrentIndex(6);

    checkbitComBox->addItem("None");
    checkbitComBox->addItem("odd");
    checkbitComBox->addItem("Even");
    checkbitComBox->setCurrentIndex(0);

    stopbitComBox->addItem("1bit");
    stopbitComBox->addItem("2bit");
    stopbitComBox->setCurrentIndex(0);

    databitComBox->addItem("7bit");
    databitComBox->addItem("8bit");
    databitComBox->setCurrentIndex(1);
}

/**
 * @brief SettingWidget::initLabel
 * @note  下拉框左边标签初始化
 */
void SettingWidget::initLabel()
{
    ttycomLab = new QLabel("端口号:",this);
    baudrateLab = new QLabel("波特率:",this);
    checkbitLab = new QLabel("校验位:",this);
    stopbitLab = new QLabel("停止位:",this);
    databitLab = new QLabel("数据位:",this);

    ttycomLab->setBuddy(ttycomComBox);
    baudrateLab->setBuddy(baudrateComBox);
    checkbitLab->setBuddy(checkbitComBox);
    stopbitLab->setBuddy(stopbitComBox);
    databitLab->setBuddy(databitComBox);

    ttycomLab->setAlignment(Qt::AlignRight);
    baudrateLab->setAlignment(Qt::AlignRight);
    checkbitLab->setAlignment(Qt::AlignRight);
    stopbitLab->setAlignment(Qt::AlignRight);
    databitLab  ->setAlignment(Qt::AlignRight);
}

/**
 * @brief SettingWidget::initLayout
 * @note  界面布局
 */
void SettingWidget::initLayout()
{
    settingBtn = new QPushButton(this);
    settingLayout = new QGridLayout(this);
    settingLayout->setContentsMargins((desktopWidth-480)/2,(desktopHeight-40-233)/2+40,(desktopWidth-480)/2, (desktopHeight-40-233)/2);

    settingLayout->addWidget(ttycomLab,0,0,1,1);
    settingLayout->addWidget(ttycomComBox,0,2,1,3);
    settingLayout->addWidget(baudrateLab,0,6,1,1);
    settingLayout->addWidget(baudrateComBox,0,8,1,3);
    settingLayout->addWidget(checkbitLab,1,0,1,1);
    settingLayout->addWidget(checkbitComBox,1,2,1,3);
    settingLayout->addWidget(stopbitLab,1,6,1,1);
    settingLayout->addWidget(stopbitComBox,1,8,1,3);
    settingLayout->addWidget(databitLab,2,0,1,1);
    settingLayout->addWidget(databitComBox,2,2,1,3);
    settingLayout->addWidget(settingBtn,4,4,1,2);

}



