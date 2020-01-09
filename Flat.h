//
// Created by Sophia Shuvar on 09.01.20.
//

#ifndef EXAM_1TERM_FLAT_H
#define EXAM_1TERM_FLAT_H

#endif //EXAM_1TERM_FLAT_H
#include <iostream>
#include <fstream>
#include <string>
#pragma once

#include "Zoneestate.h"

class Flat :
        public Zoneestate
{
    int bedroom;
    int parking;
    static const int bk = 3;
    static const int pk = 2;
public:
    Flat() :Zoneestate() {
        bedroom = 0;
        parking = 0;
    }

    Flat(string _adress, int _area, double _price, int _zone, int _bedroom, int _parking) :Zoneestate(_adress, _area, _price, _zone) {
        bedroom = _bedroom;
        parking = _parking;
    }

    Flat(const Flat& a) :Zoneestate(a) {
        bedroom = a.bedroom;
        parking = a.parking;
    }

    ~Flat() {};

    friend istream& operator>>(istream& in, Flat& a) {
        in >> (Zoneestate&)a;
        in >> a.bedroom;
        in >> a.parking;
        return in;
    }

    friend ostream& operator<<(ostream& out, Flat& a) {
        out << (Zoneestate&)a;
        out << " bedroom: " << a.bedroom << " parking: " << a.parking;
        return out;
    }

    long long getPrice() override {
        return Zoneestate::getPrice() * bedroom * bk * parking * pk;
    }

    int getZone() override{
        return zone;
    }

    void print() override {
        Zoneestate::print();
        cout << " bedroom: " << bedroom << " parking: " << parking;
    }
};