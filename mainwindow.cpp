#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene;
    TargetLayout = new targetLayout;
    txtEdit = new QPlainTextEdit();

    ui->graphicsView->setScene(scene);

    ui->centralWidget->setLayout(ui->horizontalLayout);

    ui->verticalLayout->insertLayout(0, TargetLayout);

    ui->Equals->setValue(9);

    l.resize(ui->Equals->value());
    for (int i = 0; i < ui->Equals->value(); i++) {
        l[i] = new imbaLayout(i + 1);
        connect(l[i], SIGNAL(colorChanged()), this, SLOT(on_pushButton_5_clicked()));
        ui->verticalLayout->insertLayout(1 + i, l[i]);
    }
    on_Clear_clicked();

    ///цілочислова і дробовочислова не працюють
    ///Вибачте за тимчасові незручності
    ui->IntLinear->setVisible(false);
    ui->FractLinear->setVisible(false);
}

MainWindow::~MainWindow() {
    delete scene;
    delete ui;
    delete txtEdit;
}

void MainWindow::on_pushButton_5_clicked() //Calculate
{
    on_Clear_clicked();
    auto find = [](vector<QPointF> vec, QPointF point) {
        for (auto x : vec)
            if ((fabs(point.x() - x.x()) <= 1e-3) && (fabs(point.y() - x.y()) <= 1e-3))
                return true;
        return false;
    };
    auto checkPoint = [](QPointF point, vector<imbaLayout *> l) {
        if (point.x() < 0 && point.y() < 0)
            return false;

        double e = -0.005;
        for (auto x : l) {
            double left = point.x() * x->spBox[0]->value() + point.y() * x->spBox[1]->value();
            double right = x->spBox[2]->value();
            if ((left <= e + right && x->rb1->isChecked()) || (left >= right - e && x->rb2->isChecked()))
                return false;
        }
        return true;
    };

    vector<QPointF> points;
    vector<QLineF> lines;
    vector<QPointF> goodPoints;

    lines.push_back(QLineF(QPointF(-10000, 0), QPointF(10000, 0)));
    lines.push_back(QLineF(QPointF(0, -10000), QPointF(0, 10000)));
    points.push_back(QPointF(0, 0));

    for (auto x : l) //формування ліній та їх відмальовка
    {
        /*
        //ax + by = c
        //by = c - ax
        //y = c/b - a/b x
        //k = c/b
        //alpha = -atan(a/b)
        */
        double k = x->spBox[2]->value() / x->spBox[1]->value();
        double alpha = -atan(x->spBox[0]->value() / x->spBox[1]->value()) * 180.0 / M_PI;

        QLineF tmp;
        if (x->spBox[1]->value() == 0) {
            tmp.setPoints(QPointF(10 * x->spBox[2]->value(), 0), QPointF(100, 0));
            tmp.setAngle(90);
        } else {
            tmp.setPoints(QPointF(0, -10 * k), QPointF(100, 0));
            tmp.setAngle(alpha);
        }
        tmp.setLength(1000);

        tmp.setPoints(tmp.p2(), tmp.p1());
        tmp.setLength(2000);
        lines.push_back(tmp);
        scene->addLine(tmp, QPen(x->getColor()));
    }

    for (auto lineA : lines) //пошук точок перетину
        for (auto lineB : lines)
            if (lineA != lineB) {
                QPointF tmp;
                QLineF::IntersectType intType = lineA.intersect(lineB, &tmp);
                tmp.rx() /= 10;
                tmp.ry() /= -10;
                if (intType != QLineF::NoIntersection)
                    points.push_back(tmp);
            }

    double max = -INFINITY;
    double min = INFINITY;

    double xMax = 0.0, yMax = 0.0, xMin = 0.0, yMin = 0.0;

    for (auto point : points) // Пошук точок ОДЗ і відповідно пошук мінімума і максимума
        if (checkPoint(point, l) && !find(goodPoints, point)) {
            //точка попадирувала
            goodPoints.push_back(point);

            auto targetFunc = [this, point]() { return this->TargetLayout->getX()[0] * point.x() + this->TargetLayout->getX()[1] * point.y(); };

            if (targetFunc() > max) {
                max = targetFunc();
                xMax = point.x();
                yMax = point.y();
            }
            if (targetFunc() < min) {
                min = targetFunc();
                xMin = point.x();
                yMin = point.y();
            }
        }

    QString LabelText;
    LabelText = QString("Max = %1 in (%2, %3)\n").arg(max).arg(xMax).arg(yMax) + QString("Min = %1 in (%2, %3)").arg(min).arg(xMin).arg(yMin);
    ui->label_16->setText(LabelText);

    QPainterPath path;
    path.moveTo(goodPoints[0].x() * 10, goodPoints[0].y() * -10);

    for (auto point : goodPoints) {
        point.setX(point.x() * 10);
        point.setY(point.y() * -10);
        path.lineTo(point);
    }

    scene->addPath(path, QPen(Qt::black), QBrush(Qt::DiagCrossPattern));

    if (ui->checkBoxGradient->isChecked()) {
        double k = TargetLayout->getX()[0] > TargetLayout->getX()[1] ? TargetLayout->getX()[0] / 100500.0
                                                                     : TargetLayout->getX()[1] / 100500.0;
        scene->addLine(0, 0, TargetLayout->getX()[0] / k * 10, -TargetLayout->getX()[1] / k * 10, QPen(Qt::gray));

        double a = TargetLayout->getA();
        double b = TargetLayout->getB();

        vector<double> vec;
        vec.push_back(min);
        vec.push_back(max);
        for (auto x : vec) {
            k = x / b;
            double alpha = -atan(a / b) * 180.0 / M_PI;

            QLineF tmp;
            if (b == 0) {
                tmp.setPoints(QPointF(10 * x, 0), QPointF(100, 0));
                tmp.setAngle(90);
            } else {
                tmp.setPoints(QPointF(0, -10 * k), QPointF(100, 0));
                tmp.setAngle(alpha);
            }
            tmp.setLength(1000);

            tmp.setPoints(tmp.p2(), tmp.p1());
            tmp.setLength(2000);
            lines.push_back(tmp);
            scene->addLine(tmp, QPen(Qt::red));
        }
    }
}

