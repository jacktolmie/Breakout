#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include <string_view>
#include <iostream>

class Entity{
protected:
    sf::Sprite sprite;
    
    bool destroyed{false};
    
public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    
    virtual ~Entity() {}
    
    sf::FloatRect get_bounding_box() const noexcept;
    
    sf::Vector2f get_centre() const noexcept;
    
    // Helper functions to get the position of the sprite.
    float x() const noexcept;
    float y() const noexcept;
    
    // Helper function to get the edges of the sprite.
    float left() const noexcept;
    float right() const noexcept;
    float top() const noexcept;
    float bottom() const noexcept;
    
    // Helper functions for the state of the entity.
    void destroy() noexcept;
    bool is_destroyed() const noexcept;
    
    void error(std::string_view);
};

#endif // ENTITY_HPP
