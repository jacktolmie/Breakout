#include "game.hpp"

// Begin/reset the game.
void Game::reset()
{
    // Check if no lives left. Reset to 3. Set level to constants::level.
    if(!g_lives)
    {
        g_lives = constants::player_lives;
        g_level = constants::level;
        rows  = constants::brick_rows;
    }
    
    state = game_state::paused;
    
    manager.clear();
	manager.create<Background>();
	manager.create<Ball>();
	manager.create<Paddle>();
    manager.create<Textbox>();
    
    textbox.display_text(game_window, state, manager);
    
    // Create the bricks.
    Brick bricks{manager, rows, textbox};
    
    // Find paddle in entity vector to reset paddle when resetting the ball.
    auto check_paddle{std::find_if(manager.get_entities().begin(), manager.get_entities().end(), [](auto& ent){
                        if(Paddle* paddle = dynamic_cast<Paddle*>(ent.get())) return true;
                        return false;})
                     };
         
    if(check_paddle != manager.get_entities().end()){
        paddle = dynamic_cast<Paddle*>(check_paddle->get());
    }
}
