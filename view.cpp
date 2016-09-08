#include "view.h"


View::View()
{
    cout<<"Created\n";
    this->setBackgroundBrush(QBrush(Qt::red));
}

View::View(QWidget *parent):QGraphicsView()
{

    this->setParent(parent);
}

View::~View()
{

}

void View::wheelEvent(QWheelEvent *e)
{
    if (e->modifiers() & Qt::ControlModifier)
    {
        if (e->delta() > 0)
            this->scale(2,2);
        else
            this->scale(0.5,0.5);
        e->accept();
    }
    else
        QGraphicsView::wheelEvent(e);


}
