//
// Created by student on 16.06.2020.
//

#include "../../include/model/Movie.h"

Movie::Movie(const std::string &title, int basePrice, const std::string &director, bool blueRay) : Item(title,
                                                                                                        basePrice),
                                                                                                   director(director),
                                                                                                   Blue_Ray(blueRay) {}

Movie::~Movie() {

}

const std::string &Movie::getDirector() const {
    return director;
}

bool Movie::isBlue_Ray() {
    return Blue_Ray;
}

double Movie::getActualRentalPrice() {
    if(isBlue_Ray()){
        return Item::getActualRentalPrice()*1.5;
    }
    return Item::getActualRentalPrice();
}
