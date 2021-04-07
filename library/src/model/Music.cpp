//
// Created by student on 16.06.2020.
//

#include "model/Music.h"

Music::Music(const std::string &title, int basePrice, const std::string &artist, bool original) : Item(title,
                                                                                                       basePrice),
                                                                                                  artist(artist),
                                                                                                  Original(original) {}

Music::~Music() {

}

const std::string &Music::getArtist() const {
    return artist;
}

bool Music::isOriginal() {
    return Original;
}

double Music::getActualRentalPrice() {
    if(isOriginal()){
        return Item::getActualRentalPrice()*1.7;
    }
    return Item::getActualRentalPrice();
}
