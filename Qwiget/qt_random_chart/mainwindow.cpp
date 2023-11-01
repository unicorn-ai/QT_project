#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 800, 800);
    //pushButton = new QPushButton(this);
//    pb_close1 = new QPushButton(this);
//    pb_close1->setGeometry(540, 200, 200, 100);
    //pushButton->setGeometry(540, 200, 200, 100);
    chart_init();
    timer = new QTimer(this);//设置定时器1000毫秒发送一个timeout()信号
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this,
            SLOT(time_out_clicked()));

/*

            for(int i=0;i<10;++i)
        {
           if(i%2){
               seriesx->append(i,i*0.37+1);//奇数
               seriesx1->append(i,i*0.2+3);
           }
           else{
               seriesx->append(i,i*0.08+1);//偶数
               seriesx1->append(i,i*0.9+1);
           }

        }

        _chart_view->chart()->addSeries(seriesx);
        _chart_view->chart()->addSeries(seriesx1);
        _chart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);
        seriesx->setName("光照强度");
        seriesx1->setName("电流值");
        seriesx->setColor("cyan");
        seriesx1->setColor("orange");
        QFont font("Times", 25, QFont::Fantasy);
        _chart_view->chart()->setTitle("嵌入式电力网关");
        _chart_view->chart()->setTitleFont(font);
        QValueAxis *axisx = new QValueAxis;
        //QDateTimeAxis *axisx = new QDateTimeAxis;
        axisx->setTitleText("time");
        //_chart_view->chart()->setAxisX(axisx, seriesx);
        _chart_view->chart()->setAxisX(axisx, seriesx1);
        QValueAxis *axisy = new QValueAxis;
        axisy->setTitleText("height(meter)");
        //_chart_view->chart()->setAxisY(axisy,seriesx);
        _chart_view->chart()->setAxisY(axisy,seriesx1);
        _chart_view->chart()->legend()->setVisible(true);
        _chart_view->chart()->legend()->setAlignment(Qt::AlignBottom);
*/
/*
    for(int i=0;i<32;i++){
        if(i<16){chart_data[i]=0;}
        else{
            if((i>=20)&&(i<29)){
                chart_data[i]=(double)i*0.075+4;//奇数
            }
            else if((i>=17)&&(i<20)){
                chart_data[17]=1.5;
                chart_data[18]=12;
                chart_data[19]=0.5;

            }
            else if(i>=29){
                chart_data[31]=11.5;
                chart_data[30]=1;
                chart_data[29]=8;
            }
//            else{
//                chart_data[i]=(double)i*0.125;//偶数
//            }
        }
    }
*/

    for(int i=0;i<17;i++){
        if(i<16){chart_data[i]=0;}
}


}
void MainWindow::chart_init()
{
    this->setCentralWidget(_chart_view);
    pb_close1 = new QPushButton(this);
    pb_close1->setGeometry(450, 650, 90, 50);
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(230, 650, 200, 50);
    connect(pb_close1,SIGNAL(clicked()), this,
     SLOT(pb_close()));
    for(int i=0;i<16;++i) {
        //seriesx->append(i,listdada0[i-1]);
        seriesx->append(i,0.1*i);
        seriesx1->append(i,0.2*i);
    }
    _chart_view->chart()->addSeries(seriesx);
    _chart_view->chart()->addSeries(seriesx1);
    _chart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    seriesx->setName("光照强度");
    seriesx->setColor("cyan");
    QFont font("Times", 25, QFont::Fantasy);
   _chart_view->chart()->setTitle("嵌入式电力网关");
   _chart_view->chart()->setTitleFont(font);
    QValueAxis *axisx = new QValueAxis;
    axisx->setTitleText("time");
    _chart_view->chart()->setAxisX(axisx, seriesx);
    QValueAxis *axisy = new QValueAxis;
    axisy->setTitleText("height(meter)");
    axisy->setRange(0, 12);
    _chart_view->chart()->setAxisY(axisy,seriesx1);
    _chart_view->chart()->setAxisY(axisy,seriesx);
    _chart_view->chart()->setMaximumHeight(600);
    _chart_view->chart()->legend()->setVisible(true);
    _chart_view->chart()->legend()->setAlignment(Qt::AlignBottom);
}

void MainWindow::sin_out()
{
    /*
    temp++;
    for(int i=(temp);i<(16+temp);++i) {
        //seriesx->append(i,listdada3[i-1]);
        double y=0.2*i*sin(2*i)+6;
        seriesx->append(i-temp,y);
    }
    _chart_view->chart()->addSeries(seriesx);
*/
    /*
    if(chart_temp<=8){
        for(int i=chart_temp;i<(16+chart_temp);++i) {
            //seriesx->append(i,listdada3[i-1]);

            seriesx->append(i-chart_temp,chart_data[i+chart_temp]);//未溢出

            //seriesx->append(i-temp,chart_data[i+temp]);//未溢出
        }
    }

    if(chart_temp>8){
        for(int j=0;j<16;j++){
            seriesx->append(j,chart_data[j+16]);
        }

    }
*/

        for(int j=0;j<16;j++){
            seriesx->append(j,chart_data[j]);
            seriesx1->append(j,chart_data1[j]);
        }
    _chart_view->chart()->addSeries(seriesx);
    _chart_view->chart()->addSeries(seriesx1);
    chart_temp++;
    //temp_data=3*sin(chart_temp)+4;
    loopMove(chart_data,17,temp_data_tem);
    loopMove(chart_data1,17,temp_data_ele);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::time_out_clicked()
{
    seriesx->clear();
    seriesx1->clear();
    sin_out();
    //pb_close();
}

void MainWindow::loopMove(double *dat, int len,int temp_data)
{
    //int tem = dat[0];

    for (int i = 0; i < len-1; i++)
        dat[i] = dat[i+1];
    dat[len-1] =temp_data ;
}

void MainWindow::pb_close()
{


    QString b;
    b=lineEdit->text();
    lineEdit->clear();

    temp_data_tem=b.mid(3,2).toInt();
    temp_data_ele=b.mid(0,2).toInt();
    //temperature=str_message.mid(3,2).toInt();

    pb_close1->setText(b.mid(1,2));
}

