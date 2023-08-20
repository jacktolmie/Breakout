#ifndef BALL_HPP
#define BALL_HPP

#include "moving_entity.hpp"

class Ball: public Moving_Entity
{
  static sf::Texture texture;

  const float height{constants::window_height/3.5f};
  const float width {constants::centre_width};
  
  // Adjust the ball speed according to level.
  float ball_speed();
  
public:
  
    Ball();
    virtual ~Ball() = default;
    
    void update() override;
    void draw(sf::RenderWindow&) override;
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    
    // Reset the ball after missing the ball.
    void ball_reset(int) noexcept;
    
    // Centre the ball when level completed.
    void centre_ball();
    
    // Return sprite reference for ball interaction.
    sf::Sprite& getSprite();
};
#endif //BALL_HPP
