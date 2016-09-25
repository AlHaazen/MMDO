#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <vector>


#define N 50.0


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    // Х>0 and Y>0
    staticLines[0].a = 0;  staticLines[0].b = 1;  staticLines[0].c = 0;
    staticLines[1].a = 1;  staticLines[1].b = 0;  staticLines[1].c = 0;

    lines = new LINE[equals];
    qlines = new QLineF[equals];


    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->centralWidget->setLayout(ui->horizontalLayout);



        ui->Equals->setValue(9);

        l.resize(ui->Equals->value());
        for(int i=0;i<ui->Equals->value();i++)
        {
            l[i] = new imbaLayout(i+1);
            connect(l[i],SIGNAL(colorChanged()),this,SLOT(on_pushButton_5_clicked()));
            ui->verticalLayout->insertLayout(1+i,l[i]);
        }

        l[0]->spBox1->setValue(0);   l[0]->spBox2->setValue(1);  l[0]->rb2->setChecked(true); l[0]->spBox3->setValue(12);
        l[1]->spBox1->setValue(8);   l[1]->spBox2->setValue(1);  l[1]->rb1->setChecked(true); l[1]->spBox3->setValue(16);
        l[2]->spBox1->setValue(1);   l[2]->spBox2->setValue(-1); l[2]->rb1->setChecked(true); l[2]->spBox3->setValue(-10);
        l[3]->spBox1->setValue(1);   l[3]->spBox2->setValue(1);  l[3]->rb1->setChecked(true); l[3]->spBox3->setValue(10);
        l[4]->spBox1->setValue(1);   l[4]->spBox2->setValue(3);  l[4]->rb1->setChecked(true); l[4]->spBox3->setValue(12);
        l[5]->spBox1->setValue(-1);  l[5]->spBox2->setValue(3);  l[5]->rb1->setChecked(true); l[5]->spBox3->setValue(-6);
        l[6]->spBox1->setValue(-5);  l[6]->spBox2->setValue(3);  l[6]->rb1->setChecked(true); l[6]->spBox3->setValue(-48);
        l[7]->spBox1->setValue(1);   l[7]->spBox2->setValue(0);  l[7]->rb2->setChecked(true); l[7]->spBox3->setValue(16);
        l[8]->spBox1->setValue(1);   l[8]->spBox2->setValue(4);  l[8]->rb2->setChecked(true); l[8]->spBox3->setValue(56);



//    ui->Equals->setValue(7);

//    l.resize(ui->Equals->value());
//    for(int i=0;i<ui->Equals->value();i++)
//    {
//        l[i] = new imbaLayout(i+1);
//        connect(l[i],SIGNAL(colorChanged()),this,SLOT(on_pushButton_5_clicked()));
//        ui->verticalLayout->insertLayout(1+i,l[i]);
//    }

//    l[0]->spBox1->setValue(0);   l[0]->spBox2->setValue(1);  l[0]->rb2->setChecked(true); l[0]->spBox3->setValue(12);
//    l[2]->spBox1->setValue(1);   l[2]->spBox2->setValue(-1); l[2]->rb1->setChecked(true); l[2]->spBox3->setValue(-10);
//    l[1]->spBox1->setValue(8);   l[1]->spBox2->setValue(1);  l[1]->rb1->setChecked(true); l[1]->spBox3->setValue(16);
//    l[3]->spBox1->setValue(1);   l[3]->spBox2->setValue(2);  l[3]->rb1->setChecked(true); l[3]->spBox3->setValue(10);
//    l[4]->spBox1->setValue(0);   l[4]->spBox2->setValue(3);  l[4]->rb1->setChecked(true); l[4]->spBox3->setValue(8);
//    l[5]->spBox1->setValue(-4);  l[5]->spBox2->setValue(3);  l[5]->rb1->setChecked(true); l[5]->spBox3->setValue(-48);
//    l[6]->spBox1->setValue(-1);  l[6]->spBox2->setValue(3);  l[6]->rb1->setChecked(true); l[6]->spBox3->setValue(-6);




    txtEdit = new QPlainTextEdit();


    ui->spinBox_3->setVisible(false);
    ui->spinBox_4->setVisible(false);

    connect(ui->checkBox,SIGNAL(stateChanged(int)),SLOT(FracSpinBox()));


    on_Clear_clicked();
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
    delete txtEdit;
}

