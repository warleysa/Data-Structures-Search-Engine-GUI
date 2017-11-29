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
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
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
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->label_starting->setHidden(true);
    ui->label_start->setHidden(false);
    ui->startButton->setDisabled(true);

}

void MainWindow::start() {
    int start_s=clock();
    p.readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/Q15.csv");
    p.readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/T15.csv");
    p.readFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/Q16.csv");
    p.readTagFile("/home/coder/Final-Project/CSE2341-17F-warleysa-mwoolz-rezonate11/data/T16.csv");
    int stop_s=clock();
    QString time = QString::number((stop_s-start_s)/double(CLOCKS_PER_SEC));
    on_label_time_linkActivated(time);
}

void MainWindow::on_pushButton_3_clicked() {}


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
    ui->tabwidget1->setCurrentWidget(ui->tab_3);
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
    ui->tabwidget1->setCurrentWidget(ui->tab_3);
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
    rIndex = p.findFile(index);
    QString info = QString::fromStdString(std::to_string(p.readId(rIndex)));
    info.append("\n Title: \n");
    info.append(QString::fromStdString(p.readTitle(rIndex)));
    info.append("\n Body: \n");
    info.append(QString::fromStdString(p.readBody(rIndex)));
    info.append("\n Code: \n");
    info.append(QString::fromStdString(p.readCode(rIndex)));
    ui->textBrowser->setText(info);
    QString docCount = QString::fromStdString(std::to_string(p.TotalQuestions()));
    ui->label_12->setText(docCount);

}

void MainWindow::on_startButton_clicked()
{

}

void MainWindow::on_startButton_clicked(bool checked)
{
}
