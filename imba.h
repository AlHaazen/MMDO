#ifndef IMBA_H
#define IMBA_H

#include <QHBoxLayout>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>


class imbaLayout : public QHBoxLayout
{
public:

    imbaLayout(int i);
    ~imbaLayout();


    QSpinBox *spBox1,*spBox2,*spBox3;
    QRadioButton *rb1, *rb2;
    QButtonGroup *group;
    QLabel *l1, *l2, *l3;

};





#endif // IMBA_H
