#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
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

};

#endif // VIEW_H
