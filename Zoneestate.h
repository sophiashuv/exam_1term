//
// Created by Sophia Shuvar on 09.01.20.
//

#ifndef EXAM_1TERM_ZONEESTATE_H
#define EXAM_1TERM_ZONEESTATE_H

#endif //EXAM_1TERM_ZONEESTATE_H

#include <iostream>
#include <fstream>
#include <string>
#pragma once

#include "Estate.h"

class Zoneestate :
        public Estate
{
protected:
    int zone;
    static const int k = 5;
public:
    Zoneestate() :Estate() {
        zone = 0;
    }

    Zoneestate(string _adress, int _area, double _price, int _zone) :Estate(_adress, _area, _price) {
        zone = _zone;
    }

    Zoneestate(const Zoneestate& a) :Estate(a) {
        zone = a.zone;
    }

    ~Zoneestate() {};

    friend istream& operator>>(istream& in, Zoneestate& a) {
        in >> (Estate&)a;
        in >> a.zone;
        return in;
    }

    friend ostream& operator<<(ostream& out, Zoneestate& a) {
        out << (Estate&)a;
        out << "  Zone: "<< a.zone;
        return out;
    }

    long long getPrice() override {
        if (zone == 1)
            return Estate::getPrice();
        else
            return Estate::getPrice() * (zone - 1) * k;
    }

    virtual int getZone() override{
        return zone;
    }

    virtual void print() override{
        Estate::print();
        cout << "  Zone: "<< zone;
    }
};