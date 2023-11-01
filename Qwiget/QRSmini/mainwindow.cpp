#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDataStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //serilaPortReadyRead_Slot
    ui->setupUi(this);
    QStringList serialNamePort;
    serilaPort = new QSerialPort(this) ;
    connect(serilaPort,SIGNAL(readyRead()) , this, SLOT(serilaPortReadyRead_Slot()));
   /* {
         timer->start(100);
         buffer.append(serilaPort->readAll());


            };
*/
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        serialNamePort<<info.portName();
    }
    ui->seialCb->addItems(serialNamePort);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serilaPortReadyRead_Slot(){
/*
    QString buf1,buf2;
   // QChar last_char='a';
    buf1 = QString(serilaPort->readAll());
    ui->recvEdit-> appendPlainText(buf1);



    last_char=buf1.at( buf1.length());
   if (last_char=='m'){
        ui->recvEdit-> appendPlainText(buf1);
        buf1="";buf2="";
   }
   else{
   buf2 = QString(serilaPort->readAll());
   buf1.append(buf2);
   buf2="";


    //测试
    QString buffer;
    timer->start(100);
    buffer.append(serilaPort->readAll());
    timer->stop();
    if(buffer.length() !=0)
    {

    ui->recvEdit->appendPlainText(buffer);

    if(buffer.contains( "Package")){

    QString string = buffer;

    QStringList list = string.split( ",");

    //qDebug << "list"<< list[2].toFloat/list[1].toFloat;

    }

    }

    buffer.clear();

*/

    buffer.append(serilaPort->readAll());

    //QByteArray data=buffer;
   // buffer.clear();
    ui->recvEdit-> appendPlainText(buffer);

    }


void MainWindow::serialPort_readyRead(){



}





//void MainWindow::changeButtonText()

//void Widget::on_openBt_clicked()
void MainWindow::on_openBt_clicked()
{
QSerialPort::BaudRate baudRate;
QSerialPort::DataBits dataBits;
QSerialPort::StopBits stopBits;
QSerialPort::Parity checkBits;

if(ui->baundrateCb->currentText()=="4800"){
    baudRate = QSerialPort:: Baud4800;
}else if(ui->baundrateCb->currentText() == "9600"){
    baudRate = QSerialPort :: Baud9600;
}else if(ui->baundrateCb->currentText()== "115200") {
    baudRate = QSerialPort :: Baud115200;
}

if(ui->dateCb->currentText() == "5"){
         dataBits = QSerialPort:: Data5;
}else if(ui->dateCb->currentText() == "6"){
         dataBits = QSerialPort:: Data6;
}else if(ui->dateCb->currentText() =="7"){
         dataBits = QSerialPort :: Data7;
}else if(ui->dateCb->currentText() == "8"){
         dataBits = QSerialPort:: Data8;
}

if(ui->stopCb->currentText() =="1"){
stopBits = QSerialPort:: OneStop;
}else if(ui->stopCb->currentText()== "1.5"){
         stopBits = QSerialPort:: OneAndHalfStop;
}else if(ui->stopCb->currentText()== "2"){
         stopBits = QSerialPort :: TwoStop;
}


if(ui->checkCb->currentText() == "none"){
         checkBits = QSerialPort :: NoParity;
}

//serilaPort->setPort(ui->seialCb->currentText());
serilaPort->setPortName(ui->seialCb->currentText());
serilaPort->setBaudRate(baudRate);
serilaPort->setDataBits(dataBits);
serilaPort->setStopBits(stopBits);
serilaPort->setParity(checkBits);

if(serilaPort->open(QIODevice::ReadWrite)==true){
   QMessageBox::information(this,"提示","成功");
}else{
QMessageBox::critical(this,"提示","未找到串口");}
}


void MainWindow::on_closeBt_clicked()
{
    serilaPort->close();
}

void MainWindow::on_clearBt_clicked()
{
     ui->recvEdit->clear();
}
/*
void MainWindow::slotReadData(){

    if( !temp.isEmpty())
    {
    byteArray.append(temp);
    if(byteArray.contains("#"))
    setText( byteArray.split('#').at(0));
    byteArray = byteArray.right(byteArray.length( )-byteArray.indexOf('#')-1);

    }
    }
 */
 void MainWindow::slotReadData(){


 }


void MainWindow::on_pushButton_3_clicked()
{
    ui->recvEdit->clear();
}
