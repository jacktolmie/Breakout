#include "paddle.hpp"

sf::Texture Paddle::paddle;
sf::Texture Paddle::power1;
sf::Texture Paddle::power2;

Paddle::Paddle(): Paddle{constants::centre_width, constants::window_height - constants::paddle_height}{}

Paddle::Paddle(float x, float y): Moving_Entity()
{
    // Load paddle texture.
    if(!paddle.loadFromFile("paddle.png"))
    {
        Entity::error("paddle.png");
    }
    
    // Load paddle increase textures.
    if(!power1.loadFromFile("power.png"))
    {
        Entity::error("power.png");
    }
    if(!power2.loadFromFile("power2.png"))
    {
        Entity::error("power2.png");
    }    
    
    // Set texture for paddle and increase_paddle sprites.
    sprite.setTexture(paddle);
    Paddle::scaleTexture();  
    sprite.setPosition(x, y);
    sprite.setOrigin(get_centre());
    increase_paddle.setTexture(power1);
    increase_paddle.setPosition(constants::centre_height, constants::centre_width);

    // Set paddle speed.
    velocity = {constants::paddle_speed, 0.0f};
    
    Paddle::paddle_reset();
}

void Paddle::update()
{
    process_player_input();
    
    sprite.move(velocity);
    
    if(is_hit){
        increase_paddle.move(increase_velocity);
    }
    
}

void Paddle::draw(sf::RenderWindow& window)
{
    Paddle::scaleTexture();
    window.draw(sprite);
    
    if(is_hit){
        increase_paddle.setTexture((increase_paddle.getTexture() == &power1)? power2: power1);

        // Draw increase_paddle until it is hit.
        if(!is_increased)
            window.draw(increase_paddle);
    }
    
}

inline float Paddle::getWidth()
{
    // Set paddle width according to regular or increased paddle size.    
    return (is_increased)? constants::paddle_width + 10.0f  : constants::paddle_width - 10.0f;
}

void Paddle::process_player_input() 
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x() >= Paddle::getWidth())
    {
        // velocity.x = -constants::paddle_speed;
        Paddle::move_left();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x() <= (constants::window_width - Paddle::getWidth()))
    {
        // velocity.x = constants::paddle_speed;
        Paddle::move_right();
    }
    else
    {
        velocity.x = 0;
    }
}

void Paddle::paddle_reset() noexcept
{
    sprite.setPosition(constants::centre_width, constants::window_height - constants::paddle_height);
    sprite.setOrigin(get_centre()); //Needed?
    // Reset the is_increased/is_hit to allow for increase of paddle again after ball loss.
    if(ball_missed)
    {
        is_increased    = false;
        is_hit          = false;   
        Paddle::scaleTexture();
        
        // Set ball_missed back to false to allow increase_paddle drop.
        ball_missed = false;
    }
    if(is_increased)
    {
        is_hit = true;
        Paddle::scaleTexture();
    }
}

void Paddle::dropIncrease()
{
    // Delete when done? Need to figure out where to add this.
    is_hit = true; 
    
    Paddle::move_down();
}

void Paddle::paddle_increase()
{
    is_increased = true;
    Paddle::scaleTexture();
}

sf::Sprite& Paddle::getIncreaseSprite() 
{
    return increase_paddle;
}

sf::Sprite& Paddle::getPaddleSprite()
{
    return sprite;
}

inline void Paddle::scaleTexture()
{
    (is_increased)? sprite.setScale(1.5f, 1.0f): sprite.setScale(1.0f, 1.0f);
}
