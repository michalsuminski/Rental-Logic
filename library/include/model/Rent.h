//
// Created by student on 07.06.2020.
//

#ifndef CARRENTALPROJECT_RENT_H
#define CARRENTALPROJECT_RENT_H

#include "typedefs.h"
#include <boost/date_time.hpp>
#include "Client.h"
#include "Item.h"


namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Rent{
private:
    unsigned int id;
    int rentCost;  // tu bedzie musial byc double bo bedziemy mnozyc przez ulamek
    ClientPtr client;
    ItemPtr item;
    pt::ptime beginTime;
    pt::ptime EndTime = pt::not_a_date_time;
public:
    //konstruktor
    Rent(unsigned int id, ClientPtr client, ItemPtr item, pt::ptime beginTime=pt::not_a_date_time);
    //destruktor
    virtual ~Rent();

    //funkcje
    const int getRentDays() const;
    const unsigned int getRentCost() const;
    std::string getRentInfo();
    //const pt::ptime startRent() const;
    //void endRent(pt::ptime endDate);
    bool endRent(pt::ptime endTime=pt::not_a_date_time);
    //gettery
    const int getId() const;

    ClientPtr getClient() ;
    ItemPtr getItem() const;

    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
};

#endif //CARRENTALPROJECT_RENT_H
