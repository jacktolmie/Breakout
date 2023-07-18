#ifndef INTERACTIONS_HPP
#define INTERACTIONS_HPP

#include <cmath> // Added by me.

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"

// Determine whether two entities overlap.
bool is_interacting(const Entity&, const Entity&);

// Resolve potential collision between ball and paddle.
void handle_collision(Ball& b, const Paddle& p);

// Resolve potential collision between ball and brick.
void handle_collision(Ball&, Brick&);

//Added by me from chatgpt
float calculateSpinAngle(const sf::Vector2f& paddleVelocity);
void applySpinEffect(sf::Vector2f& ballVelocity, float spinAngle);
sf::Vector2f calculateRelativeVelocity(const sf::Vector2f&, const sf::Vector2f&);
void adjustBallVelocity(sf::Vector2f&, const sf::Vector2f&);

#endif // INTERACTIONS_HPP
