/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *sInputName;
    QPushButton *pushButtonAddPerson;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QRadioButton *GenderButtonMale;
    QRadioButton *GenderButtonFemale;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidgetList;
    QPushButton *pushButtonRemovePerson;
    QPushButton *pushButtonClearPerson;
    QLabel *label_4;
    QPushButton *pushButtonTurnOff;
    QGroupBox *groupBox_4;
    QPushButton *pushButtonSaveResult;
    QLineEdit *sSaveFileName;
    QLabel *label_11;
    QTableWidget *tableWidgetResult;
    QLabel *label_12;
    QGroupBox *groupBox_5;
    QRadioButton *ModeButton0;
    QRadioButton *ModeButton1;
    QSpinBox *spinBoxGroupNum;
    QLabel *label_6;
    QGroupBox *groupBox_6;
    QLabel *labelLog;
    QPushButton *pushButtonStart;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QProgressBar *progressBar;
    QGroupBox *groupBox_7;
    QCheckBox *checkBoxToS;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 311, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225")});
        font.setPointSize(26);
        label->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 291, 471));
        QFont font1;
        font1.setPointSize(14);
        groupBox->setFont(font1);
        sInputName = new QLineEdit(groupBox);
        sInputName->setObjectName(QString::fromUtf8("sInputName"));
        sInputName->setGeometry(QRect(50, 30, 111, 21));
        QFont font2;
        font2.setPointSize(11);
        sInputName->setFont(font2);
#if QT_CONFIG(accessibility)
        sInputName->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        sInputName->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        pushButtonAddPerson = new QPushButton(groupBox);
        pushButtonAddPerson->setObjectName(QString::fromUtf8("pushButtonAddPerson"));
        pushButtonAddPerson->setGeometry(QRect(180, 30, 91, 51));
        pushButtonAddPerson->setFont(font2);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 41, 16));
        QFont font3;
        font3.setPointSize(12);
        label_2->setFont(font3);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 41, 16));
        label_3->setFont(font3);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 60, 111, 21));
        groupBox_2->setFont(font2);
        GenderButtonMale = new QRadioButton(groupBox_2);
        GenderButtonMale->setObjectName(QString::fromUtf8("GenderButtonMale"));
        GenderButtonMale->setGeometry(QRect(10, 0, 41, 20));
        GenderButtonFemale = new QRadioButton(groupBox_2);
        GenderButtonFemale->setObjectName(QString::fromUtf8("GenderButtonFemale"));
        GenderButtonFemale->setGeometry(QRect(70, 0, 41, 20));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 90, 271, 321));
        groupBox_3->setFont(font3);
        tableWidgetList = new QTableWidget(groupBox_3);
        if (tableWidgetList->columnCount() < 2)
            tableWidgetList->setColumnCount(2);
        tableWidgetList->setObjectName(QString::fromUtf8("tableWidgetList"));
        tableWidgetList->setEnabled(true);
        tableWidgetList->setGeometry(QRect(10, 30, 251, 281));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetList->sizePolicy().hasHeightForWidth());
        tableWidgetList->setSizePolicy(sizePolicy);
