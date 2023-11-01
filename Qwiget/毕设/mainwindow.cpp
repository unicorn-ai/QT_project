#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QAxObject>
int MainWindow::num3=1;
int MainWindow::s_d[8]={0,0,0,0,0,0,0,0};
//监控数据初始阈值
int MainWindow::max_temper_alarm=14;
int MainWindow::min_temper_alarm=5;
int MainWindow::max_ISO_alarm=24;
int MainWindow::min_ISO_alarm=5;
int MainWindow::max_voltage_alarm=24;
int MainWindow::min_voltage_alarm=5;
int MainWindow::max_current_alarm=14;
int MainWindow::min_current_alarm=5;


int MainWindow::num1=0;
double MainWindow::SO2[40];
double MainWindow::WEN[10]={1,2,3,4,5,1,2,3,4,5,};
double MainWindow::SHI[10]={1,2,3,4,5,1,2,3,4,5,};
double MainWindow::SHUI[10]={1,2,3,4,5,1,2,3,4,5,};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui_init();
    lineInit();
    roundPeogreInit();
    Device_alarm();

    //MQTT部分
    clientMqtt();
//    timer_mqtt = new QTimer(this);//设置定时器1000毫秒发送一个timeout()信号
//    timer_mqtt->start(2000);
//    connect(timer_mqtt, SIGNAL(timeout()), this,
//            SLOT(send_message(QString data)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ui_init()
{

    //this->setGeometry(0,0,screenWidth,screenHeigh);
    QList <QScreen *> list_screen =  QGuiApplication::screens();
//    screenWidth=list_screen.at(0)->geometry().width();
//    screenHeigh=list_screen.at(0)->geometry().height();
    this->setGeometry(0,0,screenWidth,screenHeigh);
    QString c,d;
    c = QString::number(screenHeigh);
    c.append("x");
    d = QString::number(screenWidth);
    c.append(d);
    //ui->pushButton_4->setText(c);

    QStringList list;
    //list << "#MainWindow{border:1px solid #041d48;border-image: url(:/img/bg01.png);}";
    this->setStyleSheet(list.join(""));
    ui->label_2->setGeometry(0,0,screenWidth,0.1*screenHeigh);
    //ui->label_11->setGeometry(0.5*screenWidth-180,0,360,100);
    ui->pushButton->setGeometry(0.78*screenWidth+5,0.08*screenHeigh,screenWidth/15,screenHeigh/15);
    ui->pushButton_2->setGeometry(0.86*screenWidth,0.08*screenHeigh,screenWidth/15,screenHeigh/15);
    ui->pushButton_3->setGeometry(screenWidth*14/15,0.08*screenHeigh,screenWidth/15,screenHeigh/15);

    sw2_w=screenWidth;
    sw2_H=0.76*screenHeigh;
    sw_w=screenWidth;
    sw_H=0.76*screenHeigh;
    ui->stackedWidget_2->setGeometry(0,0.08*screenHeigh,screenWidth,0.82*screenHeigh);
    ui->stackedWidget->setGeometry(0,0.08*screenHeigh,screenWidth,0.82*screenHeigh);
    ui->widget_2->setGeometry(0.0174*sw_w,0.02*sw_H,0.479*sw_w,0.409*sw_H);
    ui->widget_3->setGeometry(0.504*sw_w,0.02*sw_H,0.479*sw_w,0.409*sw_H);
    ui->widget_4->setGeometry(0.0174*sw_w,0.449*sw_H,0.479*sw_w,0.409*sw_H);
    ui->widget_5->setGeometry(0.504*sw_w,0.449*sw_H,0.479*sw_w,0.409*sw_H);
//    ui->push4->setGeometry(sw_w*0.5-screenWidth/40,0.98*sw_H,screenWidth/20,screenHeigh/20);
//ui->pushButton_4->setGeometry(sw_w*0.5-screenWidth/40,0.897*sw_H,screenWidth/20,screenHeigh/20);

    ui->label_5->setGeometry(0.0174*sw_w,0.04*sw_H,0.33*sw_w,0.82*sw_H);
    ui->label_7->setGeometry(0.65*sw_w,0.04*sw_H,0.33*sw_w,0.82*sw_H);
    ui->label_3->setGeometry(0.38*sw_w,0.2*sw_H,0.25*sw_w,0.59*sw_H);
    ui->label_9->setGeometry(0.66*sw_w,0.04*sw_H,0.3*sw_w,0.04*sw_H);
    ui->widget->setGeometry(0.66*sw_w,0.1*sw_H,0.3125*sw_w,0.74*sw_H);
    ui->label_8->setGeometry(0.65*sw_w,0.04*sw_H,0.3*sw_w,0.04*sw_H);
//    ui->label_6->setGeometry(0.026*sw_w,0.04*sw_H,0.296*sw_w,0.11*sw_H);
//    ui->label->setGeometry(0.017*sw_w,0.04*sw_H,0.31*sw_w,0.04*sw_H);
    ui->tableWidget->setGeometry(40,0.154*sw_H,sw_w-80,sw_H-150);//(40,0.154*sw_H,sw_w-80,sw_H-20);
    //ui->pushButton_5->setGeometry(sw_w*0.347,0.98*sw_H,screenWidth/20,screenHeigh/20);
    //ui->pushButton_6->setGeometry(sw_w*0.601,0.98*sw_H,screenWidth/20,screenHeigh/20);
//    ui->pushButton_6->setGeometry(sw_w*0.649,0.98*sw_H,screenWidth/20,screenHeigh/20);
    //ui->label_11->setGeometry(0.5*sw_w-166,0,450,100);
    ui->label_11->setGeometry(405,10,340,40);

}