void MainWindow::on_actionAbout_2_triggered() //про qt
{
    qApp->aboutQt();
}

void MainWindow::on_action_2_triggered() //про мене
{
    QMessageBox::about(this,
                       "Про програму",
                       "Ультимативна програма для лабораторних робіт з ММДО та МС\n"
                       "Автори:\n"
                       "Волошин Іван та Стецик Юрій");
}

void MainWindow::on_actionBuild_triggered() //Build
{
    MainWindow::on_pushButton_5_clicked();
}

void MainWindow::on_actionCalculate_area_triggered() //Calculate
{
    MainWindow::on_pushButton_5_clicked();
}

void MainWindow::on_actionClear_triggered() //Clear
{
    MainWindow::on_Clear_clicked();
}

void MainWindow::on_actionClose_triggered() //Close
{
    MainWindow::on_Clear_clicked();
}

void MainWindow::sort(vector<QPointF> &points) //сортування точок
{

    auto ccw = [](QPointF p1, QPointF p2, QPointF p3) { return (p2.x() - p1.x()) * (p3.y() - p1.y()) - (p2.y() - p1.y()) * (p3.x() - p1.x()); };

    vector<QPointF> res;

    double max = 0, min = 1e9;
    QPointF pMax, pMin;

    //Пошук лівої і правої
    for (auto point : points) {
        if (point.x() > max)
            pMax = point, max = point.x();
        if (point.x() < min)
            pMin = point, min = point.x();
    }

    //Сортування туди-сюди
    vector<QPointF> upper, lower;
    for (auto point : points) {
        if (point == pMax || point == pMin)
            continue;
        if (ccw(pMin, point, pMax) >= 0)
            upper.push_back(point);
        else
            lower.push_back(point);
    }

    res.push_back(pMin);
    QuickHull(upper, pMin, pMax, res);
    res.push_back(pMax);
    QuickHull(lower, pMax, pMin, res);

    points = res;
}

void MainWindow::on_Equals_valueChanged(int arg1) {
    ui->Equals->setValue(arg1);

    if (ui->Equals->value() > equals) {
        l.resize(ui->Equals->value());
        for (int i = equals; i < ui->Equals->value(); i++) {
            l[i] = new imbaLayout(i + 1);
            connect(l[i], SIGNAL(colorChanged()), this, SLOT(on_pushButton_5_clicked()));
            ui->verticalLayout->insertLayout(1 + i, l[i]);
        }
    } else {
        for (int i = equals - 1; i >= ui->Equals->value(); i--) {
            ui->verticalLayout->removeItem(l[i]);
            delete l[i];
            l.pop_back();
        }
    }

    equals = ui->Equals->value();

    this->update();
}

