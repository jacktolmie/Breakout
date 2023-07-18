#include "brick.hpp"

using vec_brick = std::vector<Brick>;

sf::Texture Brick::blue_brick;
sf::Texture Brick::green_brick;
sf::Texture Brick::red_brick;

void Brick::weaken() noexcept
{
    --strength;
}

bool Brick::is_too_weak() const noexcept
{
    return strength <= 0;
}

Brick::Brick(Entity_Manager& manager){Brick::bricks_reset(manager);}

Brick::Brick(float x, float y): Entity()
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
    
    sprite.setTexture(green_brick);
    sprite.setPosition(x,y);
    sprite.setOrigin(get_centre());
}

void Brick::update()
{ 
    switch(strength)
    { 
        case 1:{
            if(!green_brick.loadFromFile("brick_green.png"))
            {
                Entity::error("brick_green.png");
            }            
            sprite.setTexture(green_brick);
            break;
        }
        case 2:{
            if(!blue_brick.loadFromFile("brick_blue.png"))
            {
                Entity::error("brick_blue.png");
            }
            sprite.setTexture(blue_brick);
            break;
        }
        case 3:{
            if(!red_brick.loadFromFile("brick_red.png"))
            {
                Entity::error("brick_red.png");
            }            
            sprite.setTexture(red_brick);
            break;
        }
    }
}

void Brick::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

#include <random>
int Brick::get_random(int start, int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_red_bricks(start, end);
    
    return random_red_bricks(gen);
}

void Brick::bricks_reset(Entity_Manager& manager)
{        
    // Create main grid of green blocks.
    for (int i{0}; i < constants::brick_columns; ++i)
    {
        for (int j{0}; j < constants::brick_rows; ++j)
        {
            float x{constants::brick_offset + (i + 1) * constants::brick_width};
            float y{(j + 1) * constants::brick_height};

            manager.create<Brick>(x, y);
        }
    }

    // Get random number of strong bricks.
    int strong_bricks{Brick::get_random(1,6)};
    
    std::vector<Brick*> bricks;
    
    //!!!!!! Something is broken in this code. Fix random bricks.
    
//     /* Check all of the entities to see which are bricks.
//      * Add bricks to a vector to replace some with stronger
//      * bricks. Change accordingly. */
//     for(auto& brick: manager.get_entities())
//     {
//         if (Brick* test = dynamic_cast<Brick*>(brick.get()))
//         {
//             bricks.emplace_back(test);
//         }
//     }
//         
//     for(size_t i{0}; i < strong_bricks; ++i)
//     {
//         int random_spot{Brick::get_random(0, bricks.size() - 1)};
//         
//         // Check if the brick is already green. If it is get new number.
//         while(!bricks[random_spot]->is_green){
//             random_spot = Brick::get_random(0, bricks.size() - 1);
//         }
// 
//         // Change the brick from green to red.
//         bricks[random_spot]->strength = 3;
//         bricks[random_spot]->sprite.setTexture(red_brick);
//         bricks[random_spot]->is_green = false;       
//     }
    Brick::update();
}
