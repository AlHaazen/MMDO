#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    l = new imbaLayout* [ui->Equals->value()];

    for(int i=0;i<ui->Equals->value();i++)
    {
        l[i] = new imbaLayout(i+1);
        connect(l[i],SIGNAL(colorChanged()),this,SLOT(on_pushButton_5_clicked()));
        ui->verticalLayout->insertLayout(1+i,l[i]);
    }
    l[0]->spBox1->setValue(8);   l[0]->spBox2->setValue(-5); l[0]->rb2->setChecked(true); l[0]->spBox3->setValue(40);
    l[1]->spBox1->setValue(2);   l[1]->spBox2->setValue(5);  l[1]->rb1->setChecked(true); l[1]->spBox3->setValue(10);
    l[2]->spBox1->setValue(-6);  l[2]->spBox2->setValue(5);  l[2]->rb2->setChecked(true); l[2]->spBox3->setValue(60);
    l[3]->spBox1->setValue(2);   l[3]->spBox2->setValue(1);  l[3]->rb2->setChecked(true); l[3]->spBox3->setValue(14);


    on_pushButton_clicked();

}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
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

void MainWindow::on_pushButton_clicked()//Clear
{
    scene->clear();
    scene->addLine(500, 0, -500, 0);
    scene->addLine(0, -500, 0, 500);
    ui->label_16->clear();
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
    on_pushButton_clicked();
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
            goodPoints[p]=point;
            p++;

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


    sort(goodPoints,p);
    QPainterPath path;
    path.moveTo(goodPoints[0].x()*10,goodPoints[0].y()*-10);
    for(int i=0;i<p;i++)
    {
        goodPoints[i].setX(goodPoints[i].x()*10);
        goodPoints[i].setY(goodPoints[i].y()*-10);

        path.lineTo(goodPoints[i]);
    }
    path.lineTo(goodPoints[0]);
    scene->addPath(path,QPen(Qt::black),QBrush(Qt::DiagCrossPattern));
    p = 0;

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

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_actionAbout_2_triggered()//про qt
{
    qApp->aboutQt();
}

void MainWindow::on_action_2_triggered()//про мене
{
    QMessageBox::about(this, tr("Про програму"),
                       tr("Ультимативна програма для 1 та 2 лабораторних робіт\n"
                          "Автор:\n"
                          "Студенти груп КН-20 та КН-21, Волошин Іван та Стецик Юрій") );
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
    MainWindow::on_pushButton_clicked();
}

void MainWindow::on_actionClose_triggered()//Close
{
    MainWindow::on_pushButton_4_clicked();
}

void MainWindow::sort(QPointF *points, int n) //сортування точок і вимальовування одз
{
    for(int i=0;i<n;i++)
        cout<<points[i].x()<<' '<<points[i].y()<<endl;

    cout<<endl;
    int q=n-1;

    for(int i=0;i<n;i++)
        if(points[i].x()==0 && points[i].y()==0)
        {
            double tmp=points[q].x();
            points[q].setX(points[i].x());
            points[i].setX(tmp);

            tmp=points[q].y();
            points[q].setY(points[i].y());
            points[i].setY(tmp);
            q--;

        }

    for(int i=0;i<n;i++)
        cout<<points[i].x()<<' '<<points[i].y()<<endl;

    cout<<endl;

    float r=0,f;
    int imax=-1;
    for(int i=0;i<n;i++)
    {
        f=0;
        for(int j=i;j<n;j++)
        {
            if(f<(atan2(points[j].y(), points[j].x())))
            {
                imax=j;
                r = sqrt(points[j].x()*points[j].x() + points[j].y()*points[j].y());
                f = (atan2(points[j].y(), points[j].x()));
            }

        }
        // cout<<f<<endl;

        double tmp=points[imax].x();
        points[imax].setX(points[i].x());
        points[i].setX(tmp);

        tmp=points[imax].y();
        points[imax].setY(points[i].y());
        points[i].setY(tmp);
    }

    cout<<endl;

    for(int i=0;i<n-1;i++)
    {
        if(points[i].x()==0 && points[i+1].x()==0)
            if(points[i].y() > points[i+1].y())
            {
                double tmp=points[i].x();
                points[i].setX(points[i+1].x());
                points[1+i].setX(tmp);

                tmp=points[i].y();
                points[i].setY(points[i+1].y());
                points[i+1].setY(tmp);
            }
        if(points[i].y()==0 && points[i+1].y()==0)
            if(points[i].x() < points[i+1].x())
            {
                double tmp=points[i].x();
                points[i].setX(points[i+1].x());
                points[1+i].setX(tmp);

                tmp=points[i].y();
                points[i].setY(points[i+1].y());
                points[i+1].setY(tmp);
            }

    }

    for(int i=0;i<n;i++)
        cout<<points[i].x()<<' '<<points[i].y()<<endl;
}

//void MainWindow::on_pushButton_3_clicked()//Симлекс
//{
//    //створили матрцю
//    vector< vector<double> > matrix;
//    matrix.resize(equals);
//    for(int i = 0; i < equals; i++)
//        matrix[i].resize(2 + equals);

//    //Проініціалізуємо масив 0
//    for(int i = 0; i < equals; i++)
//        for(int j = 0; j < 2+equals; j++)
//            matrix[i][j]=0;


//    // записали Х1 та Х2
//    for(int i = 0; i < equals; i++)
//    {
//        matrix[i][0]=l[i]->spBox1->value();
//        matrix[i][1]=l[i]->spBox2->value();
//    }


//    // Записали додаткові змінні
//    for(int i = 0; i < matrix.size(); i++)
//        matrix[i][i+2] = (l[i]->rb1->isChecked() ? -1 : 1);

//    // записали штучні змінні
//    for(int i = 0; i < matrix.size(); i++)
//        if(l[i]->rb1->isChecked())
//        {
//            for(int j = 0; j < equals; j++)
//                matrix[j].resize(matrix[j].size() + 1);
//            matrix[i][matrix[0].size()-1] = 1;
//        }

//    // розширили для вільних членів 8==D
//    for(int i = 0; i < matrix.size(); i++)
//        matrix[i].resize(matrix[i].size() + 1);
//    // загнали вільні члени
//    for(int i = 0; i < matrix.size(); i++)
//        matrix[i][matrix[0].size()-1] = l[i]->spBox3->value();
//    // вивід для дебагу
//    for(unsigned i = 0; i < matrix.size(); i++)
//    {
//        for(unsigned j = 0; j < matrix[0].size(); j++)
//            cout << matrix[i][j] << ' ';
//        cout << endl;
//    }


//    vector<double> value;
//    for(unsigned i = 0; i < matrix[0].size(); i++)
//        value.push_back(0);

//    // заносимо в value M для штучних змінних
//    int j = 0;
//    for(int i = 0; i < matrix.size(); i++)
//    {
//        if(l[i]->rb1->isChecked())
//            value[2 + matrix.size() + j++] = -1000000000000;// 2(кількість норм змінних)
//        //        + кількість рівняннь(додаткові змінні) + кількість вже занесених М
//    }

//    cout << endl;
//    for(unsigned i = 0; i < value.size(); i++)
//        cout << value[i] << ' ';

//    cout << endl;
//    /// Змінити
//    ///
//    value[0] = ui->spinBox_2->value();
//    value[1] = ui->spinBox->value();

//    if(ui->radioButton_12->isChecked())
//    {
//        value[0] = - ui->spinBox_2->value();
//        value[1] = -ui->spinBox->value();
//    }

//    // Сформована матриця

//    double result;
//    int validatei, validatej = 0;
//    while(validatej != -1)
//    {

//        vector<double> simplex;
//        simplex.resize(matrix[0].size(),0);

//        vector<double> multi;
//        multi.resize(matrix.size(),0);

//        result = FormSimlexRow(&matrix, &value, &simplex,&multi);

//        QString s = formOutput(matrix,multi,value,simplex);
//        QMessageBox::about(this, "Симплекс-метод", s);

//        validatej = ValidateSimplexRow(&simplex,0);
//        if(validatej != -1)
//        {
//            validatei = MinimalGRZero(validatej, matrix);
//            if(validatei == -1)
//                printf("Не сумісна матриця");
//            MakeVector(validatei, validatej,&matrix);
//        }
//    }
//    QMessageBox::information(this, "Симплекс метод",
//                             QString("Result %1").arg(result)  ,
//                             QMessageBox::Close);
//}

void MainWindow::on_Equals_valueChanged(int arg1)
{
    for(int i=0;i<equals;i++)
    {

        ui->verticalLayout->removeItem(l[i]);
        delete l[i];
    }
    this->update();

    delete[] l;


    l = new imbaLayout* [ui->Equals->value()];

    for(int i=0;i<ui->Equals->value();i++)
    {
        l[i] = new imbaLayout(i+1);
        ui->verticalLayout->insertLayout(1+i,l[i]);
    }
    equals = ui->Equals->value();



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

void MainWindow::on_pushButton_6_clicked() //Двоїста
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

    ///Початок симлпексу
    ///
    double result;
    int validatei, validatej = 0;
    while(validatej != -1)
    {
        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(equals,0);

        result = FormSimlexRow(&matrix, &value, &simplex,&multi);

        QString s = formOutput(matrix,multi,value,simplex);
        QMessageBox::about(this, "Двоїстий симплекс-метод", s);
        validatej = ValidateSimplexRow(&simplex,0);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,&matrix);
        }
    }
    QMessageBox::information(this, "Двоїстий симплекс метод",
                             QString("Result %1").arg(-result)  ,
                             QMessageBox::Close);

}

