#include "paddle.hpp"

sf::Texture Paddle::texture;

Paddle::Paddle(): Paddle{constants::window_width/2.0f, constants::window_height - constants::paddle_height}{}

Paddle::Paddle(float x, float y): Moving_Entity()
{
    if(!texture.loadFromFile("paddle.png"))
    {
        Entity::error("paddle.png");
    }
    
    sprite.setTexture(texture);
    
    sprite.setPosition(x, y);
    
    velocity = {constants::paddle_speed, 0.0f};
    
    sprite.setOrigin(get_centre());
}

void Paddle::update()
{
    process_player_input();
    
    sprite.move(velocity);
}

void Paddle::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Paddle::process_player_input() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x() >= (0 + (constants::paddle_width - 10)))
    {
        velocity.x = -constants::paddle_speed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x() <= (constants::window_width - (constants::paddle_width - 10)))
    {
        velocity.x = constants::paddle_speed;
    }
    else
    {
        velocity.x = 0;
    }
}

void Paddle::paddle_reset() noexcept
{
    sprite.setPosition(constants::window_width/2.0f, constants::window_height - constants::paddle_height);
}

void Paddle::move_up() noexcept{}

void Paddle::move_down() noexcept{}

void Paddle::move_left() noexcept
{
    velocity.x = -constants::paddle_speed;
}
void Paddle::move_right() noexcept
{
    velocity.x = constants::paddle_speed;
}
