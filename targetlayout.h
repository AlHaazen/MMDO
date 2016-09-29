#ifndef TARGETLAYOUT_H
#define TARGETLAYOUT_H

#include <QHBoxLayout>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include <iostream>
#include <vector>

using namespace std;

class targetLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    targetLayout();
    ~targetLayout();

    void resize(int n);

    bool findMax();
    bool isFrac();
    vector<double> getX();
//    vector<double> getY();

private:
    vector<QDoubleSpinBox*> spBox1, spBox2;

    vector<QLabel*> label1,label2;
    vector<QVBoxLayout*> vBox;
    vector<QHBoxLayout *> hBox1,hBox2;

    QCheckBox *checkBox;
    QRadioButton *rb1,*rb2;
    QButtonGroup *group;

    QHBoxLayout *rbLayout;
    QVBoxLayout *ctrlLayout;

    int n=2;

};

#endif // TARGETLAYOUT_H
