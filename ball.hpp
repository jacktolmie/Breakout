#ifndef BALL_HPP
#define BALL_HPP

#include "moving_entity.hpp"

class Ball: public Moving_Entity
{
  static sf::Texture texture;

  const float height{constants::window_height/3.5f};
  const float width {constants::centre_width};
  
public:
  
    Ball();
    
    void update() override;
    void draw(sf::RenderWindow&) override;
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    void ball_reset() noexcept;
};
#endif //BALL_HPP