void MainWindow::on_pushButton_2_clicked()//Build
{

    for(int i=0;i<equals;i++)
    {
        lines[i].a = l[i]->spBox1->value();
        lines[i].b = l[i]->spBox2->value();
        lines[i].c = l[i]->spBox3->value();
        build_line(lines[i], &qlines[i]);
        scene->addLine(qlines[i],QPen(l[i]->color));
    }
}

void MainWindow::build_line(LINE line, QLineF *qline)
{
    double x1,y1;
    double x2,y2;
    double x,y;

    if(line.a != 0 && line.b != 0)
    {
        //    x1
        x = (line.c - line.b*N)/line.a;
        if(x <= N && x >= -N)
        {
            x1 = x;
            y1 = N;
        }

        x = (line.c + line.b*N)/line.a;
        if(x <= N && x >= -N)
        {
            x1 = x;
            y1 = -N;
        }

        y = (line.c - line.a*N)/line.b;
        if(y <= N && y >= -N)
        {
            x1 = N;
            y1 = y;
        }

        y = (line.c + line.a*N)/line.b;
        if(y <= N && y >= -N)
        {
            x1 = -N;
            y1 = y;
        }
        //    x2
        x = (line.c - line.b*N)/line.a;
        if(x <= N && x >= -N && x != x1)
        {
            x2 = x;
            y2 = N;
        }

        x = (line.c + line.b*N)/line.a;
        if(x <= N && x >= -N && x != x1)
        {
            x2 = x;
            y2 = -N;
        }

        y = (line.c + line.a*N)/line.b;
        if(y <= N && y >= -N && y != y1)
        {
            x2 = -N;
            y2 = y;
        }

        y = (line.c - line.a*N)/line.b;
        if(y <= N && y >= -N && y != y1)
        {
            if(y != y1)
                x2 = N;
            y2 = y;
        }

        qline->setLine(x1*10, -y1*10, x2*10, -y2*10);
    }
    else
    {
        if(line.a == 0 && line.b != 0)
            qline->setLine(-500, -10.0*line.c/line.b, 500, -10.0*line.c/line.b);
        if(line.a != 0 && line.b == 0)
            qline->setLine(10.0*line.c/line.a, 500, 10.0*line.c/line.a, -500);
    }
}

void MainWindow::on_pushButton_5_clicked()//Calculate
{
    on_Clear_clicked();
    on_pushButton_2_clicked();

    vector <QPointF> points;
    points.push_back(QPointF(0,0));

    for(int i = 0; i < 2; i++)
        for(int j = 0; j <equals; j++)
        {
            points.resize(points.size()+1);
            solve_matrix(staticLines[i], lines[j],&points.at(points.size()-1));
        }

    for(int i = 0; i < equals; i++)
        for(int j = i+1; j < equals; j++)
        {
            points.resize(points.size()+1);
            solve_matrix(lines[i], lines[j],&points.at(points.size()-1));
        }

    if(ui->radioButton_11->isChecked())
        maxmin = -INFINITY;
    else
        maxmin = INFINITY;

    for(int i = 0; i <points.size(); i++)
    {
        QPointF point = points[i];
        if(point.x() >=0 && point.y() >= 0)
        {
            if(!checkPoint(point))
                continue;

            //точка попадирувала
            goodPoints.push_back(point);


            //єбу що, питай в Стеця...
            //кажись, пошук графічного розв'язку..
            if(ui->radioButton_11->isChecked())
            {
                if(ui->spinBox_2->value()*point.x() + ui->spinBox->value()*point.y() > maxmin)
                {
                    maxmin = ui->spinBox_2->value()*point.x() + ui->spinBox->value()*point.y();
                    remX = point.x(); remY = point.y();
                }
            }
            else
            {
                if(ui->spinBox_2->value()*point.x() + ui->spinBox->value()*point.y() < maxmin)
                {
                    maxmin = ui->spinBox_2->value()*point.x() + ui->spinBox->value()*point.y();
                    remX = point.x(); remY = point.y();
                }
            }
        }
    }

    QString LabelText;
    LabelText = QString(ui->radioButton_11->isChecked() ? "Max" : "Min") + QString(" of F(x1,x2) = ")
            + QString::number(ui->spinBox_2->value()) + QString("x1")
            + QString(ui->spinBox->value()>=0 ? " + " : " - ") + QString::number(abs(ui->spinBox->value()))
            + QString("x2 is \n") + QString::number(maxmin)
            + " in x1 = " + QString::number(remX) + ", x2 = " + QString::number(remY);
    ui->label_16->setText(LabelText);

    sort(goodPoints);
    QPainterPath path;

    path.moveTo(goodPoints[0].x()*10,goodPoints[0].y()*-10);

    for(auto point:goodPoints)
    {
        point.setX(point.x()*10);
        point.setY(point.y()*-10);

        scene->addLine(point.x(),point.y(),point.x(),point.y(),QPen(QColor("red")));

        path.lineTo(point);
    }
    //path.lineTo(goodPoints[0]);
    scene->addPath(path,QPen(Qt::black),QBrush(Qt::DiagCrossPattern));

    goodPoints.clear();

    points.clear();
}

