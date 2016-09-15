#ifndef IMBA_H
#define IMBA_H

#include <QHBoxLayout>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QObject>

#include <vector>

using namespace std;


class imbaLayout : public QHBoxLayout
{
    Q_OBJECT
public:


    imbaLayout(int i);
    ~imbaLayout();

    void resize(int n);

    QRadioButton *rb1, *rb2;
    QButtonGroup *group;

    QPushButton *colorBtn;

    QColor color;

    vector<QDoubleSpinBox*> spBox;
    vector<QLabel*> label;


    int N = 2;
public slots:
  void  getColor();

signals:
  void colorChanged();




};





#endif // IMBA_H
