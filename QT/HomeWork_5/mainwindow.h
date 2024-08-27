#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startStop_clicked();
    void on_clear_clicked();
    void on_lap_clicked();
    void updateDisplayTime(const QString &time);
    void addLapRecord(const QString &lapTime);
private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch_;
};
#endif // MAINWINDOW_H