void MainWindow::Device_alarm()
{
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setColumnWidth(0,0.25*(sw_w-80));
    ui->tableWidget->setColumnWidth(1,0.15*(sw_w-80));
    ui->tableWidget->setColumnWidth(2,0.45*(sw_w-80));
    ui->tableWidget->setColumnWidth(3,0.15*(sw_w-80));
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("报警时间"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("报警设备"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("详细情况"));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("严重性"));
//    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("2023.01.09"));
//    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("STM32"));
//    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("环境温度过高"));
    //ui->tableWidget->setText
}

void MainWindow::lineInit()
{
    QVector<QString> line_name = {"","环境温度","光强","设备电压","设备电流",""};
    lineSty.append(ui->widget);
    lineSty.append(ui->widget_2);
    lineSty.append(ui->widget_3);
    lineSty.append(ui->widget_4);
    lineSty.append(ui->widget_5);
    //lineSty.append(ui->plot_6);
    for(int i = 0; i < lineSty.size(); i ++)
    {
        QCPTextElement *textelement = new QCPTextElement(lineSty[i], line_name[i],QFont("sans", 17, QFont::Bold));
        textelement->setTextColor(QColor(0,0,0));
        titel.append(textelement);
    }
    for(int i = 0; i < lineSty.size(); i ++)
    {
        QSharedPointer<QCPAxisTickerDateTime> dateTick(new QCPAxisTickerDateTime);
        dateTick->setDateTimeFormat("HH:mm:ss");
        lineSty[i] ->xAxis->setTicker(dateTick);
        lineSty[i]->plotLayout()->insertRow(0);
        lineSty[i]->plotLayout()->addElement(0, 0, titel[i]);
        lineSty[i]->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                            QCP::iSelectLegend | QCP::iSelectPlottables);//允许鼠标点击拖动
        lineSty[i]->setBackground(QColor(255, 255, 255));
        //lineSty[i]->setBackground(QColor(2, 54, 109));
        lineSty[i]->legend->setVisible(true);
        lineSty[i]->legend->setBrush(QColor(255,255,255,150));//legend背景色设为白色但背景透明，允许图像在legend区域可见


        lineSty[i]->xAxis->setLabelColor(QColor(0, 0, 0));   //XY轴的名字
        lineSty[i]->xAxis->setBasePen(QColor(0, 0, 0));//x轴颜色
        lineSty[i]->xAxis->setTickPen(QColor(0, 0, 0));//设置x坐标线上 大 分格线颜色
        lineSty[i]->xAxis->setSubTickPen(QColor(0, 0, 0));//设置x坐标线上小分格线颜色
        lineSty[i]->xAxis->setTickLabelColor(QColor(0, 0, 0));


        lineSty[i]->yAxis->setLabelColor(QColor(0, 0, 0));   //XY轴的名字
        lineSty[i]->yAxis->setBasePen(QColor(0, 0, 0));//设置y坐标线颜色
        lineSty[i]->yAxis->setTickPen(QColor(0, 0, 0));//设置x坐标线上 大 分格线颜色
        lineSty[i]->yAxis->setSubTickPen(QColor(0, 0, 0));//设置x坐标线上小分格线颜色
        lineSty[i]->yAxis->setTickLabelColor(QColor(0, 0, 0));

        lineSty[i]->addGraph();

        //数据线样式设计
        //lineSty[i]->graph(0)->setPen(QColor(27, 254, 51));
        lineSty[i]->graph(0)->setPen(QPen(QColor(0,0,0),4));
        if(i==0)
        {
            lineSty[i]->xAxis->setRange(0,40);
            lineSty[i]->yAxis->setRange(9,15);
            lineSty[i]->yAxis->setLabel("温度/V");
            lineSty[i]->xAxis->setLabel("时间/s");   //XY轴的名字
            lineSty[i]->graph(0)->setName("监测温度");
        }

       else if(i==1)
       {
           lineSty[i]->xAxis->setRange(0,40);
           lineSty[i]->yAxis->setRange(9,15);
           lineSty[i]->yAxis->setLabel("温度/C");
           lineSty[i]->xAxis->setLabel("时间/s");   //XY轴的名字
           lineSty[i]->graph(0)->setName("监测温度");
       }
        else if(i==2)
       {
           lineSty[i]->xAxis->setRange(0,40);
           lineSty[i]->yAxis->setRange(9,15);
           lineSty[i]->yAxis->setLabel("光照强度/lx");
           lineSty[i]->xAxis->setLabel("时间/s");   //XY轴的名字
           lineSty[i]->graph(0)->setName("监测光强");
       }
       else if(i==3)
      {
          lineSty[i]->xAxis->setRange(0,40);
          lineSty[i]->yAxis->setRange(9,15);
          lineSty[i]->yAxis->setLabel("电压/V");
          lineSty[i]->xAxis->setLabel("时间/s");   //XY轴的名字
          lineSty[i]->graph(0)->setName("监测电压");
      }
       else if(i==4)
      {
          lineSty[i]->xAxis->setRange(0,40);
          lineSty[i]->yAxis->setRange(9,15);
          lineSty[i]->yAxis->setLabel("电流/A");
          lineSty[i]->xAxis->setLabel("时间/s");   //XY轴的名字
          lineSty[i]->graph(0)->setName("监测电流");
      }
    }
}

