#ifndef ANIMATION_H
#define ANIMATION_H

/**
 * @fileName      animation.h
 * @brief         实现APP开启，退出时的动画效果
 * @author        topeet
 * @date          2021-04-19
 */

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QDesktopWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QApplication>

class Animation : public QWidget
{
    Q_OBJECT
public:
    explicit Animation(QWidget *parent = 0);

    void setAnimationObject(QMainWindow *obj);  //开启动画

signals:

public slots:
    void closeAnimationSlot();
    void exitAppAnimationSlot();
    void updateAnimationSlot();

private:
    QPushButton         *   exitBtn;            //右上角的退出按钮
    QMainWindow         *   animationObject;    //主界面
    QPropertyAnimation  *   startAnimation;     //开启APP的动画
    QPropertyAnimation  *   exitAnimation;      //关闭APP是的动画
    int                     desktopWidth;       //屏幕长度
    int                     desktopHeight;      //屏幕宽度
};

#endif // ANIMATION_H