#if QT_CONFIG(accessibility)
        tableWidgetList->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        tableWidgetList->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        tableWidgetList->setAutoFillBackground(false);
        tableWidgetList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidgetList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidgetList->setAutoScroll(true);
        tableWidgetList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidgetList->setDragDropOverwriteMode(true);
        tableWidgetList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidgetList->setRowCount(0);
        tableWidgetList->setColumnCount(2);
        tableWidgetList->horizontalHeader()->setVisible(true);
        tableWidgetList->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidgetList->horizontalHeader()->setMinimumSectionSize(95);
        tableWidgetList->horizontalHeader()->setDefaultSectionSize(95);
        tableWidgetList->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetList->horizontalHeader()->setStretchLastSection(false);
        tableWidgetList->verticalHeader()->setVisible(true);
        tableWidgetList->verticalHeader()->setCascadingSectionResizes(false);
        tableWidgetList->verticalHeader()->setMinimumSectionSize(30);
        tableWidgetList->verticalHeader()->setDefaultSectionSize(30);
        tableWidgetList->verticalHeader()->setHighlightSections(true);
        tableWidgetList->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetList->verticalHeader()->setStretchLastSection(false);
        pushButtonRemovePerson = new QPushButton(groupBox);
        pushButtonRemovePerson->setObjectName(QString::fromUtf8("pushButtonRemovePerson"));
        pushButtonRemovePerson->setGeometry(QRect(150, 420, 71, 41));
        pushButtonRemovePerson->setFont(font2);
        pushButtonClearPerson = new QPushButton(groupBox);
        pushButtonClearPerson->setObjectName(QString::fromUtf8("pushButtonClearPerson"));
        pushButtonClearPerson->setGeometry(QRect(230, 420, 51, 41));
        QFont font4;
        font4.setPointSize(9);
        pushButtonClearPerson->setFont(font4);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 420, 141, 41));
        label_4->setFont(font4);
        pushButtonTurnOff = new QPushButton(centralwidget);
        pushButtonTurnOff->setObjectName(QString::fromUtf8("pushButtonTurnOff"));
        pushButtonTurnOff->setGeometry(QRect(320, 10, 71, 51));
        pushButtonTurnOff->setFont(font3);
        pushButtonTurnOff->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(490, 70, 291, 341));
        groupBox_4->setFont(font1);
        pushButtonSaveResult = new QPushButton(groupBox_4);
        pushButtonSaveResult->setObjectName(QString::fromUtf8("pushButtonSaveResult"));
        pushButtonSaveResult->setGeometry(QRect(190, 290, 91, 41));
        pushButtonSaveResult->setFont(font2);
        sSaveFileName = new QLineEdit(groupBox_4);
        sSaveFileName->setObjectName(QString::fromUtf8("sSaveFileName"));
        sSaveFileName->setGeometry(QRect(70, 300, 91, 21));
        sSaveFileName->setFont(font2);
#if QT_CONFIG(accessibility)
        sSaveFileName->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        sSaveFileName->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        sSaveFileName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 300, 61, 21));
        label_11->setFont(font4);
        tableWidgetResult = new QTableWidget(groupBox_4);
        tableWidgetResult->setObjectName(QString::fromUtf8("tableWidgetResult"));
        tableWidgetResult->setGeometry(QRect(10, 31, 271, 251));
        sizePolicy.setHeightForWidth(tableWidgetResult->sizePolicy().hasHeightForWidth());
        tableWidgetResult->setSizePolicy(sizePolicy);
        tableWidgetResult->setFont(font3);
        tableWidgetResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetResult->setRowCount(0);
        tableWidgetResult->setColumnCount(0);
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(160, 300, 31, 21));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        label_12->setFont(font5);
        label_12->setAlignment(Qt::AlignCenter);
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(320, 70, 161, 111));
        groupBox_5->setFont(font1);
        ModeButton0 = new QRadioButton(groupBox_5);
        ModeButton0->setObjectName(QString::fromUtf8("ModeButton0"));
        ModeButton0->setGeometry(QRect(10, 20, 141, 31));
        QFont font6;
        font6.setPointSize(10);
        ModeButton0->setFont(font6);
        ModeButton1 = new QRadioButton(groupBox_5);
        ModeButton1->setObjectName(QString::fromUtf8("ModeButton1"));
        ModeButton1->setGeometry(QRect(10, 40, 151, 31));
        ModeButton1->setFont(font6);
        spinBoxGroupNum = new QSpinBox(groupBox_5);
        spinBoxGroupNum->setObjectName(QString::fromUtf8("spinBoxGroupNum"));
        spinBoxGroupNum->setGeometry(QRect(70, 70, 51, 31));
        spinBoxGroupNum->setFont(font2);
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 70, 51, 31));
        label_6->setFont(font5);
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(320, 410, 461, 131));
        groupBox_6->setFont(font1);
        labelLog = new QLabel(groupBox_6);
        labelLog->setObjectName(QString::fromUtf8("labelLog"));
        labelLog->setGeometry(QRect(10, 30, 441, 91));
        labelLog->setFont(font4);
        labelLog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        labelLog->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(320, 300, 161, 61));
        QFont font7;
        font7.setPointSize(18);
        font7.setBold(true);
        pushButtonStart->setFont(font7);
        pushButtonStart->setLayoutDirection(Qt::LeftToRight);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 10, 261, 21));
        QFont font8;
        font8.setBold(true);
        label_7->setFont(font8);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 20, 261, 41));
        label_8->setFont(font8);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(240, 50, 71, 16));
        label_9->setFont(font6);
        label_9->setOpenExternalLinks(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(400, 10, 101, 51));
        label_10->setFont(font6);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
