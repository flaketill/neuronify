#ifndef PASSIVECURRENT_H
#define PASSIVECURRENT_H

#include "current.h"

class PassiveCurrent : public Current
{
    Q_OBJECT
    Q_PROPERTY(double resistance READ resistance WRITE setResistance NOTIFY resistanceChanged)

public:
    explicit PassiveCurrent(QQuickItem *parent = 0);
    ~PassiveCurrent();

    double resistance() const;

signals:
    void resistanceChanged(double arg);

public slots:
    void setResistance(double arg);

protected:
    virtual void stepEvent(double dt, bool parentEnabled) override;
    virtual void resetPropertiesEvent() override;

private:
    double m_resistance = 0.0;
};

#endif // PASSIVECURRENT_H