/*
  Copyright (c) 2012, Nikolay Bondarenko <misterionkell@gmail.com>  
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  * Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
  * Neither the name of the WebSocket++ Project nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <QmlViewerDevHelper/QmlViewerDevHelper.h>

#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QCoreApplication>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeItem>

#include <QmlViewerDevHelper/ShellHelper.h>

void QmlViewerDevHelper::registerTypes(const char *uri)
{
  qmlRegisterUncreatableType<ShellHelper>("Tulip", 1, 0, "Shell", QLatin1String("Do not create objects of type Shell"));
}

void QmlViewerDevHelper::initializeEngine(QDeclarativeEngine *engine, const char *uri)
{
  this->registerVarExtension(engine);
}

void QmlViewerDevHelper::registerVarExtension(QDeclarativeEngine *engine)
{
  foreach(QString arg, QCoreApplication::arguments()) {
    if (!arg.startsWith("/var")) {
      continue;
    }

    arg = arg.right(arg.length() - 4);
    int index = arg.indexOf("=", 0);
    if (-1 == index) {
      continue;
    }

    QString key = arg.left(index).trimmed();
    QString value = arg.right(arg.length() - index - 1);

    engine->rootContext()->setContextProperty(key, "file:///" + value + "/");
  }
}
