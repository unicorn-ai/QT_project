#include "animation.h"

Animation::Animation(QWidget *parent) : QWidget(parent)
{
    desktopWidth = QApplication::desktop()->geometry().width();
    desktopHeight=QApplication::desktop()->geometry().height();

    //设置退出按钮的位置和大小
    setMaximumSize(QSize(40,40));
    exitBtn = new QPushButton(this);
    exitBtn->setGeometry(5,5,30,30);
    exitBtn->setStyleSheet("QPushButton"
                           "{border-image:url(:/Resource/icon/close1.png); background: transparent; border: 0px; outline: none }"
                           "QPushButton:pressed"
                           "{border-image:url(:/Resource/icon/close2.png); background: transparent; border: 0px ; outline: none}"
                           "QPushButton:hover"
                           "{border-image:url(:/Resource/icon/close2.png); background: transparent; border: 0px ; outline: none}"
                           );
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(closeAnimationSlot()));
}


/**
 * @brief Animation::setAnimationObject
 * @param obj
 * @note  APP开启时执行此函数，执行动画效果
 */
void Animation::setAnimationObject(QMainWindow *obj)
{
    animationObject = obj;
    /* 进场动画 */
    startAnimation = new QPropertyAnimation(animationObject, "geometry");
    startAnimation->setDuration(210);//动画长度是0.21s
    startAnimation->setStartValue(QRect(0, animationObject->geometry().height(),
                                        0, 0));
    startAnimation->setEndValue(QRect(0, 0,animationObject->geometry().width(),
                                      animationObject->geometry().height()));

    startAnimation->start();
    connect(startAnimation,SIGNAL(finished()),this,SLOT(updateAnimationSlot()));
}

/**
 * @brief Animation::closeAnimationSlot
 * @note  实现关闭app的动画效果
 */
void Animation::closeAnimationSlot()
{
    exitAnimation= new QPropertyAnimation(animationObject, "geometry");
    exitAnimation->setDuration(200);//动画长度是0.2s
    exitAnimation->setStartValue(QRect(animationObject->geometry().x(), animationObject->geometry().y(),
                                       animationObject->geometry().width(), animationObject->geometry().height())
                                 );
    exitAnimation->setEndValue(QRect(animationObject->geometry().width(),-animationObject->geometry().y(),
                                     animationObject->geometry().width(),animationObject->geometry().y()));
    exitAnimation->start();
    connect(exitAnimation,SIGNAL(finished()),this,SLOT(exitAppAnimationSlot()));

}

/**
 * @brief Animation::exitAppAnimationSlot
 * @note  关闭窗口
 */
void Animation::exitAppAnimationSlot()
{
    animationObject->close();
}

/**
 * @brief Animation::updateAnimationSlot
 */
void Animation::updateAnimationSlot()
{
    animationObject->repaint();
}
