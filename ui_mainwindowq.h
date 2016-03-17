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
#include <QtWidgets/QGraphicsView>
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
    QGraphicsView *graphicsView;
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox_3;
    QLabel *label_5;
    QSpinBox *spinBox_4;
    QLabel *label_6;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QSpinBox *spinBox_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBox_6;
    QLabel *label_8;
    QSpinBox *spinBox_7;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QSpinBox *spinBox_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QSpinBox *spinBox_9;
    QLabel *label_11;
    QSpinBox *spinBox_10;
    QLabel *label_12;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QSpinBox *spinBox_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QSpinBox *spinBox_12;
    QLabel *label_14;
    QSpinBox *spinBox_13;
    QLabel *label_15;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QSpinBox *spinBox_14;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QSpinBox *Equals;
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
        graphicsView = new QGraphicsView(layoutWidget);
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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_3->setMinimum(-100);
        spinBox_3->setMaximum(100);
        spinBox_3->setValue(8);

        horizontalLayout_4->addWidget(spinBox_3);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        spinBox_4 = new QSpinBox(layoutWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_4->setMinimum(-100);
        spinBox_4->setMaximum(100);
        spinBox_4->setValue(-5);

        horizontalLayout_4->addWidget(spinBox_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(120, 0));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 101, 21));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_3 = new QRadioButton(layoutWidget1);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setChecked(false);

        horizontalLayout_5->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(layoutWidget1);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setChecked(true);

        horizontalLayout_5->addWidget(radioButton_4);


        horizontalLayout_4->addWidget(groupBox);

        spinBox_5 = new QSpinBox(layoutWidget);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_5->setMinimum(-100);
        spinBox_5->setMaximum(100);
        spinBox_5->setValue(40);

        horizontalLayout_4->addWidget(spinBox_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox_6 = new QSpinBox(layoutWidget);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_6->setMinimum(-100);
        spinBox_6->setMaximum(100);
        spinBox_6->setValue(2);

        horizontalLayout_6->addWidget(spinBox_6);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        spinBox_7 = new QSpinBox(layoutWidget);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_7->setMinimum(-100);
        spinBox_7->setMaximum(100);
        spinBox_7->setValue(5);

        horizontalLayout_6->addWidget(spinBox_7);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(120, 0));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 0, 101, 21));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        radioButton_5 = new QRadioButton(layoutWidget_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setChecked(true);

        horizontalLayout_7->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(layoutWidget_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setChecked(false);

        horizontalLayout_7->addWidget(radioButton_6);


        horizontalLayout_6->addWidget(groupBox_2);

        spinBox_8 = new QSpinBox(layoutWidget);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_8->setMinimum(-100);
        spinBox_8->setMaximum(100);
        spinBox_8->setValue(10);

        horizontalLayout_6->addWidget(spinBox_8);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        spinBox_9 = new QSpinBox(layoutWidget);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));
        spinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_9->setMinimum(-100);
        spinBox_9->setMaximum(100);
        spinBox_9->setValue(-6);

        horizontalLayout_8->addWidget(spinBox_9);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_8->addWidget(label_11);

        spinBox_10 = new QSpinBox(layoutWidget);
        spinBox_10->setObjectName(QStringLiteral("spinBox_10"));
        spinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_10->setMinimum(-100);
        spinBox_10->setMaximum(100);
        spinBox_10->setValue(5);

        horizontalLayout_8->addWidget(spinBox_10);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_8->addWidget(label_12);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(120, 0));
        layoutWidget_3 = new QWidget(groupBox_3);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 0, 101, 21));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        radioButton_7 = new QRadioButton(layoutWidget_3);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setChecked(false);

        horizontalLayout_9->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(layoutWidget_3);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setChecked(true);

        horizontalLayout_9->addWidget(radioButton_8);


        horizontalLayout_8->addWidget(groupBox_3);

        spinBox_11 = new QSpinBox(layoutWidget);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));
        spinBox_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_11->setMinimum(-100);
        spinBox_11->setMaximum(100);
        spinBox_11->setValue(60);

        horizontalLayout_8->addWidget(spinBox_11);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_10->addWidget(label_13);

        spinBox_12 = new QSpinBox(layoutWidget);
        spinBox_12->setObjectName(QStringLiteral("spinBox_12"));
        spinBox_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_12->setMinimum(-100);
        spinBox_12->setMaximum(100);
        spinBox_12->setValue(2);

        horizontalLayout_10->addWidget(spinBox_12);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_10->addWidget(label_14);

        spinBox_13 = new QSpinBox(layoutWidget);
        spinBox_13->setObjectName(QStringLiteral("spinBox_13"));
        spinBox_13->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_13->setMinimum(-100);
        spinBox_13->setMaximum(100);
        spinBox_13->setValue(1);

        horizontalLayout_10->addWidget(spinBox_13);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_10->addWidget(label_15);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(120, 0));
        layoutWidget_4 = new QWidget(groupBox_4);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 0, 101, 21));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        radioButton_9 = new QRadioButton(layoutWidget_4);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setChecked(false);

        horizontalLayout_11->addWidget(radioButton_9);

        radioButton_10 = new QRadioButton(layoutWidget_4);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        radioButton_10->setChecked(true);

        horizontalLayout_11->addWidget(radioButton_10);


        horizontalLayout_10->addWidget(groupBox_4);

        spinBox_14 = new QSpinBox(layoutWidget);
        spinBox_14->setObjectName(QStringLiteral("spinBox_14"));
        spinBox_14->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_14->setMinimum(-100);
        spinBox_14->setMaximum(100);
        spinBox_14->setValue(14);

        horizontalLayout_10->addWidget(spinBox_14);


        verticalLayout->addLayout(horizontalLayout_10);

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

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_3);

        Equals = new QSpinBox(layoutWidget);
        Equals->setObjectName(QStringLiteral("Equals"));
        Equals->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Equals->setMaximum(10);
        Equals->setValue(4);

        verticalLayout_2->addWidget(Equals);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\234\320\224\320\236 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260 \342\204\2261", 0));
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
        label_4->setText(QApplication::translate("MainWindow", "1:", 0));
        label_5->setText(QApplication::translate("MainWindow", "x1 +", 0));
        label_6->setText(QApplication::translate("MainWindow", "x2", 0));
        groupBox->setTitle(QString());
        radioButton_3->setText(QApplication::translate("MainWindow", ">=", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "<=", 0));
        label_7->setText(QApplication::translate("MainWindow", "2:", 0));
        label_8->setText(QApplication::translate("MainWindow", "x1 +", 0));
        label_9->setText(QApplication::translate("MainWindow", "x2", 0));
        groupBox_2->setTitle(QString());
        radioButton_5->setText(QApplication::translate("MainWindow", ">=", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "<=", 0));
        label_10->setText(QApplication::translate("MainWindow", "3:", 0));
        label_11->setText(QApplication::translate("MainWindow", "x1 +", 0));
        label_12->setText(QApplication::translate("MainWindow", "x2", 0));
        groupBox_3->setTitle(QString());
        radioButton_7->setText(QApplication::translate("MainWindow", ">=", 0));
        radioButton_8->setText(QApplication::translate("MainWindow", "<=", 0));
        label_13->setText(QApplication::translate("MainWindow", "4:", 0));
        label_14->setText(QApplication::translate("MainWindow", "x1 +", 0));
        label_15->setText(QApplication::translate("MainWindow", "x2", 0));
        groupBox_4->setTitle(QString());
        radioButton_9->setText(QApplication::translate("MainWindow", ">=", 0));
        radioButton_10->setText(QApplication::translate("MainWindow", "<=", 0));
        label_16->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "Build", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Calculate area", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Simplex", 0));
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
