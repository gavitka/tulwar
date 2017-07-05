#include "widget.h"
#include <QApplication>
#include "kheventfilter.h"
#include "HookDll.h"
#include "windows.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    KhEventFilter *khEventFilter =  new KhEventFilter(&w);
    a.installNativeEventFilter(khEventFilter);

    w.show();

    HWND handle = (HWND)w.effectiveWinId();
    InstallMouseHook(handle);

    return a.exec();
}