void MainWindow::on_Variables_editingFinished()
{

}

void MainWindow::on_pushButton_7_clicked() //ЦЧ
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

    cout << endl;
    for(unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';

    cout << endl;
    /// Змінити
    ///
    value[0] = ui->spinBox_2->value();
    value[1] = ui->spinBox->value();

    if(ui->radioButton_12->isChecked())
    {
        value[0] = - ui->spinBox_2->value();
        value[1] = -ui->spinBox->value();
    }

    // Сформована матриця


    double result;
    int validatei, validatej = 0;
    vector<double> simplex;
    while(validatej != -1)
    {
        simplex.clear();
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);
        result = FormSimlexRow(&matrix, &value, &simplex,&multi);

        QString s = formOutput(matrix,multi,value,simplex);
        QMessageBox::about(this, "Симплекс-метод", s);

        validatej = ValidateSimplexRow(&simplex,0);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,&matrix);
        }

    }
    ///Початок ЦЧЛП
    double max=0;
    int imax=-1;  //Рядок який треба фіксити
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        if((matrix[i][matrix[i].size()-1] - (int)matrix[0][matrix[i].size()-1])>max)
        {
            max = (matrix[i][matrix[0].size()-1] - (int)matrix[i][matrix[0].size()-1]);
            imax = i;
        }
    }

    cout<<imax<<endl;

    //розширили під новий рядок
    matrix.resize(matrix.size()+1);

    for(int i=0;i<matrix.size();i++)
        matrix.at(i).resize(matrix.at(0).size()+1);

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

    cout<<endl<<endl;

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.at(0).size();j++)
            cout<<matrix[i][j]<<'\t';
        cout<<endl;
    }

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
    cout<<endl<<jmin<<' '<<imax<<endl;

    MakeVector(imax,jmin,&matrix);
    simplex.clear();
    simplex.resize(matrix[0].size(),0);
    vector<double> multi;
    multi.resize(matrix.size(),0);

    value.resize(value.size()+1);

    result = FormSimlexRow(&matrix, &value, &simplex,&multi);

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.at(0).size();j++)
            cout<<matrix[i][j]<<'\t';
        cout<<endl;
    }

}

