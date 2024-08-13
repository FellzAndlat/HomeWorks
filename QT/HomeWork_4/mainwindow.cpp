#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->groupBox->setTitle("Кнопочки");
    ui->radioButton->setText("Кнопочка");
    ui->radioButton_2->setText("Вторая кнопочка");

    for(int i = 0; i < 10; ++i) {
        ui->comboBox->addItem("Пункт " + QString::number(i));
    }

    ui->pushButton->setText("Добавить 10%");
    ui->pushButton->setCheckable(true);

    ui->progressBar->setRange(0, 10);
    ui->progressBar->setValue(0);

    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        int currentValue = ui->progressBar->value();
        currentValue += 1;
        if (currentValue > 10) {
            currentValue = 0;
        }
        ui->progressBar->setValue(currentValue);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
