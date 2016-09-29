/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    View *graphicsView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBoxGradient;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *Simplex;
    QPushButton *IntLinear;
    QPushButton *FractLinear;
    QPushButton *DualSimplex;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *Equals;
    QSpinBox *Variables;
    QPushButton *Clear;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuImba_knopka;
    QMenu *menu;
    QMenu *menu_2;

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
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 681, 411));
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
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        checkBoxGradient = new QCheckBox(layoutWidget);
        checkBoxGradient->setObjectName(QStringLiteral("checkBoxGradient"));

        verticalLayout_6->addWidget(checkBoxGradient);


        horizontalLayout_13->addLayout(verticalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_5);

        Simplex = new QPushButton(layoutWidget);
        Simplex->setObjectName(QStringLiteral("Simplex"));
        sizePolicy.setHeightForWidth(Simplex->sizePolicy().hasHeightForWidth());
        Simplex->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(Simplex);

        IntLinear = new QPushButton(layoutWidget);
        IntLinear->setObjectName(QStringLiteral("IntLinear"));

        verticalLayout_2->addWidget(IntLinear);

        FractLinear = new QPushButton(layoutWidget);
        FractLinear->setObjectName(QStringLiteral("FractLinear"));

        verticalLayout_2->addWidget(FractLinear);

        DualSimplex = new QPushButton(layoutWidget);
        DualSimplex->setObjectName(QStringLiteral("DualSimplex"));
        DualSimplex->setAutoFillBackground(true);

        verticalLayout_2->addWidget(DualSimplex);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Equals = new QSpinBox(layoutWidget);
        Equals->setObjectName(QStringLiteral("Equals"));
        Equals->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Equals->setMaximum(10);
        Equals->setValue(9);

        horizontalLayout_4->addWidget(Equals);

        Variables = new QSpinBox(layoutWidget);
        Variables->setObjectName(QStringLiteral("Variables"));
        Variables->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Variables->setValue(2);

        horizontalLayout_4->addWidget(Variables);


        verticalLayout_2->addLayout(horizontalLayout_4);

        Clear = new QPushButton(layoutWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        sizePolicy.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(Clear);


        horizontalLayout_13->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_13);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 881, 19));
        menuImba_knopka = new QMenu(menuBar);
        menuImba_knopka->setObjectName(QStringLiteral("menuImba_knopka"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuImba_knopka->menuAction());
        menuImba_knopka->addSeparator();
        menuImba_knopka->addAction(actionAbout_2);
        menuImba_knopka->addAction(action_2);
        menu->addAction(actionBuild);
        menu->addAction(actionCalculate_area);
        menu->addAction(actionClear);
        menu->addAction(actionClose);
        menu_2->addAction(actionLoad);
        menu_2->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\241", 0));
        actionAbout_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 &Qt", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\234\320\265\320\275\320\265", 0));
        actionBuild->setText(QApplication::translate("MainWindow", "&Build", 0));
        actionCalculate_area->setText(QApplication::translate("MainWindow", "&Calculate area", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Cl&ose", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270", 0));
        actionSave->setText(QApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", 0));
        label_16->setText(QString());
        checkBoxGradient->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\264\321\226\321\224\320\275\321\202", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\240\320\276\320\267\321\200\320\260\321\205\321\203\320\262\320\260\321\202\320\270", 0));
        Simplex->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\274\320\273\320\265\320\272\321\201", 0));
        IntLinear->setText(QApplication::translate("MainWindow", "\320\246\321\226\320\273\320\276\321\207\320\270\321\201\320\273\320\276\320\262\320\260", 0));
        FractLinear->setText(QApplication::translate("MainWindow", "\320\224\321\200\320\276\320\261\320\276\320\262\320\276-\320\273\321\226\320\275\321\226\320\271\320\275\320\260", 0));
        DualSimplex->setText(QApplication::translate("MainWindow", "\320\224\320\262\320\276\321\227\321\201\321\202\320\260 \320\267\320\260\320\264\320\260\321\207\320\260", 0));
        Clear->setText(QApplication::translate("MainWindow", "Clear", 0));
        menuImba_knopka->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\272\320\260", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\321\206\321\226\321\227", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
