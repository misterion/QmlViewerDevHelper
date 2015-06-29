#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include <QtDeclarative/QtDeclarative>

class ShellHelper: public QObject
{
  Q_OBJECT
public:
  explicit ShellHelper(QObject* parent = 0);
  virtual ~ShellHelper();
  
  static ShellHelper *qmlAttachedProperties(QObject *obj);

public:
  Q_INVOKABLE bool execute(const QString& path, const QStringList &args);

};

QML_DECLARE_TYPEINFO(ShellHelper, QML_HAS_ATTACHED_PROPERTIES)