void MainWindow::roundPeogreInit()
{

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout,this,[this]{

        //key的单位是秒
        x_time = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
        //这里的8，是指横坐标时间宽度为8秒，如果想要横坐标显示更多的时间
        //就把8调整为比较大到值，比如要显示60秒，那就改成60。
        for(int i = 0; i < lineSty.size(); i++)
        {
            lineSty[i]->xAxis->setRange(x_time+0.25, 8, Qt::AlignRight);//设定x轴的范围
            lineSty[i]->replot();
        }
        QString data="温度:C;光强:cd;电压:V;电流:A";
        static double constant = 10;
        for(int i = 1; i < 5; ++i)
        {
            int temp = qrand() % 5 + 1;
            int n = qrand() % 5;    //产生100以内的随机整数
            double fn = n / (temp * 1.0);   //产生10以内的随机浮点数，精度为小数点后1位
            //写入随机变量
            for(int iq = 0; iq<= 39; iq++)
            {
                int temp = qrand() % 5 + 1;
                int n = qrand() % 5;    //产生100以内的随机整数
                double fn = n / (temp * 1.0);   //产生10以内的随机浮点数，精度为小数点后1位
                SO2[iq]=fn;
                if (fn==0){iq=iq-1;}

            }
            if(i==1){
                lineSty[0]->graph(0)->addData(x_time, constant + fn);//添加数据1到温度曲线
                lineSty[1]->graph(0)->addData(x_time, constant + fn);
                data.insert(3,QString::number(fn+10 ,'f',2));
                temper=fn+10;
                if(((temper<=min_temper_alarm)||(temper>=max_temper_alarm))==1)
                {
                    on_pushButton_4_clicked(0);
                    qDebug() << "\r最小温度值:" << min_temper_alarm <<
                                "最大温度值:" << max_temper_alarm<<"当前"<<temper;

                }
            }

            if(i==2){
                lineSty[i]->graph(0)->addData(x_time, constant + fn);
                data.insert(13,QString::number(fn+10,'f',2));
                ISO=fn+10;
                if(((ISO<=min_ISO_alarm)||(ISO>=max_ISO_alarm))==1)
                {
                    on_pushButton_4_clicked(1);
                   qDebug() << "\r最小ISO:" << min_ISO_alarm<< "最大ISO:" << max_ISO_alarm<<"当前"<<ISO;

                }
            }
            if(i==3){
                lineSty[i]->graph(0)->addData(x_time, constant + fn);
                data.insert(24,QString::number(fn+10 ,'f',2));
                voltage=fn+10;
                if(((voltage<=min_voltage_alarm)||(voltage>=max_voltage_alarm))==1)
                {
                    on_pushButton_4_clicked(2);

                   qDebug() << "\r最小电压值:" << min_voltage_alarm << "最大电压值:" <<
                               max_voltage_alarm<<"当前"<<voltage;

                }
            }
            if(i==4){
                lineSty[i]->graph(0)->addData(x_time, constant + fn);
                data.insert(34,QString::number(fn+10 ,'f',2));
                current=fn+10;
                if(((current<=min_current_alarm)||(current>=max_current_alarm))==1)
                {on_pushButton_4_clicked(3);
                    qDebug() << "\r最小电流值:" << min_current_alarm <<
                                "最大电流值:" << max_current_alarm<<"当前"<<current;

                }
            }

        }
        //QString tp="温度:30.49C;光强:75.11cd;电压:20.20V;电流:10.23A";
        send_message(data);
        data="";
        //qDebug() << "\r\n数据序列清空： " << data;

    });
    timer->start(1000);

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked(int s)
{
    for(int i = 0; i < 4; i++)
    {//QString::number(fn+10 ,'f',2)   new QTableWidgetItem("2022.12.23")

//        QDate time=QDate::currentDate();
//        QString Time=time.toString("yyyy-MM-dd");
        QDateTime time=QDateTime::currentDateTime();
        QString Time=time.toString("yyyy-MM-dd hh:mm:ss");

        if(i==0){ui->tableWidget->setItem(Device_alarm_number, i, new QTableWidgetItem(Time));}
        else if(i==1){ui->tableWidget->setItem(Device_alarm_number, i, new QTableWidgetItem("STM32"));}
        //if(i==2){ui->tableWidget->setItem(Device_alarm_number, i, new QTableWidgetItem(""));}
        else if(i==3){ui->tableWidget->setItem(Device_alarm_number, i, new QTableWidgetItem("一般"));}
        else {}
    }
    switch (s) {
    case 0:ui->tableWidget->setItem(Device_alarm_number, 2, new QTableWidgetItem("温度异常"));break;
    case 1:ui->tableWidget->setItem(Device_alarm_number, 2, new QTableWidgetItem("环境光强异常"));break;
    case 2:ui->tableWidget->setItem(Device_alarm_number, 2, new QTableWidgetItem("电压异常"));break;
    case 3:ui->tableWidget->setItem(Device_alarm_number, 2, new QTableWidgetItem("电流异常"));break;
    default:break;
    }
    Device_alarm_number++;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(0);
}

