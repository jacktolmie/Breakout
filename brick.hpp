#ifndef BRICK_HPP
#define BRICK_HPP

#include "entity_manager.hpp"

class Brick: public Entity
{
    using vec_brick = std::vector<Brick>;

    static sf::Texture green_brick;
    static sf::Texture blue_brick;
    static sf::Texture red_brick;
    
    int         strength{1};
    bool        is_green{true};
    
public:
    Brick(float, float);
    Brick(Entity_Manager&);
    
    void update() override;
    void draw(sf::RenderWindow&) override;
    
    void bricks_reset(Entity_Manager&);
    
    // Functions for checking brick strength.
    void weaken() noexcept;
    bool is_too_weak() const noexcept;
    
    int get_random(int, int);
    
};
#endif // BRICK_HPP
