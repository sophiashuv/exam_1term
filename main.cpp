#include <iostream>
#include <fstream>
#include <string>

#include "Estate.h"
#include "Flat.h"
#include "Zoneestate.h"

using namespace std;

template <typename T>
T * read_file(string file_name, int n){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        T *c = new T[n];
        for (int i = 0; i < n; i++) myfile >> c[i];
        return c;
    }else cout << "Unable to open file";
}

template <typename T>
T find_min(T * a, int n){
    T min("", 1000000, 10000000);
    for (int i = 0; i < n; i ++ ) if (a[i].is_smaller(min)) min = a[i];
    return min;
}

int * allZones(Zoneestate * a, int n){
    int * zons = new int[n];
    bool k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) if(a[i].getZone() == a[j].getZone()) k = 1;
        if (k!=1) zons[i] = a[i].getZone();
        else zons[i] = 0;
        k = 0;
    }return zons;
}

long long sum_in_zone(Zoneestate * a, int n, int con_zone){
    long long  sum = 0;
    for(int i = 0; i < n; i++) if(a[i].getZone() == con_zone) sum += a[i].getPrice();
    return sum;
}

int* allZones2(Estate ** a, int n){
    int * zons = new int[n];
    bool k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i]->getZone() == a[j]->getZone()) k = 1;
            break;
        }
        if (!k) zons[i] = a[i]->getZone();
        else zons[i] = 0;
        k=0;
    }return zons;
}

void min_in_zone(Estate ** a, int n, int con_zone){
    Estate min;
    for(int i = 0; i < n; i++) if (a[i]->getZone() == con_zone) if(a[i]->getPrice() < min.getPrice()) min = *a[i];
    cout << "The cheapest estate in zone : " << con_zone << " is " << min << ".\n";
}

int main() {
    int n =7;
    cout << "\n\n--------------------Task 1-------------------- \n\n";
    Estate * first_arr = read_file<Estate>("/Users/sophiyca/ClionProjects/exam_1term/estate", n);
    for(int i = 0; i < n; i++) cout << first_arr[i] << "\n";
    cout << "---------------------------------------------- \n";
    cout << "Min price is: \n";
    Estate min = find_min<Estate>(first_arr, n);
    cout << min;

    cout << "\n\n--------------------Task 2-------------------- \n\n";
    Zoneestate * second_arr = read_file<Zoneestate>("/Users/sophiyca/ClionProjects/exam_1term/zoneestate", n);
    for(int i = 0; i < n; i++) cout << second_arr[i] << " Price is: " << second_arr[i].getPrice() << "\n";
    cout << "---------------------------------------------- \n";
    int * zons = allZones(second_arr, n);
    for (int i = 0; i < n; i ++) if (zons[i]!=0) cout << "For zone " << zons[i] << " sum price is: "
                                                      << sum_in_zone(second_arr, n, zons[i])<< ".\n";

    cout << "\n\n--------------------Task 3-------------------- \n\n";
    Flat * third_arr = read_file<Flat>("/Users/sophiyca/ClionProjects/exam_1term/flat", n);
    Estate ** all =  new Estate * [3*n];
    for (int i = 0; i < n; i ++){
        all[i] = new Estate;
        all[i] = &first_arr[i];
        all[i+n] = new Zoneestate;
        all[i+n] = &second_arr[i];
        all[i+2*n] = new Flat;
        all[i+2*n] = &third_arr[i];
    }
    for(int i = 0; i < 3*n; i++)  {
        all[i]->print();
        cout << " Price is: " << all[i]->getPrice() << "\n";
    }
    cout << "---------------------------------------------- \n";
    int * zons2 = allZones(second_arr, n);
    for(int i = 0; i < n; i++){
        if(zons2[i]!=0){
            min_in_zone(all, 3*n, zons2[i]);
        }
    }
    return 0;
}