void MainWindow::solve_matrix(LINE line1, LINE line2, QPointF *point)
{
    double delta, dx, dy;
    delta = line1.a*line2.b - line2.a*line1.b;
    dx = line1.c*line2.b - line2.c*line1.b;
    dy = line1.a*line2.c - line2.a*line1.c;
    point->setX(dx/delta);
    point->setY(dy/delta);
}

void MainWindow::on_actionAbout_2_triggered()//про qt
{
    qApp->aboutQt();
}

void MainWindow::on_action_2_triggered()//про мене
{
    QMessageBox::about(this, tr("Про програму"),
                       tr("Ультимативна програма для лабораторних робіт з ММДО та МС\n"
                          "Автори:\n"
                          "Волошин Іван та Стецик Юрій") );
}

void MainWindow::on_actionBuild_triggered()//Build
{
    MainWindow::on_pushButton_2_clicked();
}

void MainWindow::on_actionCalculate_area_triggered()//Calculate
{
    MainWindow::on_pushButton_5_clicked();
}

void MainWindow::on_actionClear_triggered()//Clear
{
    MainWindow::on_Clear_clicked();
}

void MainWindow::on_actionClose_triggered()//Close
{
    MainWindow::on_Clear_clicked();
}

void MainWindow::sort(vector<QPointF> &points) //сортування точок і вимальовування одз
{

    auto ccw = [](QPointF p1, QPointF p2, QPointF p3)
    {
        return (p2.x() - p1.x())*(p3.y() - p1.y()) - (p2.y() - p1.y())*(p3.x() - p1.x());
    };

    vector<QPointF> res;

    double max = 0, min = 1e9;
    QPointF pMax,pMin;
    //Пошук лівої і правої
    for(auto point:points)
    {
        if(point.x() > max)
            pMax = point, max = point.x();
        if(point.x() < min)
            pMin = point, min = point.x();
    }

    //Сортування туди-сюди
    vector<QPointF> upper, lower;
    for(auto point:points)
    {
        if(point == pMax || point == pMin)
            continue;
        if(ccw(pMin,point,pMax)>=0)
            upper.push_back(point);
        else
            lower.push_back(point);
    }


 /*   std::function<void (vector<QPointF>, QPointF, QPointF)> */


    res.push_back(pMin);
    QuickHull(upper, pMin,pMax,res);
    res.push_back(pMax);
    QuickHull(lower,pMax,pMin,res);

    points = res;

}

