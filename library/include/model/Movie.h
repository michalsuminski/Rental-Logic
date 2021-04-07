//
// Created by student on 16.06.2020.
//

#ifndef CARRENTALPROJECT_MOVIE_H
#define CARRENTALPROJECT_MOVIE_H

#include "Item.h"
#include <string>

class Movie : public Item{
private:
    std::string director;
    bool Blue_Ray;
public:
    Movie(const std::string &title, int basePrice, const std::string &director, bool blueRay);

    virtual ~Movie();

    bool isBlue_Ray();

    const std::string &getDirector() const;

    double getActualRentalPrice() override;
};


#endif //CARRENTALPROJECT_MOVIE_H
