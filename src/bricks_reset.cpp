#include "../include/brick.hpp"

void Brick::bricks_reset(Entity_Manager& manager, int rows, const Textbox& textbox)
{        
    int total_rows{(rows < constants::brick_max_rows)? rows : 6};
    
    // Thanks to Chatgpt for helping me with solving the bricks below the textbox fix.
    for (int i{0}; i < constants::brick_columns; ++i)
    {
        for (int j = 0; j < total_rows; ++j) {
        float x = constants::brick_offset + (i + 1) * constants::brick_width;
        // Use the row number j to set the correct position for the brick.
        float y = (j + 1) * constants::brick_height;

        manager.create<Brick>(x, y, j, textbox);
        }
    }

    // Get random number of strong bricks if rows is above 3.
    if (rows > 2)
    {
        // If rows are less than 6, no more than 3 strong bricks, otherwise up to 8.
        int strong_bricks{(rows < 6)? Brick::get_random(1,3): Brick::get_random(1,8)};    
    
        std::vector<Brick*> bricks;
        
        /* Check all of the entities to see which are bricks.
        * Add bricks to a vector to replace some with stronger
        * bricks.*/
        for(auto& brick: manager.get_entities())
        {
            if (Brick* test = dynamic_cast<Brick*>(brick.get()))
            {   
                bricks.emplace_back(test);
            }
        }
            
        for(size_t i{0}; i < strong_bricks; ++i)
        {
            int random_spot{Brick::get_random(0, bricks.size() - 1)};
            
            if(g_level > 5 && !will_drop && !is_increased)
            {
                bricks[random_spot]->will_drop = true; // Find a way to set this to one random brick.
                will_drop = true;
                std::cout<<"will_drop is true\n";
            }
            
            // Check if the brick is already green. If it is get new number.
            while(!bricks[random_spot]->is_green){
                random_spot = Brick::get_random(0, bricks.size() - 1);
            }

            // Change the brick from green to red.
            bricks[random_spot]->strength = 3;
            bricks[random_spot]->sprite.setTexture(red_brick);
            bricks[random_spot]->is_green = false;       
        }
    }
    Brick::update();
}