void MainWindow::on_Equals_valueChanged(int arg1)
{
    ui->Equals->setValue(arg1);

    if(ui->Equals->value() > equals)
    {
        l.resize(ui->Equals->value());
        for(int i=equals; i< ui->Equals->value(); i++)
        {
            l[i] = new imbaLayout(i+1);
            connect(l[i],SIGNAL(colorChanged()),this,SLOT(on_pushButton_5_clicked()));
            ui->verticalLayout->insertLayout(1+i,l[i]);
        }
    }
    else
    {

        for(int i=equals-1; i>=ui->Equals->value();i--)
        {
            ui->verticalLayout->removeItem(l[i]);
            delete l[i];
            l.pop_back();
        }
    }

    equals = ui->Equals->value();

    this->update();

    delete lines;
    delete qlines;
    lines = new LINE[equals];
    qlines = new QLineF[equals];

}

bool MainWindow::checkPoint(QPointF point)
{
    for(int i=0;i<ui->Equals->value();i++)
    {
        double left =point.x()* l[i]->spBox1->value()   +  point.y()* l[i]->spBox2->value();
        double r = l[i]->spBox3->value();
        if( left <r && l[i]->rb1->isChecked() || left >r && l[i]->rb2->isChecked())
            return false;
    }
    return true;

}

void MainWindow::on_Variables_editingFinished()
{

}

void MainWindow::on_FractLinear_clicked()
{
    if(ui->checkBox->isChecked() == false)
        return;

    //створили матрцю
    vector< vector<double> > matrix;
    matrix.resize(equals);
    for(int i = 0; i < equals; i++)
        matrix[i].resize(2 + equals + 1);

    //Проініціалізуємо масив 0
    for(int i = 0; i < equals; i++)
        for(int j = 0; j < 2+equals + 1; j++)
            matrix[i][j]=0;

    //Запишемо х3 - на самом деле у0

    for(int i=0; i<equals; i++)
    {
        matrix[i][0] = -l[i]->spBox3->value();
    }


    // записали Х1 та Х2
    for(int i = 0; i < equals; i++)
    {
        matrix[i][1]=l[i]->spBox1->value();
        matrix[i][2]=l[i]->spBox2->value();
    }

    for(int i=0;i<equals;i++)
        if(!l[i]->rb2->isChecked())
            for(int j=0;j<matrix.at(0).size();j++)
                matrix[i][j]*=-1;

    // Записали додаткові змінні
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][i+3] = 1;

    //Штучних змінних від рівнянь нема
    //Зато є від цільової функції


    matrix.resize(matrix.size()+1);

    int tmp = matrix[0].size()+2;

    for(int i=0; i<matrix.size(); i++)
        matrix[i].resize(tmp);



    matrix[matrix.size()-1][1] = ui->spinBox_3->value();
    matrix[matrix.size()-1][2] = ui->spinBox_4->value();


    matrix[matrix.size()-1][matrix[0].size()-1] = 1;
    matrix[matrix.size()-1][matrix[0].size()-2] = 1;



    // вивід для дебагу
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        for(unsigned j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }



    vector<double> value;
    for(unsigned i = 0; i < matrix[0].size(); i++)
        value.push_back(0);

    // заносимо в value M для штучних змінних

    //Штучна змінна лиш одна - остання
    value[value.size()-2] =-10000000000;

    value[1] = ui->spinBox_2->value();
    value[2] = ui->spinBox->value();

    if(ui->radioButton_12->isChecked())
    {
        value[1] = - ui->spinBox_2->value();
        value[2] = -ui->spinBox->value();
    }


    cout << endl;
    for(unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';

    cout << endl;


    // Сформована матриця

    double result;
    QString stringResult = "";

    int validatei, validatej = 0;
    while(validatej != -1)
    {
        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);

        result = FormSimlexRow(matrix, value, simplex,multi);

        stringResult += formOutput(matrix,multi,value,simplex);
        stringResult +="\n\n\n";

        validatej = ValidateSimplexRow(simplex);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
            {
                printf("Не сумісна матриця");
                break;
            }
            MakeVector(validatei, validatej,matrix);
        }
    }


    stringResult += "\n\n";

    QString buf = "";

    double x1,x2;
    double y0 = matrix[oVector(matrix,0)][matrix.at(0).size()-1];

    if(y0 == 0)
        return;

    qDebug()<<y0;
    tmp = oVector(matrix,1);
    if(tmp == -1)
        x1=0;
    else
    {
        x1=matrix[tmp][matrix.at(0).size()-1] / y0;

    }

    tmp = oVector(matrix,2);
    if(tmp == -1)
        x2=0;
    else
        x2=matrix[tmp][matrix.at(0).size()-1] / y0;



    buf.sprintf("X1: %llf\tX2: %llf\n",x1,x2);
    stringResult +=buf;

    qDebug()<<stringResult;
    qDebug()<<x1<<' '<<x2;

    txtEdit->setPlainText(stringResult);
    // txtEdit->setMinimumSize((int)txtEdit->document()->size().width(),(int)txtEdit->document()->size().height());
    txtEdit->show();

}

