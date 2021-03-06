﻿#include "imba.h"

imbaLayout::imbaLayout(int i)
{
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
}