//数据导出
//void MainWindow::on_pushButton_6_clicked()
//{
//     QString fileName = QFileDialog::getSaveFileName(this,tr("Excle file"),QString("./paper_list.xlsx"),tr("Excel Files(*.xlsx)"));    //设置保存的文件名
//        if(fileName != "")
//        {
//            QAxObject *excel = new QAxObject;
//            if(excel->setControl("Excel.Application"))
//            {
//                excel->dynamicCall("SetVisible (bool Visible)",false);
//                excel->setProperty("DisplayAlerts",false);
//                QAxObject *workbooks = excel->querySubObject("WorkBooks");            //获取工作簿集合
//                workbooks->dynamicCall("Add");                                        //新建一个工作簿
//                QAxObject *workbook = excel->querySubObject("ActiveWorkBook");        //获取当前工作簿
//                QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
//                QAxObject *cell;

//                tablewidget_row=4;
//                tablewidget_column=4;//列
//                /*将form列表中的数据依此保存到Excel文件中*/
//                ui->tableWidget->setColumnCount(tablewidget_row);
//                for(int j = 2; j<=(tablewidget_row+1);j++)
//                {
//                    for(int k = 1;k<=tablewidget_column;k++)
//                    {
//                        cell=worksheet->querySubObject("Cells(int,int)", j, k);
//                        if(ui->tableWidget->item(j-2,k-1)!=NULL){