void MainWindow::FracSpinBox()
{
    ui->spinBox_3->setVisible(ui->checkBox->isChecked());
    ui->spinBox_4->setVisible(ui->checkBox->isChecked());

}

QString MainWindow::formOutput(vector<vector<double> > &matrix, vector<double> &multi, vector<double> &value, vector<double> &simplex)
{
    QString s = "";
    s += QString("\t");
    for(unsigned i = 0; i < matrix[0].size() - 1; i++)
    {
        QString buf;
        buf.sprintf(" X%d\t", i+1);
        s += buf;
    }
    s += QString(" B\n");

    s += QString("C\t");
    for(unsigned i = 0; i < matrix[0].size() - 1; i++)
    {
        QString buf;
        if(fabs(value[i]) > 100000)// треба буде подумати
            buf.sprintf(" -M\t");
        else
            buf.sprintf(" %.2lf\t", value[i]);
        s += buf;
    }
    s += "\n";

    for(unsigned i = 0; i < matrix.size(); i++)
    {
        if(fabs(multi[i]) < 100000)
            s += QString(" %1\t|").arg(multi[i]);
        else
            s += QString(multi[i] < 0 ? "-M\t|":" M\t|");
        for(unsigned j = 0; j < matrix[0].size(); j++)
        {
            QString buf;
            buf.sprintf("% .2lf", matrix[i][j]);
            s+=buf;
            if(j<matrix[0].size()-1)
                s+="\t";

        }
        s += "\n";
    }
    s+="Simplex row:\n\t";
    for(unsigned i = 0; i < matrix[0].size(); i++)
    {

        QString buf;
        if(fabs(simplex[i]) < 100000)// треба буде подумати
            buf.sprintf("% .2lf\t", simplex[i]);
        else
            buf.sprintf(simplex[i] < 0 ? "-M\t":" M\t");
        s+=buf;
    }

    return s;
}

void MainWindow::on_Simplex_clicked()
{

    normalizeInput();

    //створили матрцю
    vector< vector<double> > matrix;
    matrix.resize(equals);
    for(int i = 0; i < equals; i++)
        matrix[i].resize(2 + equals);

    //Проініціалізуємо масив 0
    for(int i = 0; i < equals; i++)
        for(int j = 0; j < 2+equals; j++)
            matrix[i][j]=0;

    // записали Х1 та Х2
    for(int i = 0; i < equals; i++)
    {
        matrix[i][0]=l[i]->spBox1->value();
        matrix[i][1]=l[i]->spBox2->value();
    }

    // Записали додаткові змінні
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][i+2] = (l[i]->rb1->isChecked() ? -1 : 1);

    // записали штучні змінні
    for(int i = 0; i < matrix.size(); i++)
        if(l[i]->rb1->isChecked())
        {
            for(int j = 0; j < equals; j++)
                matrix[j].resize(matrix[j].size() + 1);
            matrix[i][matrix[0].size()-1] = 1;
        }

    // розширили для вільних членів 8==D
    for(int i = 0; i < matrix.size(); i++)
        matrix[i].resize(matrix[i].size() + 1);

    // загнали вільні члени
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][matrix[0].size()-1] = l[i]->spBox3->value();

    /// Як виявилося, вектор В має містити тільки додатні значення
    /// І, здається тепер це вилізло боком, треба розгрібати

    // вивід для дебагу
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        for(unsigned j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }

    vector<double> value;
    for(unsigned i = 0; i < matrix[0].size(); i++)
        value.push_back(0);

    // заносимо в value M для штучних змінних
    int j = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        if(l[i]->rb1->isChecked())
            value[2 + matrix.size() + j++] = -1000000000000;// 2(кількість норм змінних)
        //        + кількість рівняннь(додаткові змінні) + кількість вже занесених М
    }

    /// Змінити
    ///
    value[0] = ui->spinBox_2->value();
    value[1] = ui->spinBox->value();

    cout << endl;
    for(unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';
    cout << endl;


    if(ui->radioButton_12->isChecked())
    {
        value[0] = - ui->spinBox_2->value();
        value[1] = -ui->spinBox->value();
    }

    // Сформована матриця

    double result;

    QString stringResult = "";
    int validatei, validatej = 0;
    while(validatej != -1)
    {

        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);

        result = FormSimlexRow(matrix, value, simplex,multi);

        stringResult += formOutput(matrix,multi,value,simplex);
        stringResult +="\n\n\n";

        validatej = ValidateSimplexRow(simplex);

        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,matrix);
        }
    }



    txtEdit->setPlainText(stringResult);
    txtEdit->setMinimumSize((int)txtEdit->document()->size().width(),(int)txtEdit->document()->size().height());
    txtEdit->show();
}

