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

    void setColor(QColor color);
    QColor getColor();

    QRadioButton *rb1, *rb2;
    vector<QDoubleSpinBox*> spBox;

public slots:
    void  changeColor();

signals:
    void colorChanged();

private:
    QColor color;

    QButtonGroup *group;
    QPushButton *colorBtn;

    vector<QLabel*> label;
    int N = 2;
};


#endif // IMBA_H
