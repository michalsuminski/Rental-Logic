//
// Created by student on 16.06.2020.
//

#ifndef CARRENTALPROJECT_MUSIC_H
#define CARRENTALPROJECT_MUSIC_H


#include "Item.h"
#include <string>

class Music : public Item{
private:
    std::string artist;
    bool Original;
public:
    Music(const std::string &title, int basePrice, const std::string &artist, bool original);

    virtual ~Music();

    const std::string &getArtist() const;

    bool isOriginal();

    double getActualRentalPrice() override;
};


#endif //CARRENTALPROJECT_MUSIC_H
