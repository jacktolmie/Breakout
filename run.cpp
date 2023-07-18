#include "game.hpp"

void Game::run()
{
    bool paused_key_active{false};
    
    while (game_window.isOpen())
    {
        game_window.clear();

        // Create an event to check for close window click.
        sf::Event event;
        
        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game_window.close();
        }
        
        // Check for various key presses.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            break;
        
        // Check if 'p' or 'space bar' was pressed to pause the game.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            if(!paused_key_active)
            {
                state = (state == game_state::paused)? game_state::running : game_state::paused;
            }
            paused_key_active = true;
        }
        else
        {
            paused_key_active = false;
        }
        
        // Check if the user wants to reset the game.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        {
            Game::reset();
        }
        
        // if (state == game_state::paused)
        // {
        //     // Display the graphics.
        //     manager.draw(game_window);
        // }
        
        // If the game is not running, check the state and display on the screen.
        if (state != game_state::running)
        {
            switch (state)
            {
                case game_state::paused:
                {
                    // If paused, keep the game on the screen.
                    text_state.setString("Paused");
                    manager.draw(game_window);
                    break;
                }
                
                // If not paused, have a black screen with text.
                case game_state::game_over:
                {
                    text_state.setString("Game Over!");
                    break;
                }
                case game_state::player_wins:
                {
                    text_state.setString("Player Wins!");
                    break;
                }
                default:
                {
                    break;
                }
            }
            Game::display_text();
            // manager.draw(game_window);
        }
        else
        {
            //If no balls remaining on screen.
            if (manager.get_all<Ball>().empty())
            {

                paddle->paddle_reset();
                manager.create<Ball>();
                
                --lives;
                
                state = game_state::paused;
            }
            
            // If no bricks on screen.
            if (manager.get_all<Brick>().empty())
            {
                state = game_state::player_wins;
                std::cout<<"No more bricks\n";
                // Increase level by one.
                ++level;
                
                // Reset the game to next level.
                Game::reset();
            }
            
            if (lives <= 0)
            {
                state = game_state::game_over;
            }
                       
            manager.update();
            
            manager.apply_all<Ball>([this](auto& the_ball){
                manager.apply_all<Brick>([&the_ball](auto& the_brick){
                    handle_collision(the_ball, the_brick);
                });
            });
            
            manager.apply_all<Ball>([this](auto& the_ball){
                manager.apply_all<Paddle>([&the_ball](auto& the_paddle){
                    handle_collision(the_ball, the_paddle);
                });
            });
            
            manager.refresh();
            
            manager.draw(game_window);
            
            // Display title bar on top of screen.
            Game::set_text();
            Game::display_text();
        }

        game_window.display();
    }
}
