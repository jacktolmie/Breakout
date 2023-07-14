#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "moving_entity.hpp"

class Paddle: public Moving_Entity
{
    static sf::Texture texture;
    
    void process_player_input();
    
public:
    Paddle();
    Paddle(float, float);
    
    void update() override;
    void draw(sf::RenderWindow&) override;
    void paddle_reset() noexcept;
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
};
#endif //PADDLE_HPP
