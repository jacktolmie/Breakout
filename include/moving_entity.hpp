#ifndef MOVING_ENTITY_HPP
#define MOVING_ENTITY_HPP

#include "entity.hpp"

class Moving_Entity : public Entity
{
public:
    
    virtual void move_up() noexcept = 0;
    virtual void move_down() noexcept = 0;
    virtual void move_left() noexcept = 0;
    virtual void move_right() noexcept = 0;
    
protected:
    
    sf::Vector2f velocity;
    
};
#endif //MOVING_ENTITY_HPP
