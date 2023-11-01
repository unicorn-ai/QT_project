#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/* 引入QPushButton */
#include <QPushButton>

#include <QtCharts/QLineSeries>
QT_CHARTS_USE_NAMESPACE//为了使用QChartView
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineSeries *seriesx = new QLineSeries();
    QLineSeries *seriesx1 = new QLineSeries();
signals:
    /* 声明一个信号，只需声明，无需定义 */
    void pushButtonTextChanged();

public slots:
    /* 声明一个槽函数 */
    void changeButtonText();

    /* 声明按钮点击的槽函数 */
    void pushButtonClicked();

private:
    /* 声明一个对象pushButton */
    QPushButton *pushButton;

};
#endif // MAINWINDOW_H