//                            cell->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(j-2,k-1)->text()+ "\t");
//                        }
//                    }
//                }
//                /*将生成的Excel文件保存到指定目录下*/
//                workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName)); //保存至fileName
//                workbook->dynamicCall("Close()");                                                   //关闭工作簿
//                excel->dynamicCall("Quit()");                                                       //关闭excel
//                delete excel;
//                excel=NULL;
//                if (QMessageBox::question(NULL,QString::fromUtf8("完成"),QString::fromUtf8("文件已经导出，是否现在打开？"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
//                {
//                    QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
//                }

//            }
//        }

//}

//报警阈值设置
void MainWindow::on_pushButton_5_clicked()
{
Dialog *dia =new Dialog ;
//dia->setGeometry(this->geometry());
dia->show();




}
void MainWindow::do_sd()
{
    max_temper_alarm=s_d[0];
    min_temper_alarm=s_d[1];
    max_ISO_alarm=s_d[2];
    min_ISO_alarm=s_d[3];
    max_voltage_alarm=s_d[4];
    min_voltage_alarm=s_d[5];
    max_current_alarm=s_d[6];
    min_current_alarm=s_d[7];

};
void MainWindow::get_data(int a)
{
    num+=1;
    if(num%8==1){s_d[0]=a;}
    if(num%8==2){s_d[1]=a;}
    if(num%8==3){s_d[2]=a;}
    if(num%8==4){s_d[3]=a;}
    if(num%8==5){s_d[4]=a;}
    if(num%8==6){s_d[5]=a;}
    if(num%8==7){s_d[6]=a;}
    if(num%8==0){s_d[7]=a;}
    do_sd();

}

//void MainWindow::on_pushButton_4_clicked()
//{
//    qDebug() << "\r数据新序列：" << s_d[0]<< s_d[1]<< s_d[2]<< s_d[3]<< s_d[4]<< s_d[5]
//                << s_d[6]<< s_d[7];
//    int a=s_d[2];
//    qDebug() << "\r更新：" << s_d[0]<< s_d[1]<< a;
//    //qDebug() << "\r更新num1：" << num1;
//    qDebug() << "\r更新last：" << s_d[0]<< s_d[1]<< s_d[2];
//    max_temper_alarm= s_d[2];
//    qDebug() << "\r更新max_temper_alarm：" <<max_temper_alarm ;
//}





