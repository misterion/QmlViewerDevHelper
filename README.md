QmlViewerDevHelper
==================

How to set the the path of images in qml file if the qml file is in resource?
(http://qt-project.org/forums/viewthread/7047). The answer is:

  QString imagePath = QDir::currentPath()+"/images/";
  #if defined(Q_OS_MAC)
  imagePath = "file://"+imagePath;
  #endif
  QDeclarativeContext::setContextProperty("imagePath",imagePath);

and in qml 

   Image {
   source: imagePath + "image.png"  
   }

in your c++ application. But it`s became a real pain in QtCreator Qml editor and
qml viewer. Yes, you can write in manualy with 
  property string imagePath: ...

but it`s not clear and make some troubles with Loader. 

Just build project and put the dll to your qmlviewer plugin folder. 

Also you need to put valid qmldir file:
  plugin QmlViewerDevHelperX86

You can put dll in any folder you like, just put the path with -I options 
on QmlViewer. 

And usage:
-I "/var varName=varValue" 
or 
-P "/var varName=varValue" 
so varName would be available in qml. 

Example:
-I "/var imagePath=d:/work/project/images"

You may find qt4.x version in 1.0.0 tag.
       
(c) 2012 Nikolay Bondarenko <misterionkell@gmail.com>