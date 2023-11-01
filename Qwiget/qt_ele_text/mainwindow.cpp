#include "mainwindow.h"

#include <QValueAxis>
#include <QtCharts/QChartView> // 手动添加代码行1
using namespace QtCharts;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 设置窗体的宽为800,高为480 */
    this->resize(800,480);

    /* 实例化pushButton对象 */
    pushButton = new QPushButton(this);

    /* 调用setText()方法设定按钮的文本 */
    pushButton->setText("我是一个按钮");

    /* 信号与槽连接 */
    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
    connect(this, SIGNAL(pushButtonTextChanged()), this, SLOT(changeButtonText()));

    QChartView * _chart_view = new QChartView;// 手动添加代码行3
    this->setCentralWidget(_chart_view);// 手动添加代码行4

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
axisy->setRange(0, 12);
//_chart_view->chart()->setAxisY(axisy,seriesx);
_chart_view->chart()->setAxisY(axisy,seriesx1);
_chart_view->chart()->setMaximumHeight(600);
_chart_view->chart()->legend()->setVisible(true);
_chart_view->chart()->legend()->setAlignment(Qt::AlignBottom);





}

MainWindow::~MainWindow()
{

}

/* 实现按钮点击槽函数 */
void MainWindow::pushButtonClicked()
{
    /* 使用emit发送信号 */
    emit pushButtonTextChanged();
}

/* 实现按钮文本改变的槽函数 */
void MainWindow::changeButtonText()
{
    /* 在槽函数里改变按钮的文本 */
    QString str_message="34X12";
    QString electric=str_message.mid(0,2) ;
    QString temperature=str_message.mid(3,2) ;



   pushButton->setText(temperature);
}
