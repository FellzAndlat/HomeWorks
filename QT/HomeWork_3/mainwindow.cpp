#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newWindow = new Dialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete newWindow;
}

void MainWindow::on_pb_connect_clicked()
{
    newWindow->show();
}


void MainWindow::on_pb_cancel_clicked()
{
    close();
}

