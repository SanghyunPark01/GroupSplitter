#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QDebug>
#include <string>
#include <vector>
#include <fstream>
#include <QFile>

#include "processor.h"
#include "utility.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonTurnOff_clicked();

    void on_pushButtonAddPerson_clicked();

    void on_sInputName_textChanged(const QString &arg1);

    void on_sInputName_returnPressed();

    void on_pushButtonRemovePerson_clicked();

    void on_pushButtonClearPerson_clicked();

    void on_tableWidgetList_itemClicked(QTableWidgetItem *item);

    void on_pushButtonStart_clicked();

    void on_progressBar_valueChanged(const int &value);

    void progressSignal(int n);

    void on_pushButtonSaveResult_clicked();

private:
    Ui::MainWindow *ui;
    std::string _msTempName;
    int _mnPersonNum = 0;
    int _mnRemoveIndex = -2;
    std::vector<std::string> _mvsLogData;
    bool _mbOnGoingFlag = false;
    int _mnGroupNum = 0;

    Processor* _mMainProcessor = new Processor();
    void insertPerson(void);
    void removePerson(void);
    void addLog(std::string msg);
};
#endif // MAINWINDOW_H
