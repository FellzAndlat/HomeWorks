#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);
    connect(udpWorker, &UDPworker::sig_sendMessageToGUI, this, &MainWindow::DisplayReceivedMessage);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;

        udpWorker->SendDatagram(dataToSend);
        timer->start(TIMER_DELAY);

    });

    connect(ui->pb_sendMessage, &QPushButton::clicked, this, &MainWindow::on_pb_sendMessage_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_sendMessage_clicked() {
    QString message = ui->le_message->text();  // Получаем текст из виджета
    QByteArray data = message.toUtf8();  // Преобразуем в байты

    udpWorker->SendDatagram(data);  // Отправляем сообщение
    ui->le_message->clear();  // Очищаем поле ввода
}

void MainWindow::DisplayReceivedMessage(QString message, QString sender, int size) {
    ui->te_result->append(QString("Принято сообщение от %1, размер сообщения (байт): %2\nСообщение: %3")
                              .arg(sender).arg(size).arg(message));
}

void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}

void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + data.toString() + ". "
                "Принято пакетов " + QString::number(counterPck));


}


void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}