void MainWindow::on_IntLinear_clicked()
{
    //створили матрцю
    vector< vector<double> > matrix;
    matrix.resize(equals);
    for(int i = 0; i < equals; i++)
        matrix[i].resize(2 + equals);

    //Проініціалізуємо масив 0
    for(int i = 0; i < equals; i++)
        for(int j = 0; j < 2+equals; j++)
            matrix[i][j]=0;


    // записали Х1 та Х2
    for(int i = 0; i < equals; i++)
    {
        matrix[i][0]=l[i]->spBox1->value();
        matrix[i][1]=l[i]->spBox2->value();
    }


    // Записали додаткові змінні
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][i+2] = (l[i]->rb1->isChecked() ? -1 : 1);

    // записали штучні змінні
    for(int i = 0; i < matrix.size(); i++)
        if(l[i]->rb1->isChecked())
        {
            for(int j = 0; j < equals; j++)
                matrix[j].resize(matrix[j].size() + 1);
            matrix[i][matrix[0].size()-1] = 1;
        }

    // розширили для вільних членів 8==D
    for(int i = 0; i < matrix.size(); i++)
        matrix[i].resize(matrix[i].size() + 1);
    // загнали вільні члени
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][matrix[0].size()-1] = l[i]->spBox3->value();
    // вивід для дебагу
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        for(unsigned j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }


    vector<double> value;
    for(unsigned i = 0; i < matrix[0].size(); i++)
        value.push_back(0);

    // заносимо в value M для штучних змінних
    int j = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        if(l[i]->rb1->isChecked())
            value[2 + matrix.size() + j++] = -1000000000000;// 2(кількість норм змінних)
        //        + кількість рівняннь(додаткові змінні) + кількість вже занесених М
    }
    /// Змінити
    ///
    value[0] = ui->spinBox_2->value();
    value[1] = ui->spinBox->value();

    cout << endl;
    for(unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';

    cout << endl;

    if(ui->radioButton_12->isChecked())
    {
        value[0] = - ui->spinBox_2->value();
        value[1] = -ui->spinBox->value();
    }

    // Сформована матриця


    QString stringResult = "";
    double result;
    int validatei, validatej = 0;
    vector<double> simplex;
    while(validatej != -1)
    {
        simplex.clear();
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);
        result = FormSimlexRow(matrix, value, simplex,multi);


        stringResult += formOutput(matrix,multi,value,simplex);
        stringResult +="\n\n\n";


        validatej = ValidateSimplexRow(simplex);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,matrix);
        }

    }

    ///Початок ЦЧЛП
    ///
    ///
    ///
    while(1)
    {
        double max=0;
        int imax=-1;  //Рядок який треба фіксити

        for(unsigned i = 0; i < matrix.size(); i++)
        {
            if((matrix[i][matrix[i].size()-1] - (int)matrix[i][matrix[i].size()-1])>max)
            {
                if((matrix[i][matrix[0].size()-1] - (int)matrix[i][matrix[0].size()-1]) + 0.00001 >= 1 || (matrix[i][matrix[0].size()-1] - (int)matrix[i][matrix[0].size()-1]) <1.0/pow(10,5))
                    continue;
                max = (matrix[i][matrix[0].size()-1] - (int)matrix[i][matrix[0].size()-1]);
                imax = i;
            }
        }



        if(imax == -1) // Якщо нема що фіксити - виходимо
            break;

        //розширили під новий рядок
        matrix.resize(matrix.size()+1);

        int tmpSize = matrix.at(0).size()+1;

        for(int i=0;i<matrix.size();i++)
            matrix.at(i).resize(tmpSize);

        //записали значення в новий рядок

        for(int j = 0; j < matrix[0].size();j++)
        {
            if(matrix.at(imax).at(j) > 0)
            {
                matrix.at(matrix.size()-1).at(j) = -( matrix.at(imax).at(j) - (int)matrix.at(imax).at(j) );
                /// Приклад
                /// у тебе там 3/8
                /// Результат = 3/8 - 1 = -5/8
            }

            if(matrix.at(imax).at(j) < 0)
            {
                matrix.at(matrix.size()-1).at(j) = -(int)matrix.at(imax).at(j) + 1 +  matrix.at(imax).at(j);

                /// Імба додавання
                /// Приклад:
                /// у тебе там -3/8
                /// Результат = -3/8 + 1 = 5/8
            }
        }

        //Вставити стовпець між останнім і вектором В
        double *tmp = new double[matrix.size()-1];

        for(int i=0;i<matrix.size();i++)
            tmp[i] = matrix.at(i).at(matrix[0].size()-2);

        for(int i=0;i<matrix.size();i++)
            matrix.at(i).at(matrix[0].size()-2) = 0;

        matrix.at(matrix.size()-1).at(matrix[0].size()-2)=1;

        for(int i=0;i<matrix.size();i++)
            matrix.at(i).at(matrix.at(0).size()-1)=tmp[i];

        double jmin=-1;
        double min=INFINITY;
        if(imax != -1)
        {
            for(int j=0;j<matrix[0].size()-1;j++)
            {
                if(  simplex[j] / matrix.at(imax).at(j) < min && simplex[j] / matrix.at(imax).at(j) > 0)
                {
                    min=simplex[j] / matrix.at(imax).at(j);
                    jmin=j;
                }
            }
        }

        imax = matrix.size()-1;

        MakeVector(imax,jmin,matrix);
        simplex.clear();
        simplex.resize(matrix[0].size(),0);
        vector<double> multi;
        multi.resize(matrix.size(),0);

        value.resize(value.size()+1);

        result = FormSimlexRow(matrix, value, simplex,multi);

        stringResult += formOutput(matrix,multi,value,simplex);
    }

    txtEdit->setPlainText(stringResult);
    txtEdit->setMinimumSize((int)txtEdit->document()->size().width(),(int)txtEdit->document()->size().height());
    txtEdit->show();

}