//MQTT部分

void MainWindow::clientMqtt() {
    client = new QMQTT::Client(); // 初始化QMQTT客户指针

    connect(client, SIGNAL(received(QMQTT::Message)),this, SLOT(onMQTT_Received(QMQTT::Message)));
    connect(client, SIGNAL(subscribed(QString,quint8)), this, SLOT(onMQTT_subscribed(QString,quint8)) );
    connect(client, SIGNAL(unsubscribed(QString)), this, SLOT( onMQTT_unSubscribed(QString)));
    // oneNet server //
    QHostAddress host("183.230.40.39"); // 代理服务器 IP
    QByteArray password = "test"; // 设备名称
    quint16 port = 6002; // 代理服务器端口
    QString deviceId = "1009121288"; // 设备 ID
    QString productId = "502379";   // 产品 ID

    client->setKeepAlive(120); // 心跳
    client->setHost(host); // 设置 EMQ 代理服务器
    client->setPort(port); // 设置 EMQ 代理服务器端口
    client->setClientId(deviceId); // 设备 ID
    client->setUsername(productId); // 产品 ID
    client->setPassword(QByteArray(QString("231274").toStdString().c_str()));
    client->cleanSession();
    client->setVersion(QMQTT::MQTTVersion::V3_1_1); // 设置mqtt版本


    client->connectToHost(); // 连接 EMQ 代理服务器

    QTimer::singleShot(1000, this, [=](){
        client->subscribe("abcd",0);
    });
}

void MainWindow::onMQTT_Received(QMQTT::Message message) {
    QString str = message.payload();
    qDebug() <<"\nTopic: " << message.topic() << "payload:" <<str;
}

void MainWindow::onMQTT_subscribed(QString topic, quint8 qos) {
    qDebug() << "\n订阅topic = " << topic << "Qos = " << qos << " 成功!";
}

void MainWindow::onMQTT_unSubscribed(QString topic) {
    qDebug() << "\nonMQTT_unSubscribed:" << topic;//"Humidity:%d,"
}

void MainWindow::send_message(QString data)
{
    QString topic = "QT_SD";
//    int temp = qrand() %8 + 1;
//    int n = qrand() %8;    //产生100以内的随机整数
//    double fn = n / (temp * 1.0);
//    QString send=QString::number(fn ,'f',2);
//    QString send1="温度:30.49C;光强:75.11cd;电压:20.20V;电流:10.23A";
    QMQTT::Message message(136,topic,data.toUtf8());
    client->publish(message);
    //qDebug() << "\r数据序列： " << data;
}




//报警数据导出
void MainWindow::on_pushButton_6_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Excle file"),QString("./paper_list.xlsx"),tr("Excel Files(*.xlsx)"));    //设置保存的文件名

    if(fileName != "")
    {
        QAxObject *excel = new QAxObject;
        if(excel->setControl("Excel.Application"))
        {
            excel->dynamicCall("SetVisible (bool Visible)",false);
            excel->setProperty("DisplayAlerts",false);
            QAxObject *workbooks = excel->querySubObject("WorkBooks");            //获取工作簿集合
            workbooks->dynamicCall("Add");                                        //新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");        //获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
            QAxObject *cell;

            int tablewidget_row=18;
            int tablewidget_column=5;//列
            /*将form列表中的数据依此保存到Excel文件中*/
            ui->tableWidget->setColumnCount(tablewidget_row);
            for(int j = 2; j<=(tablewidget_row+1);j++)
            {
                for(int k = 1;k<=tablewidget_column;k++)
                {
                    cell=worksheet->querySubObject("Cells(int,int)", j, k);
                    if(ui->tableWidget->item(j-2,k-1)!=NULL){

                        cell->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(j-2,k-1)->text()+ "\t");
                    }
                }
            }
            /*将生成的Excel文件保存到指定目录下*/
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName)); //保存至fileName
            workbook->dynamicCall("Close()");                                                   //关闭工作簿
            excel->dynamicCall("Quit()");                                                       //关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,QString::fromUtf8("完成"),QString::fromUtf8("文件已经导出，是否现在打开？"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }

        }
    }
}

