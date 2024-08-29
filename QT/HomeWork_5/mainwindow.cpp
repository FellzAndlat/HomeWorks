#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stopwatch_(new Stopwatch(this))
{
    ui->setupUi(this);

    connect(stopwatch_, &Stopwatch::timeUpdated, this, &MainWindow::updateDisplayTime);
    connect(stopwatch_, &Stopwatch::lapRecorded, this, &MainWindow::addLapRecord);

    ui->time->setText("00:00:0");
    ui->startStop->setText("Старт");
    ui->clear->setText("Очистить");
    ui->lap->setText("Круг");
    ui->lap->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStop_clicked() {
    if (stopwatch_->isRunning()) {
        stopwatch_->stop();
        ui->startStop->setText("старт");
        ui->lap->setEnabled(false);
    } else {
        stopwatch_->start();
        ui->startStop->setText("стоп");
        ui->lap->setEnabled(true);
    }
}

void MainWindow::on_clear_clicked() {
    stopwatch_->reset();
    ui->startStop->setText("старт");
}

void MainWindow::on_lap_clicked() {
    stopwatch_->lap();
}

void MainWindow::updateDisplayTime(const QString &time) {
    ui->time->setText(time);
}

void MainWindow::addLapRecord(const QString &lapTime) {
    ui->textBrowser->append(lapTime);
}