void MainWindow::on_FractLinear_clicked()
{
    //створили матрцю
    vector< vector<double> > matrix;
    matrix.resize(equals);
    for(int i = 0; i < equals +1 ; i++)
        matrix[i].resize(2 + equals);

    //Проініціалізуємо масив 0
    for(int i = 0; i < equals; i++)
        for(int j = 0; j < 2+equals; j++)
            matrix[i][j]=0;


    // записали Х1 та Х2
    for(int i = 1; i <= equals; i++)
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


    //    // вивід для дебагу
    //    for(unsigned i = 0; i < matrix.size(); i++)
    //    {
    //        for(unsigned j = 0; j < matrix[0].size(); j++)
    //            cout << matrix[i][j] << ' ';
    //        cout << endl;
    //    }


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

    cout << endl;
    for(unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';

    cout << endl;
    /// Змінити
    ///
    value[0] = ui->spinBox_2->value();
    value[1] = ui->spinBox->value();

    if(ui->radioButton_12->isChecked())
    {
        value[0] = - ui->spinBox_2->value();
        value[1] = -ui->spinBox->value();
    }

    // Сформована матриця


    double result;
    int validatei, validatej = 0;
    while(validatej != -1)
    {

        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);

        result = FormSimlexRow(&matrix, &value, &simplex,&multi);

        QString s = formOutput(matrix,multi,value,simplex);
        QMessageBox::about(this, "Симплекс-метод", s);

        validatej = ValidateSimplexRow(&simplex,0);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,&matrix);
        }
    }
    QMessageBox::information(this, "Симплекс метод",
                             QString("Result %1").arg(result)  ,
                             QMessageBox::Close);

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
            buf.sprintf("% .2lf\t", matrix[i][j]);
            s+=buf;
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

    cout << endl;
    for(unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';

    cout << endl;
    /// Змінити
    ///
    value[0] = ui->spinBox_2->value();
    value[1] = ui->spinBox->value();

    if(ui->radioButton_12->isChecked())
    {
        value[0] = - ui->spinBox_2->value();
        value[1] = -ui->spinBox->value();
    }

    // Сформована матриця

    double result;
    int validatei, validatej = 0;
    while(validatej != -1)
    {

        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);

        result = FormSimlexRow(&matrix, &value, &simplex,&multi);

        QString s = formOutput(matrix,multi,value,simplex);
        QMessageBox::about(this, "Симплекс-метод", s);

        validatej = ValidateSimplexRow(&simplex,0);
        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
                printf("Не сумісна матриця");
            MakeVector(validatei, validatej,&matrix);
        }
    }
    QMessageBox::information(this, "Симплекс метод",
                             QString("Result %1").arg(result)  ,
                             QMessageBox::Close);
}
