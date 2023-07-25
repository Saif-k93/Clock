#include "currenttime.h"

CurrentTime::CurrentTime(QObject *parent)
    : QObject{parent}
{
    m_timerS = new QTimer(this);
    m_timerH = new QTimer(this);
    connect(m_timerS,&QTimer::timeout,this,&CurrentTime::timeoutS);
    connect(m_timerH,&QTimer::timeout,this,&CurrentTime::timeoutH);
    m_timerS->start(500);
    m_timerH->start(500);

    m_timeH = QDateTime::currentDateTime().toString("hh.mm");
    m_timeS = QDateTime::currentDateTime().toString("ss");

}

void CurrentTime::timeoutH()
{
    m_timeH = QDateTime::currentDateTime().toString("hh.mm");
    emit timeHChanged();
}

void CurrentTime::timeoutS()
{
    m_timeS = QDateTime::currentDateTime().toString("ss");
    emit timeSChanged();

}
