#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include "windows.h"
#include <QAbstractNativeEventFilter>

class QTextEdit;

class Toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = 0);
    QTextEdit* debugtext;

private:
    void disableFocus();
    INPUT ip;

private slots:
    void button1_press();
    void button1_release();
    void button2_press();
    void button2_release();
    void button2_toggled(bool value);
};

class ToolBarEventFilter : public QAbstractNativeEventFilter
{
public:
    explicit ToolBarEventFilter(QWidget* widget) : m_widget(widget) {}

private:
    QWidget* m_widget;

    virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *) Q_DECL_OVERRIDE;
};


#endif // TOOLBAR_H
