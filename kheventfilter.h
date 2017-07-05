#ifndef KHEVENTFILTER_H
#define KHEVENTFILTER_H

#define WM_KEYSTROKE (WM_USER + 101)

#include <QObject>
#include <QAbstractNativeEventFilter>
#include "Windows.h"
#include <QDebug>
#include "Winuser.h"
#include "Windowsx.h"
#include "stdio.h"
#include "widget.h"

class KhEventFilter : public QAbstractNativeEventFilter
{

public:
    KhEventFilter(Widget* widget);

    virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *) Q_DECL_OVERRIDE
    {
        Q_UNUSED(eventType)
        //POINTS ptsEnd;
        MSG* msg = (MSG*)(message);
        if(msg->message == WM_KEYSTROKE) {
            //ptsEnd = MAKEPOINTS(msg->lParam);
            //qDebug() << "mouse location:" << ptsEnd.x << ptsEnd.y;
            //qDebug() << eventType;

            //POINT mpt = ((tagMOUSEHOOKSTRUCT*)msg->lParam)->pt;
            POINT mpt = msg->pt;
            //printf("mousemove: %d %d\n",GET_X_LPARAM(msg->lParam), GET_Y_LPARAM(msg->lParam));
            //printf("mousemove: %d %d\n",mpt.x, mpt.y);
            m_widget->setMousex(mpt.x);
            m_widget->setMousey(mpt.y);
        }
        return false;
    }
private:
    Widget* m_widget;
};

#endif // KHEVENTFILTER_H
