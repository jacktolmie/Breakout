#include "ball.hpp"
#include <ctime>

sf::Texture Ball::texture;

Ball::Ball(): Moving_Entity()
{
    if(!texture.loadFromFile("ball.png")){
        Entity::error("ball.png");
    }
    
    sprite.setTexture(texture);
 
    velocity = {constants::ball_speed, constants::ball_speed};
    
    sprite.setOrigin(get_centre());
    
    // Call reset() to move ball random downward angle.
    Ball::ball_reset();
}

void Ball::update()
{
    sprite.move(velocity);
    
    if(x() < 0 || x() > constants::window_width)
    {
        velocity.x = -velocity.x;
    }

    if(y() < 0)
    {
        velocity.y = -velocity.y;
    }
    if(y() > constants::window_height)
    {
        destroy();
    }
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Ball::move_up() noexcept
{
    velocity.y = -constants::ball_speed;
}

void Ball::move_down() noexcept
{
    velocity.y = constants::ball_speed;
}

void Ball::move_left() noexcept
{
    velocity.x = -constants::ball_speed;
}

void Ball::move_right() noexcept
{
    velocity.x = constants::ball_speed;
}

void Ball::ball_reset() noexcept
{
    sprite.setPosition(constants::ball_start_width, constants::ball_start_height);

    /* A timer to check for even/odd number for direction for the ball to travel
     * when the game starts/resets. Even moves it down/right, odd down/left. */
    time_t timer;
    time(&timer);
    if (timer % 2 == 0)
    {
        Ball::move_down();
        Ball::move_right();
    }
    else
    {   Ball::move_down();
        Ball::move_left();
    }
}
