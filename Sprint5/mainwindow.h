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

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Parser p;
};

#endif // MAINWINDOW_H
