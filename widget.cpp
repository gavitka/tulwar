#include "widget.h"
#include <QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include "NcFramelessHelper/NcFramelessHelper.h"
#include "settingswindow.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mFh = new NcFramelessHelper;
    mFh->activateOn( this );
    mFh->setWidgetResizable(false);

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    lab1 = new QLabel("0",this);
    lab2 = new QLabel("0",this);

    QPushButton *settingsButton = new QPushButton("Settings", this);
    connect(settingsButton, SIGNAL (released()),this, SLOT (openSettings()));

    vBoxLayout->addWidget(lab1);
    vBoxLayout->addWidget(lab2);
    vBoxLayout->addWidget(settingsButton);

    setLayout(vBoxLayout);

    setMinimumSize(100, 200);

    setWindowFlags(Qt::FramelessWindowHint);
    settingsWindow = new SettingsWindow(this);
}

Widget::~Widget()
{

}

void Widget::setMousex(int value)
{
    lab1->setText(QString::number(value));
}

void Widget::setMousey(int value)
{
    lab2->setText(QString::number(value));
}

void Widget::openSettings()
{
    settingsWindow->exec();
}
