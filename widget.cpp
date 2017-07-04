#include "widget.h"
#include <QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include "NcFramelessHelper.h"
#include "settingswindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mFh = new NcFramelessHelper;
    mFh->activateOn( this );
    mFh->setWidgetResizable(false);

    QPushButton *settingsButton = new QPushButton(this);
    settingsButton->setText("Settings");
    connect(settingsButton, SIGNAL (released()),this, SLOT (openSettings()));

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(settingsButton);
    setLayout(vBoxLayout);

    setMinimumSize(100, 200);

    setWindowFlags(Qt::FramelessWindowHint);
    settingsWindow = new SettingsWindow(this);
}

Widget::~Widget()
{

}

void Widget::openSettings()
{
    settingsWindow->exec();
}
