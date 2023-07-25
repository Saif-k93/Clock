#ifndef CURRENTTIME_H
#define CURRENTTIME_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QVariant>
#include <QDateTime>


class CurrentTime : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant timeS MEMBER m_timeS NOTIFY timeSChanged)
    Q_PROPERTY(QVariant timeH MEMBER m_timeH NOTIFY timeHChanged)

public:
    explicit CurrentTime(QObject *parent = nullptr);

signals:

    void timeSChanged();
    void timeHChanged();

private:
    void timeoutS();
    void timeoutH();

private:
    QVariant m_timeS;
    QVariant m_timeH;
    QTimer* m_timerS;
    QTimer* m_timerH;
};

#endif // CURRENTTIME_H
