#ifndef DONATION_H
#define DONATION_H

#include <QString>

// 1. Base Class (Abstraction)
class Donation {
protected:
    QString donorName;
    float value;
public:
    Donation(QString name, float v) : donorName(name), value(v) {}
    virtual QString getType() = 0;
    QString getName() { return donorName; }
    float getValue() { return value; }
    virtual ~Donation() {}
};

// 2. Inheritance: Cash
class CashDonation : public Donation {
public:
    CashDonation(QString name, float v) : Donation(name, v) {}
    QString getType() override { return "Financial (Cash)"; }
};

// 3. Inheritance: Medical
class MedicalDonation : public Donation {
public:
    MedicalDonation(QString name, float v) : Donation(name, v) {}
    QString getType() override { return "Medical Supplies"; }
};

#endif