//历史数据导出
void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Excle file"),QString("./paper_list.xlsx"),tr("Excel Files(*.xlsx)"));    //设置保存的文件名
    if(fileName != "")
       {
           QAxObject *excel = new QAxObject;
           if(excel->setControl("Excel.Application"))
           {
               excel->dynamicCall("SetVisible (bool Visible)",false);
               excel->setProperty("DisplayAlerts",false);
               QAxObject *workbooks = excel->querySubObject("WorkBooks");            //获取工作簿集合
               workbooks->dynamicCall("Add");                                        //新建一个工作簿
               QAxObject *workbook = excel->querySubObject("ActiveWorkBook");        //获取当前工作簿
               QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
               QAxObject *cell;

               int tablewidget_row=5;
               int tablewidget_column=10;//列
               /*将form列表中的数据依此保存到Excel文件中*/
               ui->tableWidget->setColumnCount(tablewidget_row);

               QDateTime time=QDateTime::currentDateTime();
               QString Time=time.toString("yyyy-MM-dd");
//               QString h=QString::number(QTime::currentTime().minute());
//               QString s=QString::number(QTime::currentTime().second());
               int m1=0,h1=0;
               h1=QTime::currentTime().hour();
               m1=QTime::currentTime().minute();

//                h=QString::number(QTime::currentTime().hour());
//

               for(int j = 1; j<=(tablewidget_row);j++)
               {
                   for(int k = 1;k<=tablewidget_column;k++)
                   {
                       //cell=worksheet->querySubObject("Cells(int,int)", k, j+1);
                       if (j==1){

                           QString h=QString::number(h1);

                           QString m=QString::number(m1);
                            //QString Time=time.toString("yyyy-MM-dd hh:mm:")+QString::number(QTime::currentTime().second());
                           QString TS=Time+"   "+h+":"+m;

                           cell=worksheet->querySubObject("Cells(int,int)", k+1, j);
                           cell->dynamicCall("SetValue(const QString&)",TS);//将数据写入excel表格
                           m1=m1-1;
                           if(m1<0){h1=h1-1;m1=59;}
                       }
                       else{
                           cell=worksheet->querySubObject("Cells(int,int)", k+1, j);
                           QString tp1 = QString::number(SO2[num1],'f', 3);
                          // QString tp = QString::number(num1,'f', 3);//将数据转为QSTRING类型暂存于tp中
                           cell->dynamicCall("SetValue(const QString&)",tp1);//将数据写入excel表格
                           num1++;}

                   }
               }




               cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
               cell->dynamicCall("SetValue(const QString&)","时间");//将数据写入excel表格
               cell=worksheet->querySubObject("Cells(int,int)", 1, 2);
               cell->dynamicCall("SetValue(const QString&)","环境温度(摄氏度)");//将数据写入excel表格
               cell=worksheet->querySubObject("Cells(int,int)", 1,3 );
               cell->dynamicCall("SetValue(const QString&)","环境光强(勒克斯)");//将数据写入excel表格
               cell=worksheet->querySubObject("Cells(int,int)", 1, 4);
               cell->dynamicCall("SetValue(const QString&)","设备电压(伏特)");//将数据写入excel表格
               cell=worksheet->querySubObject("Cells(int,int)", 1, 5);
               cell->dynamicCall("SetValue(const QString&)","设备电流(安培)");//将数据写入excel表格

               /*将生成的Excel文件保存到指定目录下*/
               workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName)); //保存至fileName
               workbook->dynamicCall("Close()");                                                   //关闭工作簿
               excel->dynamicCall("Quit()");                                                       //关闭excel
               delete excel;
               excel=NULL;
               if (QMessageBox::question(NULL,QString::fromUtf8("完成"),QString::fromUtf8("文件已经导出，是否现在打开？"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
               {
                   QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
               }

           }
       }
}
