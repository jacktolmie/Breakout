#include "game.hpp"
#include "interactions.hpp"

Game::Game()
{
     // Populate the bricks vector.
    Game::reset();
    
    // Sets the frame rate per second. 60 is the norm for games.
    game_window.setFramerateLimit(60);
    
    /* Load font from system. Check if Windows or Linux. */
#ifdef linux
    verdana.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/verdana.ttf");
#endif
    
#ifdef _WIN32
    verdana.loadFromFile("C:/Windows/fonts/Verdana.ttf");
#endif
    
    text_state.setFont(verdana);
    text_state.setPosition(constants::window_width/2.0f - 100.0f, constants::window_height/2.0f - 100.0f);
    text_state.setCharacterSize(35);
    text_state.setFillColor(sf::Color::White);
    text_state.setString("Paused");
    
    text_lives.setFont(verdana);
    text_lives.setPosition(constants::window_width/2.0f - 65.0f, constants::window_height/2.0f - 50.0f);
    text_lives.setCharacterSize(35);
    text_lives.setFillColor(sf::Color::White);
    text_lives.setString("Lives: " + std::to_string(lives));
    
    // Find paddle in entity vector to reset paddle when resetting the ball.
    auto check_paddle{std::find_if(manager.get_entities().begin(), manager.get_entities().end(), [](auto& ent){
                        if(Paddle* paddle = dynamic_cast<Paddle*>(ent.get())) return true;
                        return false;})
                     };
         
    if(check_paddle != manager.get_entities().end()){
        paddle = dynamic_cast<Paddle*>(check_paddle->get());
    }
    
}

// Begin/reset the game.
void Game::reset()
{
    lives = constants::player_lives;
    
    state = game_state::paused;
    
    manager.clear();
	manager.create<Background>();
	manager.create<Ball>();
	manager.create<Paddle>();
    
    // Create the bricks.
    Brick bricks{manager};
}

void Game::run()
{
    bool paused_key_active{false};
    
    while (game_window.isOpen())
    {
        game_window.clear(sf::Color::Black);
        
        sf::Event event;
        
        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game_window.close();
        }
        
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
        
        if (state == game_state::paused)
        {
            // Display the graphics.
            manager.draw(game_window);
        }
        
        if (state != game_state::running)
        {
            switch (state)
            {
                case game_state::running:
                {
                    text_state.setString("   Paused   ");
                    break;
                }
                case game_state::game_over:
                {
                    text_state.setString("  Game Over!  ");
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
            game_window.draw(text_state);
            game_window.draw(text_lives);
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
            }
            
            if (lives <= 0)
            {
                state = game_state::game_over;
            }
            
            text_lives.setString("Lives: " + std::to_string(lives));
            
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
        }
        game_window.display();
    }
}
