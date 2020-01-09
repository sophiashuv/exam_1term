//
// Created by Sophia Shuvar on 09.01.20.
//

#ifndef EXAM_1TERM_ESTATE_H
#define EXAM_1TERM_ESTATE_H

#endif //EXAM_1TERM_ESTATE_H

#include <iostream>
#include <fstream>
#include <string>
#pragma once

using namespace std;

class Estate{
protected:
    string adress;
    int area;
    double price;
public:
    Estate(){
        adress = "";
        area = 10000000;
        price = 10000000;
    }

    Estate(string _adress, int _area, double _price){
        adress = _adress;
        area = _area ;
        price = _price;
    }

    Estate(const Estate & a){
        adress = a.adress;
        area = a.area ;
        price = a.price;
    }

    ~Estate() {};

    friend istream& operator>>(istream& in, Estate& a) {
        in >> a.adress;
        in >> a.area;
        in >> a.price;
        return in;
    }

    friend ostream& operator<<(ostream& out, Estate& a) {
        out << "Address: " << a.adress << "  Square: " << a.area << " sq. meters" << "  Price per sq. meter: " << a.price;
        return out;
    }

    virtual long long getPrice() {
        return area * price;
    }

    string getAdress() {
        return adress;
    }

    virtual bool is_smaller(Estate b){
        return getPrice() < b.getPrice();
    }

    virtual void print(){
        cout << "Adress: " << adress << "  Square: " << area << " sq. meters" << "  Price per sq. meter: " << price;
    }

    virtual int getZone() {
        return 0;
    }
};
