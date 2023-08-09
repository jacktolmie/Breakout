#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "moving_entity.hpp"

class Paddle: public Moving_Entity
{
private:
    
    static sf::Texture paddle;
    static sf::Texture power1;
    static sf::Texture power2;
    
    sf::Sprite increase_paddle;
    
    // Check for left/right keypress.
    void process_player_input();
    
    // Return the width of current paddle size if increased or not.
    float getWidth();
    
    // Set the scale of the sprite, if increase_paddle was active or not.
    void scaleTexture();
    
    // Vector for the increase_paddle sprite.
    sf::Vector2f increase_velocity;
    
public:
    Paddle();
    Paddle(float, float);
    virtual ~Paddle() = default;
    
    void update() override;
    void draw(sf::RenderWindow&) override;
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    
    // Sends reference to sprites to check boundaries.
     sf::Sprite& getIncreaseSprite();
     sf::Sprite& getPaddleSprite();
    
    // Drop the paddle_increase if the block is hit.
    void dropIncrease();
    
    // Increase the paddle size if increase_paddle sprite is hit.
    void paddle_increase();
    
    // Reset the paddle after the ball is missed.
    void paddle_reset() noexcept;
};
#endif //PADDLE_HPP
