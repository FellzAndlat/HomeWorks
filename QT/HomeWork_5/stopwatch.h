#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT
public:
    explicit Stopwatch (QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void lap();
    QString getTimeString() const;
    bool isRunning() const;
signals:
    void timeUpdated(const QString &time);
    void lapRecorded(const QString &lapTime);
private slots:
    void updateTime();
private:
    QTimer *timer;
    int elapsedTime;
    int lastLapTime;
    int lapCount;
    bool running;

};

#endif // STOPWATCH_H
