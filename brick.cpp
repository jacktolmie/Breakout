#include "brick.hpp"

using vec_brick = std::vector<Brick>;

sf::Texture Brick::blue_brick;
sf::Texture Brick::green_brick;
sf::Texture Brick::red_brick;

Brick::Brick(Entity_Manager& manager, int rows, const Textbox& textbox): textbox{textbox}{Brick::bricks_reset(manager, rows, textbox);}

Brick::Brick(float x, float y, int row, const Textbox& textbox) : Entity(), row(row), textbox(textbox) 
{
    // Load the different brick images.
    if(!blue_brick.loadFromFile("brick_blue.png"))
    {
        Entity::error("brick_blue.png");
    }
    if(!red_brick.loadFromFile("brick_red.png"))
    {
        Entity::error("brick_red.png");
    }
    if(!green_brick.loadFromFile("brick_green.png"))
    {
        Entity::error("brick_green.png");
    }
    
    float textboxBottom = textbox.y() + textbox.get_bounding_box().height;
    float brickY = textboxBottom + (row + 3)    *   constants::brick_height;
    sprite.setPosition(x, brickY);
    sprite.setTexture(green_brick);
    sprite.setOrigin(get_centre());
}

void Brick::weaken() noexcept
{
    --strength;
}

bool Brick::is_too_weak() const noexcept
{
    return strength <= 0;
}

void Brick::update()
{ 
    switch(strength)
    { 
        case 1:{       
            sprite.setTexture(green_brick);
            break;
        }
        case 2:{
            sprite.setTexture(blue_brick);
            break;
        }
        case 3:{      
            sprite.setTexture(red_brick);
            break;
        }
    }
}

void Brick::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// Random number generator for red bricks.
#include <random>
int Brick::get_random(int start, int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_red_bricks(start, end);
    
    return random_red_bricks(gen);
}

