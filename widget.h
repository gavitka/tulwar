#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class NcFramelessHelper;
class SettingsWindow;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void openSettings();
private:
    NcFramelessHelper *mFh;
    SettingsWindow *settingsWindow;
};

#endif // WIDGET_H
