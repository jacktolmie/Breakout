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
            
            // Loop to stop Keyboard events if window is not in focus.
            while (event.type == sf::Event::LostFocus)
            {
                state = game_state::paused;
                
                game_window.pollEvent(event);
                
                if(event.type == sf::Event::GainedFocus)
                {
                    break;
                }
            }            
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
        
        // If the game is not running, check the state and display on the screen.
        if (state != game_state::running)
        {
            // If game is not running, display state.
            textbox.set_text();
            textbox.display_text(game_window, state, manager);
        }
        else
        {
            //If no balls remaining on screen.
            if (manager.get_all<Ball>().empty())
            {
                // Set ball_missed to true, to reset the paddle size.
                ball_missed = true;

                // Decrement one life.
                --g_lives;
                
                /* Reset the paddle to centre, and remove the_ball
                 * drop_increase sprite if it is on the screen. */
                paddle->paddle_reset();

                manager.create<Ball>();
                
                state = game_state::paused;
            }
            
            // If no bricks on screen.
            if (manager.get_all<Brick>().empty())
            {
                ball_missed = false;
                
                // state = game_state::player_wins;
                // Increase level by one.
                ++g_level;
                ++rows;
                
                // Reset the game to next level.
                Game::reset();
            }
            
            if (g_lives <= 0)
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

            handle_collision(paddle);
            
            manager.refresh();
            
            manager.draw(game_window);
            
            // Display title bar on top of screen.
            textbox.set_text();
            textbox.display_text(game_window, state, manager);
        }

        game_window.display();
    }
}
