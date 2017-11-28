#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QtCore>
#include <ctime>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()  //Start Button
{
    //Run parser to load in the data
    ui->label_dataStartType->setHidden(true);
    ui->label_starting->setHidden(false);
    int start_s=clock();

    int stop_s=clock();
    QString time = QString::number((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000);
    on_label_time_linkActivated(time);

    ui->label_starting->setHidden(true);
    ui->label_start->setHidden(false);
    ui->startButton->setDisabled(true);
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
