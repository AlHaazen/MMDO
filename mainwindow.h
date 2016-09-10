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

    typedef struct _line
    {
        int a,b,c;
    }LINE;

    LINE *getLines() const;
    void setLines(LINE *value);

private slots:

    void on_pushButton_2_clicked();

    void build_line(LINE line, QLineF *lines);

    void on_pushButton_5_clicked();

    void solve_matrix(LINE line1, LINE line2, QPointF *point);

    void on_actionAbout_2_triggered();

    void on_action_2_triggered();

    void on_actionBuild_triggered();

    void on_actionCalculate_area_triggered();

    void on_actionClear_triggered();

    void on_actionClose_triggered();

    void sort(vector<QPointF> &points);

    void on_Equals_valueChanged(int arg1);

    bool checkPoint(QPointF point);

    void on_Variables_editingFinished();

    void on_Clear_clicked();

    void on_Close_clicked();

    QString formOutput(vector<vector<double> > &matrix, vector<double> &multi, vector<double> &value, vector<double> &simplex);

    void on_Simplex_clicked();

    void on_IntLinear_clicked();

    void on_DualSimplex_clicked();

    void on_FractLinear_clicked();

    void FracSpinBox();

    void on_pushButton_clicked();

    void normalizeInput();

    void QuickHull (vector<QPointF> set, QPointF pMin, QPointF pMax, vector<QPointF> &res)
    {
        if(set.empty())
            return;
        auto len = [](QPointF A, QPointF B, QPointF C)
        {
            double a = B.y() - A.y();
            double b = A.x() - B.x();
            return fabs((a*C.x() + b*C.y() + a*A.x() + b*B.x())) / sqrt(a*a + b*b);
        };

        auto ccw = [](QPointF p1, QPointF p2, QPointF p3)
        {
            return (p2.x() - p1.x())*(p3.y() - p1.y()) - (p2.y() - p1.y())*(p3.x() - p1.x());
        };


        double l = 0;

        QPointF max;
        for(auto point:set)
        {
            if(l < len(pMin,pMax,point))
                l = len(pMin,pMax,point), max = point;
        }


        //Max - найдальша точка


        //Сортування туди-сюди
        vector<QPointF> upper, lower;
        for(auto point:set)
        {
            if(point == pMax || point == pMin)
                continue;
            if(ccw(pMin,point,max)>0)
                upper.push_back(point);
            if(ccw(max,point,pMin)>0)
                lower.push_back(point);
        }

        QuickHull(upper,pMin,max,res);
        res.push_back(max);
        QuickHull(lower,max,pMax,res);

    };

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    LINE *lines;
    LINE staticLines[2];

    QLineF *qlines;
    double maxmin;
    double remX, remY;
    vector<QPointF> goodPoints;
    int equals = 9;         // 9 7
    vector<imbaLayout*> l;
    QPlainTextEdit *txtEdit;

};

#endif // MAINWINDOW_H
