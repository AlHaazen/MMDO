#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QObject>

#include <iostream>

using namespace std;

class View : public QGraphicsView
{
    Q_OBJECT

public:

    View();
    View(QWidget *parent);
    ~View();
    void wheelEvent(QWheelEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

};

#endif // VIEW_H
