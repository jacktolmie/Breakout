#ifndef BRICK_HPP
#define BRICK_HPP

#include "entity_manager.hpp"
#include "textbox.hpp"
#include "paddle.hpp"

class Brick: public Entity
{
    using vec_brick = std::vector<Brick>;

    static sf::Texture green_brick;
    static sf::Texture blue_brick;
    static sf::Texture red_brick;
    
    int     strength{constants::regular_brick_strength};
    bool    is_green{true};
    
    //added by me from chatgpt
    int row; // Variable to store the row of the brick.
    
    // Reference to the Textbox.
    const Textbox& textbox; 
    

    
    
public:
    Brick(Entity_Manager&, int, const Textbox&);
    Brick(float x, float y, int row, const Textbox& textbox);
    virtual ~Brick() = default;
    
    void update() override;
    void draw(sf::RenderWindow&) override;
    
    void bricks_reset(Entity_Manager& manager, int rows, const Textbox& textbox);
    
    // Functions for checking brick strength.
    void weaken() noexcept;
    bool is_too_weak() const noexcept;
    
    int  get_random(int, int);
    
    bool will_drop{false};
    
    
};
#endif // BRICK_HPP
