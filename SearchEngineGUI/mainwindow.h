#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
