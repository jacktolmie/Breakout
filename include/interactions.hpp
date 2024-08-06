#ifndef INTERACTIONS_HPP
#define INTERACTIONS_HPP

// Added for applying spin on the ball
#include <cmath> 

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"
#include "textbox.hpp"

// Determine whether two entities overlap.
bool    is_interacting(const Entity&, const Entity&);

// Check for potential collision between ball and paddle.
void    handle_collision(Ball&,  Paddle&);

// Check for potential collision between ball and brick.
void    handle_collision(Ball&, Brick&, Paddle*);

// Check for potential collision between paddle and increase_paddle.
void    handle_collision(Paddle*);

//Added by me from chatgpt
float   calculateSpinAngle(const sf::Vector2f& paddleVelocity);
void    applySpinEffect(sf::Vector2f& ballVelocity, float spinAngle);
void    adjustBallVelocity(sf::Vector2f&, const sf::Vector2f&);
sf::Vector2f calculateRelativeVelocity(const sf::Vector2f&, const sf::Vector2f&);

#endif // INTERACTIONS_HPP
