#include <QDebug>

#include "settingsui.h"

#include <stdio.h>

#include <QtGui>
#include <MAction>
#include <MTheme>
#include <DcpWidget>
#include "main.h"
#include "brief.h"
#include "settingsui.h"

Q_EXPORT_PLUGIN2(qmlappletdemo, QMLApplet)

void QMLApplet::init()
{

}

DcpWidget* QMLApplet::constructWidget(int widgetId)
{
    Q_UNUSED(widgetId);

    return pageMain();
}

DcpWidget* QMLApplet::pageMain()
{
    return new QMLAppletWidget();
}



QString QMLApplet::title() const
{
    //% "Skeleton applet"
    return "Applet";
}

QVector<MAction*> QMLApplet::viewMenuItems()
{
    QVector<MAction*> vector(0);
    //% "Example action"
    //vector[0] = new MAction("NoAction", this);
    //vector[0]->setLocation(MAction::NoLocation);
    return vector;
}

DcpBrief* QMLApplet::constructBrief(int)
{
    return new QMLAppletBrief();
}