void MainWindow::on_DualSimplex_clicked()
{
    //створили матрицю
    vector< vector<double> > matrix;
    matrix.resize(2);
    for(int i = 0; i < 2; i++)
        matrix[i].resize(equals);
    //занесли значення
    for(int i = 0; i < equals; i++)
    {
        matrix[0][i] = l[i]->spBox1->value();
        matrix[1][i] = l[i]->spBox2->value();

        if(l[i]->rb1->isChecked())
        {
            matrix[1][i] *= -1;
            matrix[0][i] *= -1;
        }
    }
    for(unsigned i = 0; i < matrix.size(); i++)
        matrix[i].resize(4 + equals);
    ///ЗМІНИТИ
    /// ОБОВ'ЯЗКОВО

    matrix[0][4] = -1;
    matrix[1][4] = 0;

    matrix[0][5] = 0;
    matrix[1][5] = -1;

    matrix[0][6] = 1;
    matrix[1][6] = 0;

    matrix[0][7] = 0;
    matrix[1][7] = 1;

    // розширили для вільних члені
    for(unsigned i = 0; i < matrix.size(); i++)
        matrix[i].resize(matrix[i].size() + 1);
    // загнали вільні члени
    matrix[0][matrix[0].size()-1] = ui->spinBox_2->value();
    matrix[1][matrix[1].size()-1] = ui->spinBox->value();
    // вивід для дебагу
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        for(unsigned j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }

    vector<double> value;
    for(unsigned i = 0; i < matrix[0].size(); i++)
        value.push_back(0);
    // заносимо ціни
    for(int i = 0; i < equals; i++)
    {
        value[i] = -l[i]->spBox3->value();//двоїста шукає мінімум
        if(l[i]->rb1->isChecked())
            value[i] *= -1;
    }
    //    -2 -> кількість змінних(x)
    for(unsigned i = matrix[0].size()-1 -2; i < matrix[0].size()-1; i++)
        value[i]=-10000000;

    for(unsigned i = 0;i < value.size(); i++)
        cout<<value[i]<<' ';
    cout<<endl;


    QString stringResult = "";
    double result;
    int validatei, validatej = 0;
    while(validatej != -1)
    {
        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(equals,0);

        result = FormSimlexRow(matrix, value, simplex,multi);

        stringResult += formOutput(matrix,multi,value,simplex);
        stringResult +="\n\n\n";


        validatej = ValidateSimplexRow(simplex);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,matrix);
        }
    }

    txtEdit->setPlainText(stringResult);
    txtEdit->setMinimumSize((int)txtEdit->document()->size().width(),(int)txtEdit->document()->size().height());
    txtEdit->show();

}

