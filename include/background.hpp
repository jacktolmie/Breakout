#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <iostream>
#include "constants.hpp"
#include "entity.hpp"

class Background: public Entity {
    static sf::Texture texture;
    
public:
    Background();
    Background(float x, float y);
    
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif //BACKGROUND_HPP
