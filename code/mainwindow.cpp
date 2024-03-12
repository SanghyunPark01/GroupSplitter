#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GenderButtonMale->setChecked(true);
    QStringList qlsHeader;
    qlsHeader << "이름" << "성별";
    ui->tableWidgetList->setHorizontalHeaderLabels(qlsHeader);
    ui->progressBar->setValue(0);

    QObject::connect(_mMainProcessor, SIGNAL(processSignal(int)), this, SLOT(progressSignal(int)));
    _mMainProcessor->start();
}
MainWindow::~MainWindow()
{
//    _mMainProcessor->printData();
    _mMainProcessor->setFlag(-1);
    _mMainProcessor->wait();
    delete ui;
}
void MainWindow::on_pushButtonTurnOff_clicked()
{
    _mMainProcessor->setFlag(-1);
    _mMainProcessor->wait();
    this->close();
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@ ADD PERSON @@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

void MainWindow::on_sInputName_textChanged(const QString &arg1)
{
    _msTempName = arg1.toLocal8Bit().data();
}
void MainWindow::on_pushButtonAddPerson_clicked()
{
    insertPerson();
}
void MainWindow::on_sInputName_returnPressed()
{
    insertPerson();
}
void MainWindow::insertPerson(void)
{
    bool bGender = true;
    bGender = ui->GenderButtonMale->isChecked();
//    Person* personTemp = new Person(_msTempName, bGender);
//    _mMainProcessor.inputData(personTemp);
    if(_msTempName.size() >= 2)
    {
        ui->tableWidgetList->insertRow(0);
        // name
        QTableWidgetItem* qPresonName = new QTableWidgetItem();
        QString qName = QString::fromLocal8Bit(_msTempName);
        qPresonName->setText(qName);
        ui->tableWidgetList->setItem(0,0,qPresonName);
        // gender
        QTableWidgetItem* qPresonGender = new QTableWidgetItem();
        QString qGender;
        if(bGender)
        {
            qGender = QString::fromStdString("남");
        }
        else
        {
            qGender = QString::fromStdString("여");
        }

        qPresonGender->setText(qGender);
        ui->tableWidgetList->setItem(0,1,qPresonGender);
        _mnPersonNum++;
        addLog("[인원관리]인원을 추가하였습니다.");
    }
    ui->sInputName->clear();
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@ REMOVE PERSON @@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

void MainWindow::on_tableWidgetList_itemClicked(QTableWidgetItem *item)
{
    _mnRemoveIndex = item->row();
}
void MainWindow::on_pushButtonRemovePerson_clicked()
{
    removePerson();
}
void MainWindow::on_pushButtonClearPerson_clicked()
{
    _mnRemoveIndex = -1;
    removePerson();
}
void MainWindow::removePerson(void)
{
    if(_mnRemoveIndex < -1)return;
    if(_mnRemoveIndex == -1)
    {
//        ui->tableWidgetList->clear();
        for(int i = 0; i < _mnPersonNum; i++)ui->tableWidgetList->removeRow(0);
        _mnPersonNum = 0;
        addLog("[인원관리]인원을 초기화하였습니다.");
    }
    else
    {
        ui->tableWidgetList->removeRow(_mnRemoveIndex);
        _mnPersonNum--;
        addLog("[인원관리]인원을 삭제하였습니다.");
    }
    _mnRemoveIndex = -2;
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@ PROCESS @@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

void MainWindow::addLog(std::string msg)
{
    _mvsLogData.push_back(msg);
    if(_mvsLogData.size() > 5)
    {
        _mvsLogData.erase(_mvsLogData.begin());
    }
    //print log
    std::string sLogMsg = "";
    for(int i = 0; i < _mvsLogData.size(); i++)
    {
        sLogMsg += "\n";
        sLogMsg += _mvsLogData[i];
    }
//    QString qsTmpMsg = QString::fromLocal8Bit(sLogMsg);
    QString qsTmpMsg = QString::fromStdString(sLogMsg);
    ui->labelLog->setText(qsTmpMsg);
}

void MainWindow::on_pushButtonStart_clicked()
{
    if(_mbOnGoingFlag)
    {
        addLog("[WARN]인원 분배가 진행중입니다. 나중에 다시 시도해 주세요.");
        return;
    }
    // prepare process
    if(_mnPersonNum < 1)
    {
        addLog("[WARN]인원을 추가하세요.");
        return;
    }

    bool bMode0 = ui->ModeButton0->isChecked();
    bool bMode1 = ui->ModeButton1->isChecked();
    int nMode = -1;

    if(bMode0)nMode = 0;
    else if(bMode1) nMode = 1;

    if(nMode < 0){
        addLog("[WARN]모드를 선택하세요.");
        return;
    }

    int nGroupNum =ui->spinBoxGroupNum->value();
    if(nGroupNum < 1)
    {
        addLog("[WARN]그룹 수를 정하세요.");
        return;
    }

    bool bTermsOfService = ui->checkBoxToS->isChecked();
    if(!bTermsOfService)
    {
        addLog("[WARN]이용약관에 동의하세요.");
        return;
    }

    if(_mnPersonNum <= nGroupNum)
    {
        addLog("[WARN]인원수가 그룹의 수보다 커야 합니다.");
        return;
    }

    for(int i = 0; i < _mnPersonNum; i++)
    {
        QTableWidgetItem* qItemGender = ui->tableWidgetList->item(i,1);
        std::string sTmpGender = qItemGender->text().toStdString();
        if(sTmpGender != "남" && sTmpGender != "여"){
            addLog("[WARN]성별이 올바르지 않은 인원이 있습니다.");
            return;
        }
    }

    // make database
    _mMainProcessor->setFlag(0);
    _mMainProcessor->clearData();
    for(int i = 0; i < _mnPersonNum; i++)
    {
        QTableWidgetItem* qItemName = ui->tableWidgetList->item(i,0);
        QTableWidgetItem* qItemGender = ui->tableWidgetList->item(i,1);
        std::string sTmpName = qItemName->text().toLocal8Bit().data();
        std::string sTmpGender = qItemGender->text().toStdString();
        bool bTmpGender = true;
        if(sTmpGender == "남")bTmpGender = true;
        else bTmpGender = false;
        Person* pTmpPerson = new Person(sTmpName,bTmpGender);
        _mMainProcessor->inputData(pTmpPerson);
    }
    _mMainProcessor->setMode(nMode);
    _mnGroupNum = nGroupNum;
    _mMainProcessor->setGroupNum(_mnGroupNum);
    // Run!
    _mbOnGoingFlag = true;
    ui->progressBar->setValue(0);
    _mMainProcessor->setFlag(1);
    addLog("[RUN]인원 분배 하는중...");
}
void MainWindow::progressSignal(int n)
{
    ui->progressBar->setValue(n);
}
void MainWindow::on_progressBar_valueChanged(const int &value)
{
    if(value == 100)
    {
        _mMainProcessor->setFlag(0);
        addLog("[RUN]인원 분배 완료!");

        // reset result table
        for(;ui->tableWidgetResult->columnCount() != 0;)ui->tableWidgetResult->removeColumn(0);
        for(;ui->tableWidgetResult->rowCount() != 0;)ui->tableWidgetResult->removeRow(0);
        // get result
        std::vector<Person*> vpResult = _mMainProcessor->getDataBase();
        ui->tableWidgetResult->setColumnCount(_mnGroupNum);

        // write result to table
        std::vector<int> vnCountItem;
        vnCountItem.reserve(_mnGroupNum);
        for(int i = 0; i < _mnGroupNum; i++)
        {
            vnCountItem.push_back(0);
        }
        int nMaxRow = 0;
        ui->tableWidgetResult->insertRow(nMaxRow);
        for(int i = 0; i < vpResult.size(); i++)
        {
            QTableWidgetItem* qPerson = new QTableWidgetItem();
            std::string sTmpName = vpResult[i]->getName();
//            if(vpResult[i]->getGender())
//            {
//                sTmpName += "(M)";
//            }
//            else
//            {
//                sTmpName += "(F)";
//            }
            QString qName = QString::fromLocal8Bit(sTmpName);
            qPerson->setText(qName);

            int nTmpGroup = vpResult[i]->getGroup();
            if(vnCountItem[nTmpGroup] > nMaxRow)
            {
                nMaxRow = vnCountItem[nTmpGroup];
                ui->tableWidgetResult->insertRow(nMaxRow);
            }
            ui->tableWidgetResult->setItem(vnCountItem[nTmpGroup]++,nTmpGroup,qPerson);
        }

        _mbOnGoingFlag = false;
    }
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@ SAVE @@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */

void MainWindow::on_pushButtonSaveResult_clicked()
{
    if(_mbOnGoingFlag)
    {
        addLog("[WARN]인원 분배가 진행중입니다. 나중에 다시 시도해 주세요.");
        return;
    }
    QString qsText;
    for(int i = 0; i < ui->tableWidgetResult->columnCount(); i++)
    {
        qsText += QString::fromStdString(std::to_string(i+1) + "팀: ");
        for(int j = 0; j < ui->tableWidgetResult->rowCount(); j++)
        {
            if(ui->tableWidgetResult->item(j,i) == nullptr)continue;
            qsText += ui->tableWidgetResult->item(j,i)->text() + QString::fromStdString(" ");
        }
        qsText += QString::fromStdString("\n");
    }
    QString qsSaveFileName = ui->sSaveFileName->text();
    QFile file(qsSaveFileName+QString::fromStdString(".txt"));
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        addLog("[WARN]저장 실패.");
        return;
    }
    else
    {
        QTextStream out(&file);
        out << qsText;
        file.close();
    }

    addLog("[SAVE]저장완료.");
}

