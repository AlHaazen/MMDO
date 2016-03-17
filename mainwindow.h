#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>

#include <vector>
#include <iostream>
#include <math.h>

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

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void build_line(LINE line, QLineF *lines);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void solve_matrix(LINE line1, LINE line2, QPointF *point);

    void on_actionAbout_2_triggered();

    void on_action_2_triggered();

    void on_actionBuild_triggered();

    void on_actionCalculate_area_triggered();

    void on_actionClear_triggered();

    void on_actionClose_triggered();
    
    void on_pushButton_3_clicked();

    void sort(QPointF *points, int n);

    void on_Equals_valueChanged(int arg1);

    bool checkPoint(QPointF point);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    LINE line[6];
    LINE *lines;
    LINE staticLines[2];

    QLineF qline[4];
    QLineF *qlines;
    int r1, r2, r3, r4;
    double maxmin;
    double remX, remY;
    QPointF goodPoints[14];
    int p=0,equals = 4;
    imbaLayout** l;

};

#endif // MAINWINDOW_H
