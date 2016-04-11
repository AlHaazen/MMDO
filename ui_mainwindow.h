/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <view.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_2;
    QAction *action_2;
    QAction *actionBuild;
    QAction *actionCalculate_area;
    QAction *actionClear;
    QAction *actionClose;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    View *graphicsView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_12;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *Simplex;
    QPushButton *pushButton_7;
    QPushButton *FractLinear;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *Equals;
    QSpinBox *Variables;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuImba_knopka;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(881, 631);
        QIcon icon;
        icon.addFile(QStringLiteral(":/myicon/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout_2 = new QAction(MainWindow);
        actionAbout_2->setObjectName(QStringLiteral("actionAbout_2"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        actionBuild = new QAction(MainWindow);
        actionBuild->setObjectName(QStringLiteral("actionBuild"));
        actionCalculate_area = new QAction(MainWindow);
        actionCalculate_area->setObjectName(QStringLiteral("actionCalculate_area"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 741, 401));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new View(layoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setMinimum(-100);
        spinBox_2->setMaximum(100);
        spinBox_2->setValue(1);

        horizontalLayout_2->addWidget(spinBox_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMinimum(-100);
        spinBox->setMaximum(100);
        spinBox->setValue(3);

        horizontalLayout_2->addWidget(spinBox);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(120, 0));
        layoutWidget_5 = new QWidget(groupBox_5);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 0, 101, 21));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        radioButton_11 = new QRadioButton(layoutWidget_5);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        radioButton_11->setChecked(true);

        horizontalLayout_12->addWidget(radioButton_11);

        radioButton_12 = new QRadioButton(layoutWidget_5);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));

        horizontalLayout_12->addWidget(radioButton_12);


        horizontalLayout_2->addWidget(groupBox_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setEnabled(true);
        label_16->setMinimumSize(QSize(400, 0));

        verticalLayout->addWidget(label_16);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setCheckable(false);

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        Simplex = new QPushButton(layoutWidget);
        Simplex->setObjectName(QStringLiteral("Simplex"));
        sizePolicy.setHeightForWidth(Simplex->sizePolicy().hasHeightForWidth());
        Simplex->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(Simplex);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_2->addWidget(pushButton_7);

        FractLinear = new QPushButton(layoutWidget);
        FractLinear->setObjectName(QStringLiteral("FractLinear"));

        verticalLayout_2->addWidget(FractLinear);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoFillBackground(true);

        verticalLayout_2->addWidget(pushButton_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Equals = new QSpinBox(layoutWidget);
        Equals->setObjectName(QStringLiteral("Equals"));
        Equals->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Equals->setMaximum(10);
        Equals->setValue(4);

        horizontalLayout_4->addWidget(Equals);

        Variables = new QSpinBox(layoutWidget);
        Variables->setObjectName(QStringLiteral("Variables"));
        Variables->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Variables->setValue(2);

        horizontalLayout_4->addWidget(Variables);


        verticalLayout_2->addLayout(horizontalLayout_4);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_4);


        horizontalLayout_13->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_13);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 881, 21));
        menuImba_knopka = new QMenu(menuBar);
        menuImba_knopka->setObjectName(QStringLiteral("menuImba_knopka"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuImba_knopka->menuAction());
        menuImba_knopka->addSeparator();
        menuImba_knopka->addAction(actionAbout_2);
        menuImba_knopka->addAction(action_2);
        menu->addAction(actionBuild);
        menu->addAction(actionCalculate_area);
        menu->addAction(actionClear);
        menu->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\234\320\224\320\236 ", 0));
        actionAbout_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 Qt", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\234\320\265\320\275\320\265", 0));
        actionBuild->setText(QApplication::translate("MainWindow", "Build", 0));
        actionCalculate_area->setText(QApplication::translate("MainWindow", "Calculate area", 0));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        label->setText(QApplication::translate("MainWindow", "F(x1;x2)=", 0));
        label_2->setText(QApplication::translate("MainWindow", "x1 +", 0));
        label_3->setText(QApplication::translate("MainWindow", "x2 ->", 0));
        groupBox_5->setTitle(QString());
        radioButton_11->setText(QApplication::translate("MainWindow", "max", 0));
        radioButton_12->setText(QApplication::translate("MainWindow", "min", 0));
        label_16->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Build", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Calculate area", 0));
        Simplex->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\274\320\273\320\265\320\272\321\201", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\246\321\226\320\273\320\276\321\207\320\270\321\201\320\273\320\276\320\262\320\260", 0));
        FractLinear->setText(QApplication::translate("MainWindow", "\320\224\321\200\320\276\320\261\320\276\320\262\320\276-\320\273\321\226\320\275\321\226\320\271\320\275\320\260", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\224\320\262\320\276\321\227\321\201\321\202\320\260 \320\267\320\260\320\264\320\260\321\207\320\260", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Close", 0));
        menuImba_knopka->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\272\320\260", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\321\206\321\226\321\227", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
