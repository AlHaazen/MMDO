#include "targetlayout.h"

targetLayout::targetLayout() {
    checkBox = new QCheckBox("Дробова");

    rb1 = new QRadioButton("Mакс");
    rb2 = new QRadioButton("Mін");

    rbLayout = new QHBoxLayout;
    rbLayout->addWidget(rb1);
    rbLayout->addWidget(rb2);

    ctrlLayout = new QVBoxLayout;
    ctrlLayout->addLayout(rbLayout);
    ctrlLayout->addWidget(checkBox);

    for (int i = 0; i < n; i++) {
        spBox1.push_back(new QDoubleSpinBox);
        spBox1[i]->setMinimum(-1000);
        spBox1[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);

        spBox2.push_back(new QDoubleSpinBox);
        spBox2[i]->setMinimum(-1000);
        spBox2[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spBox2[i]->setVisible(checkBox->isChecked());

        label1.push_back(new QLabel(QString("x%1 + ").arg(i + 1)));
        label2.push_back(new QLabel(QString("y%1 + ").arg(i + 1)));
        label2[i]->setVisible(false);

        hBox1.push_back(new QHBoxLayout);
        hBox1[i]->addWidget(spBox1[i]);
        hBox1[i]->addWidget(label1[i]);

        hBox2.push_back(new QHBoxLayout);
        hBox2[i]->addWidget(spBox2[i]);
        hBox2[i]->addWidget(label2[i]);

        vBox.push_back(new QVBoxLayout);
        vBox[i]->addLayout(hBox1[i]);
        vBox[i]->addLayout(hBox2[i]);
    }

    label1[n - 1]->setText(QString("x%1").arg(n));
    label2[n - 1]->setText(QString("y%1").arg(n));

    this->addWidget(new QLabel("F(X1,...Xn) ="));

    for (auto x : vBox)
        this->addLayout(x);

    this->addLayout(ctrlLayout);

    connect(this->checkBox, &QCheckBox::stateChanged, this, &targetLayout::onFracChange);
}

targetLayout::~targetLayout() {
    delete checkBox;

    delete rb1;
    delete rb2;

    delete rbLayout;
    delete ctrlLayout;
}

void targetLayout::resize(int n) {
    if (n < this->n)
        for (int i = 0; i < this->n - n; i++) {
            this->removeItem(vBox.back());

            vBox.back()->removeItem(hBox1.back());
            vBox.back()->removeItem(hBox2.back());
            vBox.pop_back();

            hBox1.back()->removeWidget(spBox1.back());
            hBox1.back()->removeWidget(label1.back());

            spBox1.pop_back();
            label1.pop_back();

            hBox2.back()->removeWidget(spBox2.back());
            hBox2.back()->removeWidget(label2.back());

            label2.pop_back();
            spBox2.pop_back();
        }
    else {
        label1[this->n - 1]->setText(QString("x%1 +").arg(this->n));
        label2[this->n - 1]->setText(QString("y%1 +").arg(this->n));

        for (int i = 0; i < n - this->n; i++) {
            spBox1.push_back(new QDoubleSpinBox);
            spBox1[i]->setMinimum(-1000);
            spBox1[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);

            spBox2.push_back(new QDoubleSpinBox);
            spBox2[i]->setMinimum(-1000);
            spBox2[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
            spBox2[i]->setVisible(checkBox->isChecked());

            label1.push_back(new QLabel(QString("x%1 + ").arg(i + 1)));
            label2.push_back(new QLabel(QString("y%1 + ").arg(i + 1)));
            label2[i]->setVisible(checkBox->isChecked());

            hBox1.push_back(new QHBoxLayout);
            hBox1[i]->addWidget(spBox1[i]);
            hBox1[i]->addWidget(label1[i]);

            hBox2.push_back(new QHBoxLayout);
            hBox2[i]->addWidget(spBox2[i]);
            hBox2[i]->addWidget(label2[i]);

            vBox.push_back(new QVBoxLayout);
            vBox[i]->addLayout(hBox1[i]);
            vBox[i]->addLayout(hBox2[i]);
        }
        label1[n - 1]->setText(QString("x%1").arg(n));
        label2[n - 1]->setText(QString("y%1").arg(n));
    }

    this->n = n;
}

bool targetLayout::findMax() {
    if (rb1->isChecked())
        return true;
    return false;
}

bool targetLayout::isFrac() {
    if (checkBox->isChecked())
        return true;
    return false;
}

vector<double> targetLayout::getX() {
    vector<double> res;
    for (auto x : spBox1)
        res.push_back(x->value());
    return res;
}

int targetLayout::setX(vector<double> x) {
    if (x.size() != n)
        return -1;

    for (int i = 0; i < n; i++)
        spBox1[i]->setValue(x[i]);
    return 0;
}

vector<double> targetLayout::getY() {
    vector<double> res;
    for (auto x : spBox2)
        res.push_back(x->value());
    return res;
}

int targetLayout::setY(vector<double> x) {
    if (x.size() != n)
        return -1;

    for (int i = 0; i < n; i++)
        spBox2[i]->setValue(x[i]);
    return 0;
}

void targetLayout::setTarget(bool max) {
    if (max)
        rb1->setChecked(true), rb2->setChecked(false);
    else
        rb1->setChecked(false), rb2->setChecked(true);
}

void targetLayout::setFrac(bool x) {
    checkBox->setChecked(x);
}

double targetLayout::getA() {
    return spBox1[0]->value();
}

double targetLayout::getB() {
    return spBox1[1]->value();
}

double targetLayout::getC() {
    return spBox1[2]->value();
}

void targetLayout::onFracChange(int value) {
    for (auto x : spBox2)
        x->setVisible(value);
    for (auto x : label2)
        x->setVisible(value);
}