""));
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setOpenExternalLinks(true);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(320, 370, 161, 23));
        progressBar->setValue(0);
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(320, 190, 161, 91));
        groupBox_7->setFont(font1);
        checkBoxToS = new QCheckBox(groupBox_7);
        checkBoxToS->setObjectName(QString::fromUtf8("checkBoxToS"));
        checkBoxToS->setGeometry(QRect(10, 20, 141, 71));
        checkBoxToS->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButtonStart->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\354\235\270\354\233\220 \353\266\204\353\260\260 \355\224\204\353\241\234\352\267\270\353\236\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\354\235\270\354\233\220 \352\264\200\353\246\254", nullptr));
        pushButtonAddPerson->setText(QCoreApplication::translate("MainWindow", "\354\266\224\352\260\200\n"
"(Enter Key)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\354\204\261\353\263\204", nullptr));
        groupBox_2->setTitle(QString());
        GenderButtonMale->setText(QCoreApplication::translate("MainWindow", "\353\202\250", nullptr));
        GenderButtonFemale->setText(QCoreApplication::translate("MainWindow", "\354\227\254", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "List", nullptr));
        pushButtonRemovePerson->setText(QCoreApplication::translate("MainWindow", "\354\202\255\354\240\234", nullptr));
        pushButtonClearPerson->setText(QCoreApplication::translate("MainWindow", "\354\264\210\352\270\260\355\231\224", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "- \354\234\204 \355\221\234\354\227\220\354\204\234 \355\201\264\353\246\255 \355\233\204 \354\202\255\354\240\234 \n"
"- \353\215\224\353\270\224\355\201\264\353\246\255\354\234\274\353\241\234 \354\210\230\354\240\225 \352\260\200\353\212\245", nullptr));
        pushButtonTurnOff->setText(QCoreApplication::translate("MainWindow", "\354\242\205\353\243\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\352\262\260\352\263\274", nullptr));
        pushButtonSaveResult->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        sSaveFileName->setText(QCoreApplication::translate("MainWindow", "result", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\355\214\214\354\235\274 \354\235\264\353\246\204", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", ".txt", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\354\204\244\354\240\225", nullptr));
        ModeButton0->setText(QCoreApplication::translate("MainWindow", "\354\235\274\353\260\230(\354\235\270\354\233\220\353\247\214 \353\266\204\353\260\260)", nullptr));
        ModeButton1->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \353\266\204\353\260\260(\352\267\270\353\243\271\354\204\236\352\270\260)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\352\267\270\353\243\271 \354\210\230", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Log", nullptr));
        labelLog->setText(QString());
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start !", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Copyright (C) 2024 \353\260\225\354\203\201\355\230\204. All right reserved.", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Contact: pash0302@gmail.com", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Version 1.0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><a href=\"https://github.com/SanghyunPark01/GroupSplitter\"><span style=\" font-size:11pt; text-decoration: underline; color:#0000ff;\">Source Code</span></a></p></body></html>", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\354\235\264\354\232\251 \354\225\275\352\264\200", nullptr));
        checkBoxToS->setText(QCoreApplication::translate("MainWindow", "[\355\225\204\354\210\230] \354\226\264\353\226\240\355\225\234 \352\262\260\352\263\274\352\260\200 \n"
"\353\202\230\354\231\200\353\217\204 \353\260\233\354\225\204\353\223\244\354\235\274 \352\262\203\354\235\204\n"
"\354\225\275\354\206\215\355\225\251\353\213\210\353\213\244.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
