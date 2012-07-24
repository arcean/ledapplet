include(../coverage.pri)
include(../../localconfig.pri)

TEMPLATE = lib
CONFIG += plugin \
          gui \
          meegotouch \
          duicontrolpanel \
          silent

QT += dbus

MOC_DIR = .moc
OBJECTS_DIR = .objects

HEADERS = \
    ../debug.h \
    ledbusinesslogic.h \
    ledapplet.h \
    ledwidget.h \
    ledbrief.h \ 
    TitleWidget.h \
    switch.h \
    drilllistitem.h \
    viewId.h \
    drilllistitemtitle.h \
    ledsettingswidget.h \
    aboutdialog.h

SOURCES = \
    ../debug.cpp \
    ledbusinesslogic.cpp \
    ledapplet.cpp \
    ledwidget.cpp \
    ledbrief.cpp \  
    switch.cpp \
    drilllistitem.cpp \
    drilllistitemtitle.cpp \
    ledsettingswidget.cpp \
    aboutdialog.cpp

DESTDIR = lib
desktop.files += *.desktop
desktop.path = $$(DEBIAN_DESTDIR)/usr/lib/duicontrolpanel
target.path += $$(DEBIAN_DESTDIR)$$[QT_INSTALL_LIBS]/duicontrolpanel/applets
css.files += *.css
css.path = $$(DEBIAN_DESTDIR)/opt/ledapplet/styles/
png.files += *.png
png.path = $$(DEBIAN_DESTDIR)/opt/ledapplet/styles/

message("The plugin will be installed to: " $$target.path)
INSTALLS += target \
            desktop \
            css \
            png
