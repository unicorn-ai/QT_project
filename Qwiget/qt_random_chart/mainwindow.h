#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <QTime>
QT_CHARTS_USE_NAMESPACE//为了使用QChartView



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineSeries *seriesx = new QLineSeries();
    QLineSeries *seriesx1 = new QLineSeries();
    QChartView * _chart_view = new QChartView;
    double chart_data[32];
    double chart_data1[32];
    int listdada0[10]={1,2,5,8,2,4};
    int listdada1[10]={2,5,8,2,4,2};
    int listdada2[10]={5,8,2,4,2,4};
    int listdada3[10]={8,2,4,2,4,1};
    int chart_temp=0;
    int temp_data_tem=0;
    int temp_data_ele=0;
    bool flag=0;
     //QPushButton *pb_close1;

signals:

public slots:
    void chart_init();

    void sin_out();
private slots:

    void time_out_clicked();

    void pb_close();
    void loopMove(double *dat, int len,int temp_data);
private:

    QPushButton *pb_close1;
    QLineEdit *lineEdit;

    Ui::MainWindow *ui;
    QTimer *timer;


};
#endif // MAINWINDOW_H
