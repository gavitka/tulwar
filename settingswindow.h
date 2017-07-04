#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

class ButtonDialog;
class QStackedWidget;

class SettingsWindow : public QDialog
{
public:
    explicit SettingsWindow(QWidget *parent);

private:
    ButtonDialog *buttonDialog;
};


class TouchPage : public QWidget
{
    Q_OBJECT
public:
    explicit TouchPage(QWidget *parent = 0);
};

class ListPage : public QWidget
{
    Q_OBJECT
public:
    explicit ListPage(QWidget *parent = 0);
    QPushButton *addButton;
    QPushButton *editButton;
};

class ButtonDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ButtonDialog(QWidget *parent = 0);
public slots:
    void setButtonType(bool value);
private:
    QStackedWidget *stackedWidget;
};


#endif // SETTINGSWINDOW_H
