//
// Created by student on 30.04.2020.
//

#include "model/Rent.h"
#include <string>


Rent::Rent(unsigned int id, ClientPtr client, ItemPtr item, pt::ptime beginTime) : id(id), client(client), item(item), beginTime(beginTime) {
    if(beginTime == pt::not_a_date_time) this->beginTime = pt::second_clock::local_time();
    item->setRented(true);
}

std::string Rent::getRentInfo() {
    return ""+std::to_string(id)+" "+client->getClientInfo()+" "+item->getItemInfo()+"\n";
}

//gettery
const int Rent::getId() const {
    return id;
}
ClientPtr Rent::getClient(){
    return client;
}
ItemPtr Rent::getItem() const {
    return item;
}
const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return EndTime;
}


Rent::~Rent() {
    item->setRented(false);
}

//void Rent::endRent(pt::ptime endDate) {
//    if(endTime == pt::not_a_date_time) {
//        if(endDate != pt::not_a_date_time) endTime = pt::second_clock::local_time();
//        else{
//            pt::time_period period(beginTime, endDate);
//            if(!period.is_null())endTime = endDate;
//            else{
//                endTime = beginTime;
//            }
//        }
//        rentCost = item->getBasePrice()*getRentDays();
//    }
//}

//const pt::ptime Rent::startRent() const {
//    return endTime;
//}

const int Rent::getRentDays() const {
//    if(endTime == pt::not_a_date_time) return 0;
//    pt::time_period time(beginTime, endTime);
//    //
//    if(time.length().hours() == 0 && time.length().minutes() == 0) return 0;
//    //
//    if(time.length().hours() /24 == 0 || time.length().minutes() != 0 || time.length().seconds() != 0) return (time.length().hours() /24) +1;
//    //
//    return time.length().hours() /24;

//jeżeli wypożyczenie nie zostało zakończone
    if(getEndTime()==pt::not_a_date_time) return 0;
    pt::time_period period = pt::time_period(getBeginTime(), getEndTime());
    //jeżeli wypożyczenie trwało < minutę
    if(period.length() < pt::minutes(1)) return 0;

    return period.length().hours()/24 + 1;
}

const unsigned int Rent::getRentCost() const {
    return rentCost;
}

bool Rent::endRent(pt::ptime endTime) {
    //jeżeli wypożyczenie zostało wcześniej zakończone
    if(getEndTime()!=pt::not_a_date_time) return false;
    //jeżeli argument to not_a_date_time to ustaw czas bieżacy
    if(endTime==pt::not_a_date_time) endTime=pt::second_clock::local_time();
    //jeżeli endTime jest przed BeginTime
    if(pt::time_period(getBeginTime(), endTime).length() < pt::seconds(0)) return false;
    //ustaw czas zakończenia
    EndTime=endTime;
    //ustal cenę
    rentCost = getRentDays() * getItem()->getBasePrice();
    return true;
}
