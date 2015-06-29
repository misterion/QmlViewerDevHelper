#include <QmlViewerDevHelper/ShellHelper.h>

#include <QtCore/QProcess>
#include <QtCore/QFileInfo>

ShellHelper::ShellHelper(QObject* parent)
{

}

ShellHelper::~ShellHelper()
{
}

ShellHelper *ShellHelper::qmlAttachedProperties(QObject *obj) {
  return new ShellHelper(obj);
}
 
bool ShellHelper::execute(const QString& path, const QStringList &args)
{
  if (path.isEmpty())
    return false;

  QString exePath = path;
  exePath.replace(QString("file:///"), QString(""));

  QFileInfo fi(exePath);
  return QProcess::startDetached(exePath, args, fi.absolutePath());
}
