#include "mainwindow.h"
#include "unistd.h"
#include <sys/ioctl.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置主窗口
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setObjectName("mainWindow");
    this->setGeometry(0,0,desktopWidth,desktopHeight);
    this->setStyleSheet("#mainWindow { background-color: white }");
    pb1 = new QPushButton();
    pb1->setText("等待数据");
    pb1->setGeometry(100,100,180,140);
    //初始化顶层栏
//    initTopWidget();

//    serialParentWidget = new QStackedWidget(this);
//    serialParentWidget->setObjectName("serialParentWidget");
//    serialParentWidget->setGeometry(0,40,desktopWidth,desktopHeight-40);

//    //初始化串口数据收发测试主界面
//    serialWidget = new SerialWidget(serialParentWidget);
//    serialParentWidget->addWidget(serialWidget);
//    serialWidget->resize(serialParentWidget->width(),serialParentWidget->height());

    //初始化串口属性设置界面
//    settingWidget = new SettingWidget(this);
//    serialParentWidget->addWidget(settingWidget);
//    settingWidget->resize(serialParentWidget->width(),serialParentWidget->height());



    //connect(settingWidget->settingBtn,SIGNAL(clicked()),this,SLOT(toDataPageSlot()));
    toDataPageSlot();

    //设置动画
//    enterExitanimation = new Animation(this);
//    enterExitanimation->setGeometry(this->geometry().width()-48,0,48,48); //设置位置
//    enterExitanimation->setAnimationObject(this);//设置动画对象
//    serialParentWidget->setCurrentIndex(0);
    fd = -1;
}

MainWindow::~MainWindow()
{
    delete notifier;
    notifier = NULL;
    if(fd > 0)
    {
        ::close(fd);
        fd = -1;
    }
}

/**
 * @brief MainWindow::initTopWidget
 * @note  初始化顶层栏
 */
void MainWindow::initTopWidget()
{
    QFont font ( "Microsoft YaHei", 30, 60);
    if(desktopWidth >= desktopHeight)
    {
        font.setPointSize(desktopWidth/70);
    } else {
        font.setPointSize((float)10/800*this->geometry().height());
    }

    topLabel = new QLabel(this);
    topLabel->setGeometry(0,0,(float)this->geometry().width(),40);
    topLabel->setStyleSheet("color:rgba(88,88,88,255);"
                            "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0.988636, y2:0, stop:0 rgba(221, 203, 194, 255), stop:1 rgba(255, 255, 255, 255));"
                            "border:0px;");

    QFont topFont ("Microsoft YaHei", 30, 60);
    topFont.setPointSize(23);
    topLabel->setFont(topFont);
    topLabel->setText(" RS485测试系统 RK3568");
}


/**
 * @brief MainWindow::toDataPage
 * @note  保存修改后的串口属性值，使用新属性打开串口,切换到数据收发界面
 */
void MainWindow::toDataPageSlot()
{
    bool ret = false;

    //! 打开串口
    QString serialpath = "/dev/ttyS7";
    devName = serialpath.toLatin1().data();
    ret= openSerialDevice(devName);
    if(!ret){       
        return;
    }

    //! 监听串口可读事件，发现可以读后调用槽函数去读
    notifier = new QSocketNotifier(fd, QSocketNotifier::Read,this);
    connect (notifier, SIGNAL(activated(int)), this, SLOT(recvDataSlot()));

    //! 设置串口属性
    QString baudrateString = "115200";
    QString checkbitString = "None";
    QString stopbitString = "1bit";
    QString databitString = "8bit";
    ret = setSerialAttribute(fd,baudrateString,checkbitString,stopbitString,databitString);
    if(!ret)
    {
        ::close(fd);
        //serialParentWidget->setCurrentIndex(1);
        return;
    }


}

/**
 * @brief MainWindow::openSerialDevice
 * @param name  串口设备名字
 * @return 成功返回true，失败返回false
 */
bool MainWindow::openSerialDevice(char *name)
{
    int errno;
    fd = open(name,O_RDWR|O_NOCTTY|O_NDELAY);
    fd2 = open("/dev/rs485_ctl",O_RDWR|O_NOCTTY|O_NDELAY);
    ioctl(fd2, 0, 0);
    if(fd < 0)
    {
        QMessageBox::critical(NULL, "Error", strerror(errno), QMessageBox::Yes );
        return false;
    }
    return true;
}

/**
 * @brief MainWindow::setSerialAttribute
 * @param devfd             串口设备文件描述符
 * @param speedString       波特率
 * @param checkbitString    校验位
 * @param stopbitString     停止位
 * @param databitString     数据位
 * @return                  成功返回true，失败返回false
 * @note                    使用Linux接口设置串口属性
 */
bool MainWindow::setSerialAttribute(int devfd, QString speedString,
                                    QString checkbitString, QString stopbitString, QString databitString)
{
    int errno;

    struct termios newtio,oldtio;
    if  ( tcgetattr( devfd,&oldtio)  !=  0) {
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        if(fd > 0)
        {
            ::close(fd);
            fd = -1;
        }
        return false;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag |=  CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;

    //! 设置波特率
    int speed = speedString.toInt();
    switch (speed) {
    case 4800:
        cfsetispeed(&newtio, B4800);
        cfsetospeed(&newtio, B4800);
        break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    case 19200:
        cfsetispeed(&newtio, B19200);
        cfsetospeed(&newtio, B19200);
        break;
    case 38400:
        cfsetispeed(&newtio, B38400);
        cfsetospeed(&newtio, B38400);
        break;
    case 57600:
        cfsetispeed(&newtio, B57600);
        cfsetospeed(&newtio, B57600);
        break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
        break;
    case 230400:
        cfsetispeed(&newtio, B230400);
        cfsetospeed(&newtio, B230400);
        break;
    case 460800:
        cfsetispeed(&newtio, B460800);
        cfsetospeed(&newtio, B460800);
        break;
    default:
        break;
    }

    //! 设置校验位
    if(checkbitString == "odd")
    {
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
    }else if(checkbitString == "Even"){
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
    }else if(checkbitString == "None"){
        newtio.c_cflag &= ~PARENB;
    }

    //! 设置停止位
    int stopbit = stopbitString.mid(0,1).toInt();
    switch (stopbit) {
    case 1 :
        newtio.c_cflag &=  ~CSTOPB;
        break;
    case 2 :
        newtio.c_cflag |=  CSTOPB;
        break;
    default:
        break;
    }

    //! 设置数据位
    int databit = databitString.mid(0,1).toInt();
    switch( databit )
    {
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    default:
        break;
    }

    //! 设置串口属性
    newtio.c_cc[VTIME]  = 0;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(devfd,TCSANOW,&newtio))!=0)
    {
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        if(fd > 0)
        {
            ::close(fd);
            fd = -1;
        }
        return false;
    }
    return true;
}
/**
 * @brief MainWindow::recvDataSlot
 * @note  接收数据槽函数
 */
//! 每次读取的字节
#define READ_BUFFER_SIZE 128
void MainWindow::recvDataSlot()
{
    int errno;
    char buffer[READ_BUFFER_SIZE];
    memset(buffer, 0, READ_BUFFER_SIZE);
    ioctl(fd2, 0, 0);
    if (read(fd, buffer, READ_BUFFER_SIZE) < 0)
    {
        QMessageBox::critical(this, "Error", strerror(errno), QMessageBox::Yes );
        return;
    }
//    serialWidget->recvPlainEdit->appendPlainText("接收：");
//    serialWidget->recvPlainEdit->appendPlainText(QString(buffer));
    pb1->setText(QString(buffer));
}

