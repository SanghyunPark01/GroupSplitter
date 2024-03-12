#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "person.h"
#include <map>
#include <vector>
#include <iostream>
#include <QThread>
#include <QObject>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>

#include "ui_mainwindow.h"

class Processor : public QThread
{
    Q_OBJECT
private:
    std::vector<Person*> _mvpDatabase;

    int _mnFlag = 0; // stop, run
    int _mnMode = -1;
    int _mnShuffleIter = 0;
    int _mnGroupNum = 0;

    int _mnProgressValue = 0;

    std::mutex _mMtxFlag;
    std::mutex _mMtxMode;
    std::mutex _mMtxDB;

signals:
    void processSignal(int n);
private:
    void processGrouping(int nMode);
    void shuffleNum(std::vector<int> &idx);
    void mode0(std::vector<int> &vnidx);
    void mode1(std::vector<int> &vnidx);
public:

    Processor();
    void setFlag(int n);
    void setMode(int n);
    void setGroupNum(int n);

    void run() // thread
    {
        while(true)
        {
//            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            QThread::msleep(10);
            if(_mnFlag == -1)break;
            if(_mnFlag == 0)continue;
            _mnProgressValue = 0;
            processGrouping(_mnMode);
            _mnProgressValue = 100;
            emit processSignal(_mnProgressValue);
            _mnFlag = 0;
        }

    }
    void clearData(void);
    void inputData(Person* data);
    void removeData(int index);
    void printData(void);
    std::vector<Person*> getDataBase(void);
};

#endif // PROCESSOR_H
