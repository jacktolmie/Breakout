#include "interactions.hpp"


void handle_collision(Ball& b,  Paddle& p)
{   
    auto ball{b.getSprite().getGlobalBounds()};
    auto increase{p.getIncreaseSprite().getGlobalBounds()};
    
    // If ball hits increase_paddle sprite, make it drop.
    if(ball.intersects(increase))
    {
        p.dropIncrease();
        p.update();
    }
    
    if(is_interacting(b, p))
    {
        b.update();
        
        sf::Vector2f paddle{sf::Vector2f(p.x(), p.y())};
        sf::Vector2f ball{sf::Vector2f(b.x(), b.y())};
        calculateRelativeVelocity(ball, paddle);
        adjustBallVelocity(ball, paddle);
        auto spin = calculateSpinAngle(sf::Vector2f(p.x(), p.y()));
        applySpinEffect(ball, spin);
        b.move_up();
    }
}

void handle_collision(Ball& ball, Brick& brick)
{
    if(is_interacting(brick, ball))
    {
        brick.weaken();
        
        if (brick.is_too_weak())
        {
            // The brick is destroyed.
            brick.destroy(); 
        }

        /* Make the new direction depend on where the collision occurs on the brick.
         * If the ball collides on the side of the brick, make the ball bounce to the  opposite side.
         * If the ball collides on the top or bottom, make the ball bounce the opposite way. 
         
         * First find the amount of overlap in each direction. The smaller the left overlap, the closer
         * the ball is to the left side of the brick etc. */
        float left_overlap  {ball.right() - brick.left()};
        float right_overlap {brick.right() - ball.left()};
        float top_overlap   {ball.bottom() - brick.top()};
        float bottom_overlap{brick.bottom() - ball.top()};
        
        // If the left overlap is smaller than the right, the ball hit the left side.
        bool from_left      {std::abs(left_overlap) < std::abs(right_overlap)};
        bool from_top       {std::abs(top_overlap) < std::abs(bottom_overlap)};
        
        // User the right or left overlap as appropriate.
        float min_x_overlap {from_left ? left_overlap : right_overlap};
        float min_y_overlap {from_top ? top_overlap : bottom_overlap};
        
        /* If the ball hit the left of right side of the brick, change its horizontal direction.
         * If the ball hit the top or bottom of the brick, change its vertical direction. */
        if(std::abs(min_x_overlap) < std::abs(min_y_overlap))
        {
            (from_left) ? ball.move_left() : ball.move_right();
        }
        else
        {
            (from_top) ? ball.move_up() : ball.move_down();
        }
    }
}

void handle_collision(Paddle* p)
{
    auto paddle{p->getPaddleSprite().getGlobalBounds()};
    auto increase_paddle{p->getIncreaseSprite().getGlobalBounds()};
    
    // If paddle hits increase_paddle sprite, make it drop.
    if(paddle.intersects(increase_paddle))
    {
        p->paddle_increase();
    }
}
