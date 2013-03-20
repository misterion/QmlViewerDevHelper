#include <QmlViewerDevHelper/WindowsApiHelper.h>
#include <Windows.h>

WindowsApiHelper::WindowsApiHelper(QObject* obj) : QObject(obj)
{
}

WindowsApiHelper::~WindowsApiHelper()
{
}

WindowsApiHelper* WindowsApiHelper::qmlAttachedProperties(QObject *obj)
{
  return new WindowsApiHelper(obj);
}

quint32 WindowsApiHelper::findWindow(QString windowClass, QString windowTitle)
{
  return reinterpret_cast<quint32>(
    ::FindWindow(reinterpret_cast<const wchar_t*>(windowClass.unicode()), 
                 reinterpret_cast<const wchar_t*>(windowTitle.unicode())));
}

quint32 WindowsApiHelper::findWindowByClass(QString windowClass)
{
  return reinterpret_cast<quint32>(
    ::FindWindow(reinterpret_cast<const wchar_t*>(windowClass.unicode()), 0));
}

quint32 WindowsApiHelper::findWindowByTitle(QString windowTitle)
{
  return reinterpret_cast<quint32>(
    ::FindWindow(0, reinterpret_cast<const wchar_t*>(windowTitle.unicode())));
}

quint32 WindowsApiHelper::processIdByWindow(quint32 window)
{
  DWORD pid = 0;
  GetWindowThreadProcessId((HWND)window, &pid);
  return pid;
}
