#include "processor.h"

Processor::Processor(){}
void Processor::setFlag(int n)
{
    std::unique_lock<std::mutex>(_mMtxFlag);
    _mnFlag = n;
}
void Processor::setMode(int n)
{
    std::unique_lock<std::mutex>(_mMtxMode);
    _mnMode = n;
}
void Processor::setGroupNum(int n)
{
    std::unique_lock<std::mutex>(_mMtxMode);
    _mnGroupNum = n;
}
void Processor::clearData(void)
{
    removeData(-1);
}
void Processor::inputData(Person* p)
{
    if(p->getName().size() < 2)
    {
        return;
    }
    _mvpDatabase.push_back(p);
}
void Processor::removeData(int index)
{
    std::unique_lock<std::mutex>(_mMtxDB);
    if(index == -1)
    {
        for(int i = 0; i < _mvpDatabase.size(); i++)
        {
            delete _mvpDatabase[i];
        }
        _mvpDatabase.clear();
        return;
    }
    Person* tempP = _mvpDatabase[index];
    _mvpDatabase.erase(_mvpDatabase.begin()+index);
    delete tempP;
}

void Processor::printData(void)
{
    std::unique_lock<std::mutex>(_mMtxDB);
    for(int i = 0; i < _mvpDatabase.size(); i++)
    {
        std::cout << _mvpDatabase[i]->getName() << " "<< _mvpDatabase[i]->getGender() << "\n";
    }
}
 std::vector<Person*> Processor::getDataBase(void)
 {
     return _mvpDatabase;
 }

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@ Process @@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

void Processor::processGrouping(int nMode)
{
    // mode
    // 0: general
    // 1: add mix with group
    int nDBSize = _mvpDatabase.size();

    std::vector<int> vnIdx;
    vnIdx.reserve(nDBSize);
    for(int i = 0; i < nDBSize; i++)
    {
        vnIdx.push_back(i);
    }

    _mnShuffleIter = nDBSize/20 + 1;
    while(_mnShuffleIter > 0)
    {
        shuffleNum(vnIdx);
        _mnShuffleIter--;
    }

    if(_mnMode == 0)
    {
        mode0(vnIdx);
    }
    else if(_mnMode == 1)
    {
        mode1(vnIdx);
    }
    else
    {
        mode0(vnIdx);
    }


}
void Processor::shuffleNum(std::vector<int> &idx)
{
    std::random_device rd_;
    std::mt19937 gen_(rd_());
    std::uniform_int_distribution<int> dis_(0,idx.size()-1);

    int nRandomIdx;
    int nTmpIdx;
    for(int i = 0; i < idx.size(); i++)
    {
        nRandomIdx = dis_(gen_);
        nTmpIdx = idx[i];
        idx[i] = idx[nRandomIdx];
        idx[nRandomIdx] = nTmpIdx;

        _mnProgressValue = ((double(i+((idx.size()/20 +1)-_mnShuffleIter)*idx.size())/((idx.size()/20 +1)*idx.size())))*100;
        emit processSignal(_mnProgressValue);
        QThread::msleep(10);
    }
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@ Mode @@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

void Processor::mode0(std::vector<int> &vnIdx)
{
    // arrange
    std::vector<std::vector<Person*>> vvpTmpGroup;
    // initialize
    for(int i = 0; i < _mnGroupNum; i++)
    {
        std::vector<Person*> vpTmpOneGroup;
        vpTmpOneGroup.push_back(_mvpDatabase[vnIdx[i]]);
        vvpTmpGroup.push_back(vpTmpOneGroup);
    }
    //
    for(int i = _mnGroupNum; i < vnIdx.size(); i++)
    {
        Person* tmpPerson = _mvpDatabase[vnIdx[i]];

        int nSelectedGroup = i % _mnGroupNum;
        vvpTmpGroup[nSelectedGroup].push_back(tmpPerson);
    }
    for(int i = 0; i < vvpTmpGroup.size(); i++)
    {
        for(int j = 0; j < vvpTmpGroup[i].size(); j++)
        {
            vvpTmpGroup[i][j]->setGroup(i);
        }
    }

}
void Processor::mode1(std::vector<int> &vnIdx)
{
    mode0(vnIdx);
    std::vector<int> vnGroupShuffle;
    for(int i = 0; i < _mnGroupNum; i++)vnGroupShuffle.push_back(i);

    std::random_device rd_;
    std::mt19937 gen_(rd_());
    std::uniform_int_distribution<int> dis_(0,vnGroupShuffle.size()-1);

    int nRandomIdx;
    int nTmpIdx;

    for(int i = 0; i < vnGroupShuffle.size(); i++)
    {
        nRandomIdx = dis_(gen_);
        nTmpIdx = vnGroupShuffle[i];
        vnGroupShuffle[i] = vnGroupShuffle[nRandomIdx];
        vnGroupShuffle[nRandomIdx] = nTmpIdx;
    }

    // rearrange
    for(int i = 0; i < _mvpDatabase.size(); i++)
    {
        int nNewGroup = vnGroupShuffle[_mvpDatabase[i]->getGroup()];
        _mvpDatabase[i]->setGroup(nNewGroup);
    }
}
