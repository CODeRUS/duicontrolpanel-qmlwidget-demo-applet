#include "settingsui.h"
#include "QMLHelper.h"

QMLAppletWidget::QMLAppletWidget(QGraphicsWidget *parent):
    DcpWidget(parent)
{
    setReferer(-1);
    initWidget();
}

void QMLAppletWidget::initWidget()
{
    engine = new QDeclarativeEngine(this);
    context = new QDeclarativeContext(engine->rootContext());
    context->setContextProperty("QMLHelper", new QMLHelper(this));

    component = new QDeclarativeComponent(engine, QUrl::fromLocalFile("/usr/share/duicontrolpanel/qmlwidget-demo/main.qml"));
    if (component->isLoading())
         QObject::connect(component, SIGNAL(statusChanged(QDeclarativeComponent::Status)),
                          this, SLOT(continueLoading()));
    else
         continueLoading();
}

QMLAppletWidget::~QMLAppletWidget()
{

}

void QMLAppletWidget::continueLoading()
{
    if (component->isError()) {

    }
    else
    {
        QObject *myObject = component->create(context);
        myQML = qobject_cast<QGraphicsObject*>(myObject);
        if (myQML)
        {
            myQML->setParentItem(this);
            myQML->setProperty("width", 480);
            QDeclarativeProperty(myQML, "height").connectNotifySignal(this, SLOT(heightChanged()));
            heightChanged();
        }
    }
}

void QMLAppletWidget::heightChanged()
{
    int height = myQML->property("height").toInt();
    setMinimumHeight(height);
    setMaximumHeight(height);
}

