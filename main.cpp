//#include "widget.h"
#include <QApplication>
#include "kheventfilter.h"
//#include "HookDll.h"
#include "windows.h"
#include "toolbar.h"
#include <QtPlatformHeaders/QWindowsWindowFunctions>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Toolbar w;

    //KhEventFilter *khEventFilter =  new KhEventFilter(&w);
    //a.installNativeEventFilter(khEventFilter);

    ToolBarEventFilter *evFilter1 = new ToolBarEventFilter(&w);
    a.installNativeEventFilter(evFilter1);

    QWindow *tlwWindow = w.windowHandle();
    QWindowsWindowFunctions::setTouchWindowTouchType(tlwWindow,
                                                     QWindowsWindowFunctions::WantPalmTouch);

    w.show();

    //HWND handle = (HWND)w.effectiveWinId();
    //InstallMouseHook(handle);

    return a.exec();
}
