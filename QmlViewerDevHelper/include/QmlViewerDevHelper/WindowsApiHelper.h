#pragma once

#include <QtDeclarative>
#include <QtCore/QString>

class WindowsApiHelper : public QObject
{
  Q_OBJECT
public:
  WindowsApiHelper(QObject* obj);
  ~WindowsApiHelper();

  static WindowsApiHelper *qmlAttachedProperties(QObject *obj);
  
public slots:
  quint32 findWindow(QString windowClass, QString windowTitle);
  quint32 findWindowByClass(QString windowClass);
  quint32 findWindowByTitle(QString WindowTitle);
  quint32 processIdByWindow(quint32 window);

};

QML_DECLARE_TYPEINFO(WindowsApiHelper, QML_HAS_ATTACHED_PROPERTIES)
