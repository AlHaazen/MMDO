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
    /*!
     * \brief Вертає коефіцієнти при Х
     * \return
     */
    vector<double> getX();

    /*!
     * \brief Виставляє коефіцієнти при Х
     * \param X
     * \return -1 якщо щось не так, 1 якщо все ок
     */
    int setX(vector<double> X);

    /*!
     * \brief Вертає коефіцієнти при У
     * \return
     */
    vector<double> getY();

    /*!
     * \brief Виставляє коефіцієнти при У
     * \param x
     * \return -1 якщо щось не так, 1 якщо все ок
     */
    int setY(vector<double> x);

    /*!
     * \brief Виставляє макс/мін цільової функції. true = max, false = min
     * \param max
     */
    void setTarget(bool max);

    /*!
     * \brief В залежності від параметра включає/виключає дробові коефи
     * \param x
     */
    void setFrac(bool x);

    double getA();

    double getB();

    double getC();

private:
    vector<QDoubleSpinBox*> spBox1, spBox2;

    vector<QLabel*> label1,label2;
    vector<QVBoxLayout*> vBox;
    vector<QHBoxLayout *> hBox1,hBox2;

    QCheckBox *checkBox;
    QRadioButton *rb1,*rb2;

    QHBoxLayout *rbLayout;
    QVBoxLayout *ctrlLayout;

    int n=2;

private slots:
    void onFracChange(int x);

};

#endif // TARGETLAYOUT_H
