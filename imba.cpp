#include "imba.h"

imbaLayout::imbaLayout(int i)
{
   colorBtn = new QPushButton();

//   QRect *rect = new QRect(0,0,25,25);
//   QRegion *region = new QRegion(*rect, QRegion::Ellipse);
//   colorBtn->setMask(*region);

   connect(this->colorBtn,SIGNAL(clicked(bool)),this,SLOT(getColor()));

   spBox.resize(N+1);

   for(int i=0; i<N+1; i++)
   {
       spBox[i] = new QDoubleSpinBox();
       spBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
       spBox[i]->setMinimum(-100);
   }

    rb1 = new QRadioButton(">=");
    rb2 = new QRadioButton("=<");

    group = new QButtonGroup;
    group->addButton(rb1);
    group->addButton(rb2);

    label.resize(N+1);
    label[0] = new QLabel(QString("%1: ").arg(i));
    for(auto i=1; i<N+1; i++)
        label[i] = new QLabel(QString("x%1 + ").arg(i));


    for(int i=0; i<N; i++)
    {
        this->addWidget(label[i]);
        this->addWidget(spBox[i]);
    }

    this->addWidget(rb1);
    this->addWidget(rb2);

    this->addWidget(spBox[spBox.size()-1]);

    this->addWidget(colorBtn);

    palette = colorBtn->palette();

}

imbaLayout::~imbaLayout()
{
    for(auto x:label)
    {
        this->removeWidget(x);
        delete x;
    }

    for(auto x:spBox)
    {
        this->removeWidget(x);
        delete x;
    }

    delete rb1;
    delete rb2;

    delete group;

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
        spBox[i] = new QDoubleSpinBox();
        spBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spBox[i]->setMinimum(-100);

        label[i] = new QLabel(QString("x%1 ").arg(i+1));

    }
}

void imbaLayout::setColor(QColor color)
{
    if(color == Qt::black)
    {
        this->color = color;
        colorBtn->setPalette(palette);
        colorBtn->setStyleSheet("");
        colorBtn->update();
    }
    else
    {
        this->color = color;
        QPalette pal = colorBtn->palette();
        pal.setColor(QPalette::Base,color);
        pal.setColor(QPalette::Window,color);

        pal.setColor(QPalette::Button,color);
        pal.setColor(QPalette::WindowText,color);

        colorBtn->setAutoFillBackground(true);
        colorBtn->setPalette(pal);
        QString s=QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
        colorBtn->setStyleSheet(s);

    }

    colorBtn->update();
    emit colorChanged();
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
}