void MainWindow::on_Clear_clicked()
{
    scene->clear();
    scene->addLine(500, 0, -500, 0,QPen(QColor("blue")));
    scene->addLine(0, -500, 0, 500,QPen(QColor("blue")));
    ui->label_16->clear();

}

void MainWindow::on_Close_clicked()
{
    this->close();

}

void MainWindow::on_pushButton_clicked()
{

    //    on_Clear_clicked();

    //    ellipse el(-6,-9,2,4,1,1);
    //    vector<equation*> equ;
    //    equ.push_back(new equation(2,3,6));
    //    equ.push_back(new equation(-1,-1,-7));
    //    equ.push_back(new equation(-11,-5,-55));
    //    equ.push_back(new equation(0,1,0));//y>=0
    //    equ.push_back(new equation(1,0,0));//x>=0

    //    plots plot(&equ, &el);

    //    vector<point *> *maxMin = plot.getMaxMin();
    //    point *min = maxMin->at(1), *max = maxMin->at(0);

    //    double h = el.function(min);
    //sad
    //  0w   QLine *line = new QLine();

    //    LINE mLine;
    //    mLine.a=2;
    //    mLine.b=3;
    //    mLine.c=6;
    //    build_line(mLine,line);
    //    scene->addLine(line);

    ////    QGraphicsEllipseItem item;
    ////    item.setRect();

    //    scene->addEllipse(item);

}

void MainWindow::normalizeInput()
{
    for(int i=0; i<equals; i++)
    {
        if(l[i]->spBox3->value()<0)
        {
            l[i]->spBox1->setValue(-1 * l[i]->spBox1->value());
            l[i]->spBox2->setValue(-1 * l[i]->spBox2->value());
            l[i]->spBox3->setValue(-1 * l[i]->spBox3->value());

            l[i]->rb1->setChecked(!l[i]->rb1->isChecked());
            l[i]->rb2->setChecked(!l[i]->rb2->isChecked());


        }
    }
}

void MainWindow::on_actionLoad_triggered()
{
    filename = QFileDialog::getOpenFileName(this,"Відкрити","","MMДО/МС файли (*.fuf)");

    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);

    int equals, vars;

    stream >> equals >> vars;

    this->equals = equals;
    this->vars = vars;

    on_Equals_valueChanged(equals);
//    on_Variables_editingFinished();


    for(int i=0; i<equals; i++)
    {
        double tmp;
        for(int j=0; j<vars; j++)
        {
            stream >> tmp;
        }
    }


}

void MainWindow::on_actionSave_triggered()
{

}
