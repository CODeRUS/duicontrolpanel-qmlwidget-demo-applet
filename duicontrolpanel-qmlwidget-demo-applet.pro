CONFIG += plugin gui meegotouch-boostable meegotouch debug

QT += core dbus declarative
CONFIG += console link_pkgconfig

PKGCONFIG += duicontrolpanel meegotouch-controlpanel

INCLUDEPATH += $$(SYSROOT_DIR)/usr/include/duicontrolpanel

TEMPLATE = lib
TARGET = settingsui-qmlplugin-demo-applet

settingsdesktop.path = /usr/lib/duicontrolpanel
settingsdesktop.files = qmlplugin-demo.desktop

qml.files = qml/main.qml
qml.path = /usr/share/duicontrolpanel/qmlwidget-demo

target.path = /usr/lib/duicontrolpanel/applets
INSTALLS += target settingsdesktop qml

SOURCES += \
    main.cpp \
    settingsui.cpp \
    brief.cpp \
    QMLHelper.cpp
HEADERS += \
    settingsui.h \
    main.h \
    brief.h \
    QMLHelper.h

OTHER_FILES += \
    statusmenuextensions.desktop \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog
