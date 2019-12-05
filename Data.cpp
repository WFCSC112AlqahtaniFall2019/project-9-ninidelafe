//
// Created by Nini de la Fe on 11/18/19.
//

#include <string>
#include <iostream>
#include "Data.h"

using namespace std;

//creates a default constructor for the data
Data::Data() {
    country = "";
    points = 0;
    price = 0;
    province = "";
    variety = "";
    //country,points,price,province,variety
}
//creates an alternate constructor for when the data is inputted through parameters
Data::Data(string c, int poi, int pri, string pro, string v) {
    country = c;
    points = poi;
    price =pri;
    province = pro;
    variety = v;

}

//overloads the outstream operator
ostream& operator<<(ostream& os, const Data& pr) {
    os << pr.country << ": " << pr.points<< ", " << pr.price<< "," << pr.province << ", "<< pr.variety;
    return os;
}

//overloads < operator for points
bool operator < (const Data& hr, const Data &d){
    return hr.price <d.price;
    /*if (this->GDPperCapita > hr.GDPperCapita){
        return false;
    }
    else if (this->GDPperCapita < hr.GDPperCapita){
        return true;
    }
    else{
        return false;
    }*/
}
//overloads the <= operator
bool operator <= (const Data& hr, const Data &d) {
    return hr.price <= d.price;
}

//overloads >= operator for points
bool operator>=(const Data& hr, const Data &d) {
    return hr.price>=d.price;
}
//overloads > operator for points
bool operator>(const Data& hr, const Data &d) {
    return hr.price>d.price;
}
//overloads the = operator
Data& Data:: operator=(const Data &d){
    Data temp (d);

    swap(temp.country, country);
    swap(temp.points, points);
    swap(temp.price, price);
    swap(temp.province, province);
    swap(temp.variety, variety);

    return *this;
}
