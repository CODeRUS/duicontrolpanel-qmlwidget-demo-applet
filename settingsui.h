#ifndef SETTINGSUI_H
#define SETTINGSUI_H

#include <QGraphicsWidget>
#include <QGraphicsObject>
#include <QDeclarativeEngine>
#include <QDeclarativeComponent>
#include <QDeclarativeContext>
#include <QGraphicsLinearLayout>
#include <QDeclarativeProperty>
#include <QObject>

#include <DcpWidget>

class QMLAppletWidget : public DcpWidget
{
Q_OBJECT

public:
    QMLAppletWidget(QGraphicsWidget *parent = 0);
    virtual ~QMLAppletWidget();

private:
    QGraphicsWidget *myWidget;
    QGraphicsLinearLayout *layout;
    QDeclarativeEngine *engine;
    QDeclarativeContext *context;
    QDeclarativeComponent *component;
    QGraphicsObject* myQML;

private slots:
    void continueLoading();
    void heightChanged();

protected:
    void initWidget();

};

#endif // SETTINGSUI_H