void MainWindow::on_Simplex_clicked() {
    normalizeInput();

    //створили матрцю
    vector<vector<double>> matrix(equals);
    for (auto &x : matrix)
        x.resize(values + equals, 0);

    // записали Х1 та Х2
    for (int i = 0; i < equals; i++)
        for (int j = 0; j < values; j++)
            matrix[i][j] = l[i]->spBox[j]->value();

    // Записали додаткові змінні
    for (int i = 0; i < matrix.size(); i++)
        matrix[i][i + 2] = (l[i]->rb1->isChecked() ? -1 : 1);

    // записали штучні змінні
    for (int i = 0; i < matrix.size(); i++)
        if (l[i]->rb1->isChecked()) {
            for (auto &x : matrix)
                x.push_back(0);
            matrix[i][matrix[0].size() - 1] = 1;
        }

    // загнали вільні члени
    for (int i = 0; i < matrix.size(); i++)
        matrix[i].push_back(l[i]->spBox[values]->value());

    vector<double> value = TargetLayout->getX();
    if (!TargetLayout->findMax())
        for (auto &x : value)
            x *= -1;

    value.resize(matrix[0].size(), 0);

    // заносимо в value M для штучних змінних
    int j = 0;
    for (auto x : l)

        if (x->rb1->isChecked())
            value[values + equals + j++] = -1000000000000;
    //змінні + рівняння + вже занесені М

    // вивід для дебагу
    for (unsigned i = 0; i < matrix.size(); i++) {
        for (unsigned j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for (unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';
    cout << endl;

    QString res = Simplex(matrix, value);

    if (res == "")
        res = "Щось пішло не так";

    txtEdit->setPlainText(res);
    txtEdit->showMaximized();
}

void MainWindow::on_DualSimplex_clicked() {
    normalizeInput();

    //створили матрицю
    vector<vector<double>> matrix(values);
    for (auto &x : matrix)
        x.resize(equals);

    //занесли значення
    for (int i = 0; i < equals; i++)
        for (int j = 0; j < values; j++) {
            if (!TargetLayout->findMax() && l[i]->rb1->isChecked())
                matrix[j][i] = -l[i]->spBox[j]->value();
            else
                matrix[j][i] = l[i]->spBox[j]->value();
        }

    //Додаємо штучні змінні

    //    for(int i=0; i<values; i++)
    //        for(int j=0; j<values; j++)
    //            if(i==j)
    //                matrix[i].push_back(-1);
    //            else matrix[i].push_back(0);

    for (int i = 0; i < values; i++)
        for (int j = 0; j < values; j++)
            if (i == j)
                matrix[i].push_back(1);
            else
                matrix[i].push_back(0);

    // загнали вільні члени
    vector<double> tmp = TargetLayout->getX();
    for (int i = 0; i < values; i++)
        matrix[i].push_back(tmp[i]);

    vector<double> value(matrix[0].size(), 0);

    // заносимо ціни
    for (int i = 0; i < equals; i++) {
        value[i] = -l[i]->spBox[values]->value();
        if (l[i]->rb1->isChecked())
            value[i] *= -1;
    }

    for (unsigned i = matrix[0].size() - 1 - values; i < matrix[0].size() - 1; i++)
        value[i] = -10000000;

    // вивід для дебагу
    for (unsigned i = 0; i < matrix.size(); i++) {
        for (unsigned j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
    for (unsigned i = 0; i < value.size(); i++)
        cout << value[i] << ' ';
    cout << endl;

    QString res = Simplex(matrix, value);

    if (res == "")
        res = "Щось пішло не так";

    txtEdit->setPlainText(res);
    txtEdit->showMaximized();
}

void MainWindow::on_Clear_clicked() {
    scene->clear();
    scene->addLine(500, 0, -500, 0, QPen(QColor("blue")));
    scene->addLine(0, -500, 0, 500, QPen(QColor("blue")));
    ui->label_16->clear();
}

void MainWindow::normalizeInput() {
    for (auto x : l)
        if (x->spBox[values]->value() < 0) {
            for (auto y : x->spBox)
                y->setValue(y->value() * -1);
            x->rb1->setChecked(!x->rb1->isChecked());
            x->rb2->setChecked(!x->rb2->isChecked());
        }
}

void MainWindow::QuickHull(vector<QPointF> set, QPointF pMin, QPointF pMax, vector<QPointF> &res) {
    if (set.empty())
        return;

    auto len = [](QPointF A, QPointF B, QPointF C) {
        double a = B.y() - A.y();
        double b = A.x() - B.x();
        return fabs((a * C.x() + b * C.y() + a * A.x() + b * B.x())) / sqrt(a * a + b * b);
    };

    auto ccw = [](QPointF p1, QPointF p2, QPointF p3) {
        return (p2.x() - p1.x()) * (p3.y() - p1.y()) - (p2.y() - p1.y()) * (p3.x() - p1.x());
    };

    double l = 0;

    QPointF max;
    for (auto point : set) {
        if (l < len(pMin, pMax, point))
            l = len(pMin, pMax, point), max = point;
    }

    //Max - найдальша точка

    //Сортування туди-сюди
    vector<QPointF> upper, lower;
    for (auto point : set) {
        if (point == pMax || point == pMin)
            continue;
        if (ccw(pMin, point, max) > 0)
            upper.push_back(point);
        if (ccw(max, point, pMin) > 0)
            lower.push_back(point);
    }

    QuickHull(upper, pMin, max, res);
    res.push_back(max);
    QuickHull(lower, max, pMax, res);
}

void MainWindow::on_actionLoad_triggered() {
    filename = QFileDialog::getOpenFileName(this, "Відкрити", "", "MMДО/МС файли (*.fuf)");

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {

        QTextStream stream(&file);

        int equals, vars;

        stream >> equals >> vars;
        on_Equals_valueChanged(equals);

        this->equals = equals;
        this->values = vars;

        //    on_Variables_editingFinished();

        double tmpD;
        int tmpI;

        for (int i = 0; i < equals; i++) {
            for (int j = 0; j < vars; j++) {
                stream >> tmpD;
                l[i]->spBox[j]->setValue(tmpD);
            }

            stream >> tmpI;
            tmpI ? l[i]->rb1->setChecked(true) : l[i]->rb2->setChecked(true);

            stream >> tmpD;
            l[i]->spBox[vars]->setValue(tmpD);

            stream >> tmpI;
            int r, g, b;
            stream >> r >> g >> b;
            QColor color(r, g, b);

            l[i]->setColor(QColor(r, g, b));
        }

        vector<double> x(vars);
        for (int i = 0; i < vars; i++)
            stream >> x[i];

        TargetLayout->resize(vars);
        TargetLayout->setX(x);

        stream >> tmpI;
        TargetLayout->setTarget(tmpI);

        stream >> tmpI;
        if (tmpI) {
            TargetLayout->setFrac(true);
            for (int i = 0; i < vars; i++)
                stream >> x[i];
            TargetLayout->setY(x);
        }

        file.close();

        on_actionCalculate_area_triggered();
    }
}

void MainWindow::on_actionSave_triggered() {
    if (filename.isEmpty())
        filename = QFileDialog::getSaveFileName(this, "Зберегти", "", "MMДО/МС файли (*.fuf)");

    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)) {

        QTextStream stream(&file);

        stream << equals << " " << values << endl;

        for (int i = 0; i < equals; i++) {
            for (int j = 0; j < values; j++)
                stream << l[i]->spBox[j]->value() << " ";

            stream << l[i]->rb1->isChecked() << " ";
            stream << l[i]->spBox[values]->value() << " ";

            stream << "1 ";
            int r, g, b;

            l[i]->getColor().getRgb(&r, &g, &b, nullptr);
            stream << r << " " << g << " " << b << endl;
        }

        vector<double> vec = TargetLayout->getX();

        for (auto x : vec)
            stream << x << " ";

        stream << TargetLayout->isFrac();

        if (TargetLayout->isFrac()) {
            vec = TargetLayout->getY();

            for (auto x : vec)
                stream << x << " ";
        }
    }
}

void MainWindow::on_checkBoxGradient_clicked() {
    on_pushButton_5_clicked(); // не краще ніж попереднє, але буде фікситися
}

/*
void MainWindow::on_FractLinear_clicked()
{
    if(ui->checkBox->isChecked() == false)
        return;

    //створили матрцю
    vector< vector<double> > matrix;
    matrix.resize(equals);
    for(int i = 0; i < equals; i++)
        matrix[i].resize(values + equals + 1);

    //Проініціалізуємо масив 0
    for(int i = 0; i < equals; i++)
        for(int j = 0; j < values +equals + 1; j++)
            matrix[i][j]=0;

    //Запишемо х3 - на самом деле у0

    for(int i=0; i<equals; i++)
        matrix[i][0] = -l[i]->spBox[values]->value();



    // записали Х1 та Х2 ...
    for(int i = 0; i < equals; i++)
    {
        for(int j=0; j<values; j++)
        matrix[i][j]=l[i]->spBox[j]->value();
        matrix[i][j]=l[i]->spBox[j]->value();
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
*/
