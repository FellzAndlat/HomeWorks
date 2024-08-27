#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedTime(0), lastLapTime(0), lapCount(0), running(false)  {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::updateTime);
    timer->setInterval(100);
}
void Stopwatch::start() {
    if (!running) {
        timer->start();
        running = true;
    }
}
void Stopwatch::stop() {
    if (running) {
        timer->stop();
        running = false;
    }
}
void Stopwatch::reset() {
    stop();
    elapsedTime = 0;
    lastLapTime = 0;
    lapCount = 0;
    emit timeUpdated(getTimeString());
}
void Stopwatch::lap() {
    if(running) {
        ++lapCount;
        int lapTime = elapsedTime;
        lastLapTime = elapsedTime;
        emit lapRecorded(QString("Круг %1, время: %2 сек").arg(lapCount).arg(lapTime / 1000.0, 0, 'f', 1));
    }
}
void Stopwatch::updateTime() {
    elapsedTime += 100;
    emit timeUpdated(getTimeString());
}

QString Stopwatch::getTimeString() const {
    int seconds = (elapsedTime / 1000) % 60;
    int minutes = (elapsedTime / 60000) % 60;
    int milliseconds = elapsedTime % 1000;
    return QString("%1:%2.%3").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')).arg(milliseconds / 100);
}

bool Stopwatch::isRunning() const {
    return running;
}

