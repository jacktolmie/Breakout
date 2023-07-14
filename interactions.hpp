#ifndef INTERACTIONS_HPP
#define INTERACTIONS_HPP

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"

// Determine whether two entities overlap.
bool is_interacting(const Entity&, const Entity&);

// Resolve potential collision between ball and paddle.
void handle_collision(Ball& b, const Paddle& p);

// Resolve potential collision between ball and brick.
void handle_collision(Ball&, Brick&);

#endif // INTERACTIONS_HPP
