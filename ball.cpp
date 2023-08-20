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
    Ball::ball_reset(g_level);
}

float Ball::ball_speed()
{
    
    switch(g_level)
    {
        case 1 ... 6:
        {
            return constants::ball_speed;
        }
        case 7 ... 12:
        {
            return constants::ball_speed + 1.0f;
        }
        case 13 ... 18:
        {
            return constants::ball_speed + 2.0f;
        }
        default:
        {
            return constants::ball_speed + 4.0f;
        }
    }
}


void Ball::update()
{
    sprite.move(velocity);
    
    if(x() < 0 || x() > constants::window_width)
    {
        velocity.x = -velocity.x;
    }
    
    if(y() < constants::textbox_height)
    {
        velocity.y = -velocity.y;
    }
    
    if(y() > constants::window_height)
    {
        // Paddle is no longer large.
        is_increased = false;
        is_hit = false;
        destroy();
    }
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Ball::move_up() noexcept
{
    velocity.y = -ball_speed();
}

void Ball::move_down() noexcept
{
    velocity.y = ball_speed();
}

void Ball::move_left() noexcept
{
    velocity.x = -ball_speed();
}

void Ball::move_right() noexcept
{
    velocity.x = ball_speed();
}

void Ball::ball_reset(int level) noexcept
{
    is_increased = false;
    
    Ball::centre_ball();
    
    velocity = sf::Vector2f(ball_speed(), ball_speed());

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

sf::Sprite & Ball::getSprite()
{
    return sprite;
}

void Ball::centre_ball()
{
    sprite.setPosition(constants::ball_start_width, constants::ball_start_height);
}

