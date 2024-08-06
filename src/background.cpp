#include "../include/background.hpp"

sf::Texture Background::texture;

Background::Background(): Background{0.0f, 0.0f}{}

Background::Background(float x, float y): Entity() {
    // Load the texture file.
    if(!texture.loadFromFile("Images/Breakout.png"))
    {
        Entity::error("background.jpg");
    }
    
    sprite.setTexture(texture);
    
    // Set the initial position and velocity of the background.
    // Use (x, y) for the initial position of the background.
    sprite.setPosition(x, y);
}

// Compute the background's new position.
void Background::update() {}

void Background::draw(sf::RenderWindow& window) {
    // Ask the window to draw the sprite.
    window.draw(sprite);
}
