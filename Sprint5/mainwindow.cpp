#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <thread>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QtCore>
#include <ctime>
#include <string>
#include <chrono>
#include <word.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_4->setHidden(true);
    ui->label_5->setHidden(true);
    ui->label_start->setHidden(true);
    ui->label_time->setHidden(true);
    ui->label_starting->setHidden(true);
    ui->tab_1->activateWindow();
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_released()  //Start Button
{
    //Run parser to load in the data
    ui->label_dataStartType->setHidden(true);
    ui->label_starting->setHidden(false);
    QMessageBox::information(
        this,
        tr("Search Engine"),
        tr("The Search Engine is starting...") );
    start();
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->label_starting->setHidden(true);
    ui->label_start->setHidden(false);
    ui->startButton->setDisabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);

}

void MainWindow::start() {
    int start_s=clock();

    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q08.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T08.csv");

    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q09.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T09.csv");
    /*
    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q10.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T10.csv");
    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q11.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T11.csv");
    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q12.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T12.csv");

    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q13.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T13.csv");
    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q14.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T14.csv");
    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q16.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T16.csv");

    p->readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/Q15.csv");
    p->readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/Sprint5/data/T15.csv");
    */
    int stop_s=clock();
    QString time = QString::number((stop_s-start_s)/double(CLOCKS_PER_SEC));
    on_label_time_linkActivated(time);
}

void MainWindow::on_pushButton_3_clicked() {
    p->clear();
}


void MainWindow::on_buttonAddQuestion_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open CSV File"),
                "C://",
                "CSV File (*.csv)"
                );
    QMessageBox::information(this, tr("CSV Question File Name"), filename);
    on_label_5_linkActivated(filename);
}

void MainWindow::on_buttonAddTag_clicked()
{
    QString filenameTag = QFileDialog::getOpenFileName(
                this,
                tr("Open CSV File"),
                "C://",
                "CSV File (*.csv)"
                );
    QMessageBox::information(this, tr("CSV Tag File Name"), filenameTag);
    on_label_4_linkActivated(filenameTag);
}

void MainWindow::on_label_4_linkActivated(const QString &link)
{
    ui->label_4->setText(link);
    ui->label_4->setHidden(false);
}

void MainWindow::on_label_5_linkActivated(const QString &link)
{
    ui->label_5->setText(link);
    ui->label_5->setHidden(false);
}

void MainWindow::on_actionAccess_Top_50_Words_triggered()
{
}

void MainWindow::on_label_time_linkActivated(const QString &link)
{
    ui->label_time->setText(link);
    ui->label_time->setHidden(false);
}

void MainWindow::on_actionMaintenence_Mode_triggered()
{
    ui->tabwidget1->setCurrentWidget(ui->tab_2);
}

void MainWindow::on_pushButton_2_clicked()
{
}

void MainWindow::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
}

void MainWindow::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
}

void MainWindow::on_pushButton_clicked()
{
    //search and return document info as string
    QString qstr = ui->lineEdit_2->text();
    int index = qstr.toInt();
    int rIndex = 0;
    rIndex = p->findFile(index);
    docUpdater(rIndex);
    QString info = QString::fromStdString(std::to_string(index));
    info.append("\n Title: \n");
    info.append(QString::fromStdString(p->readTitle(rIndex)));
    info.append("\n Body: \n");
    info.append(QString::fromStdString(p->readBody(rIndex)));
    info.append("\n Code: \n");
    info.append(QString::fromStdString(p->readCode(rIndex)));
    ui->textBrowser->setText(info);
    QString docCount = QString::fromStdString(std::to_string(p->TotalQuestions()));
    ui->label_12->setText(docCount);
    QString wordCount = QString::fromStdString(std::to_string(p->vStrings->getTotalWords()));
    ui->label_14->setText(wordCount);
}

void MainWindow::on_startButton_clicked()
{

}

void MainWindow::on_startButton_clicked(bool checked)
{
}

void MainWindow::docUpdater(int docL) {
    QString info = QString::fromStdString(std::to_string(p->readId(docL)));
    ui->lineEdit_2->setText(info);
    currDoc = docL;
}

void MainWindow::on_pushButton_6_clicked()
{
    docUpdater(currDoc+1);
}

