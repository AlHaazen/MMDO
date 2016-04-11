#ifndef IMBA_H
#define IMBA_H

#include <QHBoxLayout>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QObject>


class imbaLayout : public QHBoxLayout
{
    Q_OBJECT
public:


    imbaLayout(int i);
    ~imbaLayout();

    void resize(int n);

    QSpinBox *spBox1,*spBox2,*spBox3;
    QRadioButton *rb1, *rb2;
    QButtonGroup *group;
    QLabel *l1, *l2, *l3;

    QSpinBox **spBox = nullptr;
    QLabel **label = nullptr;

    QPushButton *colorBtn;

    QColor color;

    int N = 2;
public slots:
  void  getColor();

signals:
  colorChanged();




};





#endif // IMBA_H
