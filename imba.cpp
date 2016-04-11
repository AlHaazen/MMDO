#include "imba.h"

imbaLayout::imbaLayout(int i)
{


    colorBtn = new QPushButton();

   connect(this->colorBtn,SIGNAL(clicked(bool)),this,SLOT(getColor()));

   // colorBtn->connect(colorBtn,SIGNAL(clicked(bool)),this,SLOT(getColor()));


    spBox1 = new QSpinBox();
    spBox2 = new QSpinBox();
    spBox3 = new QSpinBox();

    spBox1->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);

    spBox1->setMinimum(-100);
    spBox2->setMinimum(-100);
    spBox3->setMinimum(-100);


    rb1 = new QRadioButton(">=");
    rb2 = new QRadioButton("=<");

    group = new QButtonGroup;
    group->addButton(rb1);
    group->addButton(rb2);

    this->addWidget(l1 = new QLabel(QString("%1: ").arg(i)));

    this->addWidget(spBox1);
    this->addWidget(l2 = new QLabel("x1 + "));

    this->addWidget(spBox2);
    this->addWidget(l3 = new QLabel("x2"));

    this->addWidget(rb1);
    this->addWidget(rb2);

    this->addWidget(spBox3);

    this->addWidget(colorBtn);

}

imbaLayout::~imbaLayout()
{
    delete spBox1;
    delete spBox2;
    delete spBox3;

    delete rb1;
    delete rb2;

    delete group;

    delete l1;
    delete l2;
    delete l3;
    delete colorBtn;
}

void imbaLayout::resize(int n)
{
    for(int i = 0; i<N; i++)
    {
        delete spBox[i];
        delete label[i];
    }


    for(int i=0;i<n;i++)
    {
        spBox[i] = new QSpinBox();
        spBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spBox[i]->setMinimum(-100);

        label[i] = new QLabel(QString("x%1 ").arg(i+1));

    }
}

void imbaLayout::getColor()
{
    color = QColorDialog::getColor();
    QPalette pal = colorBtn->palette();
    pal.setColor(QPalette::Base,color);
    pal.setColor(QPalette::Window,color);

    pal.setColor(QPalette::Button,color);
    pal.setColor(QPalette::WindowText,color);

    colorBtn->setAutoFillBackground(true);
    colorBtn->setPalette(pal);
    QString s=QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
    colorBtn->setStyleSheet(s);
    colorBtn->update();

    emit colorChanged();

    qDebug()<<s;

    qDebug()<<"HELP Me";
}

