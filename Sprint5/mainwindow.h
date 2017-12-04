#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <../Sprint5/parser.h>

#include <QMainWindow>
#include <QFileDialog>
#include <QCoreApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_pushButton_3_clicked();

    void on_buttonAddQuestion_clicked();

    void on_buttonAddTag_clicked();

    void on_label_4_linkActivated(const QString &link);

    void on_label_5_linkActivated(const QString &link);

    void on_actionAccess_Top_50_Words_triggered();

    void on_label_time_linkActivated(const QString &link);

    void on_actionMaintenence_Mode_triggered();

    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_clicked();

    void start();

    void on_startButton_released();

    void on_startButton_clicked(bool checked);

    void docUpdater(int doc);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Parser p;
    int currDoc;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int rIndex1;
    int rIndex2;
    int rIndex3;
    int rIndex4;
    int rIndex5;

};

#endif // MAINWINDOW_H
