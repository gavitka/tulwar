#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class NcFramelessHelper;
class SettingsWindow;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void setMousex(int value);
    void setMousey(int value);

private slots:
    void openSettings();
private:
    NcFramelessHelper *mFh;
    SettingsWindow *settingsWindow;

    QLabel *lab1;
    QLabel *lab2;
};

#endif // WIDGET_H
