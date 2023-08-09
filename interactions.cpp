#include "interactions.hpp"

bool is_interacting(const Entity& e1, const Entity& e2)
{
    auto box1{e1.get_bounding_box()};
    auto box2{e2.get_bounding_box()};
    return box1.intersects(box2);
}

// Add a spin on the ball if it hits a moving paddle. Thanks to chatgpt for this code.
void applySpinEffect(sf::Vector2f& ballVelocity, float spinAngle)
{
    // Calculate the new velocity direction after applying the spin effect
    float oldVelocityMagnitude = std::sqrt(ballVelocity.x * ballVelocity.x + ballVelocity.y * ballVelocity.y);
    float newVelocityAngle = std::atan2(ballVelocity.y, ballVelocity.x) + spinAngle;

    // Update the ball's velocity with the new direction and the same magnitude
    ballVelocity.x = oldVelocityMagnitude * std::cos(newVelocityAngle);
    ballVelocity.y = oldVelocityMagnitude * std::sin(newVelocityAngle);    
}

float calculateSpinAngle(const sf::Vector2f& paddleVelocity)
{
    // Calculate the magnitude (speed) of the paddle's movement
    float paddleSpeed = std::sqrt(paddleVelocity.x * paddleVelocity.x + paddleVelocity.y * paddleVelocity.y);

    // Calculate the angle of the paddle's movement (in radians)
    float paddleAngle = std::atan2(paddleVelocity.y, paddleVelocity.x);

    // Define a factor to adjust the spin based on paddle speed (experiment with this value)
    float spinFactor = 0.2f;

    // Calculate the spin angle based on the paddle's movement speed and direction
    float spinAngle = paddleSpeed * spinFactor * std::cos(paddleAngle);

    return spinAngle;    
}

// Function to calculate the relative velocity between the ball and the paddle at the collision point
sf::Vector2f calculateRelativeVelocity(const sf::Vector2f& ballVelocity, const sf::Vector2f& paddleVelocity)
{
    return ballVelocity - paddleVelocity;
}

// Function to adjust the ball's velocity to move in the same way as the paddle's movement
void adjustBallVelocity(sf::Vector2f& ballVelocity, const sf::Vector2f& relativeVelocity)
{
    ballVelocity += relativeVelocity;
}
// End chatgpt code.
