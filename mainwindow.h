#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>
#include <QPlainTextEdit>


#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>

#include <logic.h>
#include <imba.h>
#include <view.h>


using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_5_clicked();

    void on_actionAbout_2_triggered();

    void on_action_2_triggered();

    void on_actionBuild_triggered();

    void on_actionCalculate_area_triggered();

    void on_actionClear_triggered();

    void on_actionClose_triggered();

    void sort(vector<QPointF> &points);

    void on_Equals_valueChanged(int arg1);

    void on_Clear_clicked();

    void on_Simplex_clicked();

    void on_IntLinear_clicked(){};

    void on_DualSimplex_clicked();

    void on_FractLinear_clicked(){};

    void FracSpinBox();

    void normalizeInput();

    void QuickHull (vector<QPointF> set, QPointF pMin, QPointF pMax, vector<QPointF> &res);

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_checkBoxGradient_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int equals = 9;         // 9 7
    int values = 2;

    vector<imbaLayout*> l;
    QPlainTextEdit *txtEdit;
    QString filename;

};

#endif // MAINWINDOW_H
