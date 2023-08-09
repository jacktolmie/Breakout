#include "paddle.hpp"

void Paddle::move_up() noexcept{}

void Paddle::move_down() noexcept
{
    // Drop the sprite depending on the level. 1-6 slowly, any higher, faster.
    increase_velocity = sf::Vector2f(0.0f, (g_level <=6 )? velocity.y = constants::increase_brick_slow : velocity.y = constants::increase_brick_fast);
    // increase_paddle.move(velocity);

    increase_paddle.move(increase_velocity);
    
    // Makes sure the paddle does not drop when the increase does.
    velocity.y = 0.0f;
}

void Paddle::move_left() noexcept
{
    // std::cout<<"Paddle x left: "<<velocity.x<<'\n';
    velocity.x = -constants::paddle_speed;
}
void Paddle::move_right() noexcept
{
    velocity.x = constants::paddle_speed;
    // std::cout<<"Paddle x right: "<<velocity.x<<'\n';
}

