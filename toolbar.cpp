#include "toolbar.h"

#include "windows.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QScrollBar>

#include <QDebug>


Toolbar::Toolbar(QWidget *parent) : QWidget(parent)
{
    disableFocus();

    QGridLayout *grid1 = new QGridLayout(this);

    QPushButton *button1 = new QPushButton("Button 1",this);
    connect(button1,SIGNAL(pressed()),this,SLOT(button1_press()));
    //button1->setAttribute(Qt::WA_ShowWithoutActivating);
    connect(button1,SIGNAL(released()),this,SLOT(button1_release()));
    QPushButton *button2 = new QPushButton("Button 2",this);
    button2-> setCheckable(true);
    //connect(button2,SIGNAL(pressed()),this,SLOT(button2_press()));
    //connect(button2,SIGNAL(released()),this,SLOT(button2_release()));
    connect(button2,SIGNAL(toggled(bool)),this,SLOT(button2_toggled(bool)));

    QPushButton *button3 = new QPushButton("Button 3",this);
    QPushButton *button4 = new QPushButton("Button 4",this);
    debugtext = new QTextEdit("message",this);

    grid1->addWidget(button1,0,0);  grid1->addWidget(button2,0,1);
    grid1->addWidget(button3,1,0);  grid1->addWidget(button4,1,1);
    grid1->addWidget(debugtext,2,0,1,2);

    setLayout(grid1);

    setAttribute(Qt::WA_ShowWithoutActivating);
    setAttribute(Qt::WA_AcceptTouchEvents);

    // focus:https://stackoverflow.com/questions/24582525/how-to-show-clickable-qframe-without-loosing-focus-from-main-window?lq=1
    // http://www.qtcentre.org/threads/33081-Clickable-no-focus-window
    // qt click no focus
}

void Toolbar::button1_press()
{
    int x,y;
    x = 100;
    y = 100;
    SetCursorPos(x, y);

//    SendMessage(HWND_BROADCAST,
//                WM_MOUSEMOVE,
//                (WPARAM)0,
//                ((x << 0x10) ^ y));

    qDebug() << "sent message";
}

void Toolbar::button1_release()
{

}

void Toolbar::button2_toggled(bool value)
{
    if(value == true)
        button2_press();
    else
        button2_release();
}

void Toolbar::button2_press()
{
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VK_MENU; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press

    SendInput(1, &ip, sizeof(INPUT));

    qDebug() << "press A";
}

void Toolbar::button2_release()
{

    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release

    SendInput(1, &ip, sizeof(INPUT));

    qDebug() << "release A";
}

void Toolbar::disableFocus()
{
    HWND winHandle = (HWND)winId();
    ShowWindow(winHandle, SW_HIDE);
    SetWindowLong(winHandle, GWL_EXSTYLE, GetWindowLong(winHandle, GWL_EXSTYLE)
        | WS_EX_NOACTIVATE | WS_EX_APPWINDOW);
    ShowWindow(winHandle, SW_SHOW);

    //RegisterTouchWindow(winHandle, TWF_WANTPALM);
    //https://msdn.microsoft.com/en-us/library/windows/desktop/dd317326(v=vs.85).aspx

}

bool ToolBarEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, long *)
{
    Q_UNUSED(eventType)
    //POINTS ptsEnd;
    MSG* msg = (MSG*)(message);

    QString messagetext;
    QString messagetexthex;


    switch(msg->message)
    {
    //useless messages
    case 1025:
    case 32756:
    case WM_MOUSEMOVE:
    case WM_NCHITTEST:
    case WM_TIMER:
    case WM_SETCURSOR:
    case WM_NCMOUSEMOVE:
        return false;
        break;
    //useful messages
    case WM_GESTURE: messagetext = "WM_GESTURE"; break;
    case WM_GETICON: messagetext = "WM_GETICON"; break;
    case WM_LBUTTONDOWN: messagetext = "WM_LBUTTONDOWN"; break;
    case WM_LBUTTONUP: messagetext = "WM_LBUTTONUP"; break;
    case WM_CAPTURECHANGED: messagetext = "WM_CAPTURECHANGED"; break;
    case WM_NCMOUSELEAVE: messagetext = "WM_NCMOUSELEAVE"; break;
    //case WM_MOUSELEAVE: messagetext = "WM_MOUSELEAVE"; break;
    //case WM_NCMOUSEMOVE: messagetext = "WM_NCMOUSEMOVE"; break;
    case WM_IME_SETCONTEXT: messagetext = "WM_IME_SETCONTEXT"; break;
    case WM_POINTERDOWN: messagetext = "WM_POINTERDOWN"; break;
    case WM_POINTERENTER: messagetext = "WM_POINTERENTER"; break;
    case WM_TOUCH: messagetext = "WM_TOUCH"; break;
    case WM_POINTERUPDATE: messagetext = "WM_POINTERUPDATE"; break;
    case WM_POINTERUP: messagetext = "WM_POINTERUP"; break;
    case WM_POINTERLEAVE: messagetext = "WM_POINTERLEAVE"; break;
    default:
       break;
    }

    messagetexthex.sprintf("%02X", msg->message);
    messagetext+= " "+ messagetexthex;

    qDebug() << "Native event happened" << messagetext;

    QTextEdit* debugtext = ((Toolbar*)m_widget)->debugtext;
    QString text = debugtext->toPlainText();
    text = text.mid(text.length() - 1023, 1023);
    text = text + "\n" + messagetext;
    debugtext->setText(text);
    debugtext->verticalScrollBar()->setValue(debugtext->verticalScrollBar()->maximum());


//    if(msg->message == WM_KEYSTROKE) {
//        //ptsEnd = MAKEPOINTS(msg->lParam);
//        //qDebug() << "mouse location:" << ptsEnd.x << ptsEnd.y;
//        //qDebug() << eventType;

//        //POINT mpt = ((tagMOUSEHOOKSTRUCT*)msg->lParam)->pt;
//        POINT mpt = msg->pt;
//        //printf("mousemove: %d %d\n",GET_X_LPARAM(msg->lParam), GET_Y_LPARAM(msg->lParam));
//        //printf("mousemove: %d %d\n",mpt.x, mpt.y);
//        m_widget->setMousex(mpt.x);
//        m_widget->setMousey(mpt.y);
//    }
    return false;
}