void MainWindow::on_pushButton_7_clicked()
{
    docUpdater(currDoc-1);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString tagQS = ui->label_4->text();
    QString quesQS = ui->label_5->text();
    QByteArray tagArray = tagQS.toLocal8Bit();
    char* bufferT = tagArray.data();
    QByteArray quesArray = quesQS.toLocal8Bit();
    char* bufferQ = quesArray.data();
    p->readTagFile(bufferT);
    p->readFile(bufferQ);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString query = ui->lineEdit->text();
    string qInput = query.toStdString();
    word result = p->vStrings->searchIndex(qInput);
    result.qSort();

    if (result.idList.size() > 0) {
        i1 = result.idList[0];
        f1 = result.freqList[0];
    } else {
        i1 = 0;
        f1 = 0;
    }
    if (result.idList.size() > 1) {
        i2 = result.idList[1];
        f2 = result.freqList[1];
    } else {
        i2 = 0;
        f2 = 0;
    }
    if (result.idList.size() > 2) {
        i3 = result.idList[2];
        f3 = result.freqList[2];
    } else {
        i3 = 0;
        f3 = 0;
    }

    if (result.idList.size() > 3) {
        i4 = result.idList[3];
        f4 = result.freqList[3];
    } else {
        i4 = 0;
        f4 = 0;
    }
    if (result.idList.size() > 4) {
        i5 = result.idList[4];
        f5 = result.freqList[4];
    } else {
        i5 = 0;
        f5 = 0;
    }

    cout << "f1: " << f1  << endl;
    rIndex1 = p->findFile(i1);
    QString text1;
    text1.append("Frequency: ");
    text1.append(QString::number(f1));
    text1.append("\n ID #: ");
    text1.append(QString::number(i1));
    text1.append("\n Title: ");
    text1.append(QString::fromStdString((p->readTitle(rIndex1)).substr(0, 90)));
    text1.append("\n Body: ");
    text1.append(QString::fromStdString((p->readBody(rIndex1)).substr(0, 115)));
    text1.append("...");
    ui->textBrowser_2->setText(text1);
    text1.clear();

    rIndex2 = p->findFile(i2);

    text1.append("Frequency: ");
    text1.append(QString::number(f2));
    text1.append("\n ID #: ");
    text1.append(QString::number(i2));
    text1.append("\n Title: ");
    text1.append(QString::fromStdString((p->readTitle(rIndex2)).substr(0, 90)));
    text1.append("\n Body: ");
    text1.append(QString::fromStdString((p->readBody(rIndex2)).substr(0, 115)));
    text1.append("...");
    ui->textBrowser_3->setText(text1);
    text1.clear();

    rIndex3 = p->findFile(i3);

    text1.append("Frequency: ");
    text1.append(QString::number(f3));
    text1.append("\n ID #: ");
    text1.append(QString::number(i3));
    text1.append("\n Title: ");
    text1.append(QString::fromStdString((p->readTitle(rIndex3)).substr(0, 90)));
    text1.append("\n Body: ");
    text1.append(QString::fromStdString((p->readBody(rIndex3)).substr(0, 115)));
    text1.append("...");
    ui->textBrowser_4->setText(text1);
    text1.clear();

    rIndex4 = p->findFile(i4);

    text1.append("Frequency: ");
    text1.append(QString::number(f4));
    text1.append("\n ID #: ");
    text1.append(QString::number(i4));
    text1.append("\n Title: ");
    text1.append(QString::fromStdString((p->readTitle(rIndex4)).substr(0, 90)));
    text1.append("\n Body: ");
    text1.append(QString::fromStdString((p->readBody(rIndex4)).substr(0, 115)));
    text1.append("...");
    ui->textBrowser_5->setText(text1);
    text1.clear();

    rIndex5 = p->findFile(i5);

    text1.append("Frequency: ");
    text1.append(QString::number(f5));
    text1.append("\n ID #: ");
    text1.append(QString::number(i5));
    text1.append("\n Title: ");
    text1.append(QString::fromStdString((p->readTitle(rIndex5)).substr(0, 90)));
    text1.append("\n Body: ");
    text1.append(QString::fromStdString((p->readBody(rIndex5)).substr(0, 115)));
    text1.append("...");
    ui->textBrowser_6->setText(text1);
    ui->tabwidget1->setCurrentWidget(ui->tab_4);
}

void MainWindow::on_pushButton_8_clicked()
{
    docUpdater(rIndex1);
    ui->tabwidget1->setCurrentWidget(ui->tab);
}

void MainWindow::on_pushButton_9_clicked()
{
    docUpdater(rIndex2);
    ui->tabwidget1->setCurrentWidget(ui->tab);
}

void MainWindow::on_pushButton_10_clicked()
{
    docUpdater(rIndex3);
    ui->tabwidget1->setCurrentWidget(ui->tab);
}

void MainWindow::on_pushButton_11_clicked()
{
    docUpdater(rIndex4);
    ui->tabwidget1->setCurrentWidget(ui->tab);
}

void MainWindow::on_pushButton_12_clicked()
{
    docUpdater(rIndex5);
    ui->tabwidget1->setCurrentWidget(ui->tab);
}
