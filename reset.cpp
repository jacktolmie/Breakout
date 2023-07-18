#include "game.hpp"

// Begin/reset the game.
void Game::reset()
{
    // Check if no lives left. Reset to 3. Set level to 0.
    if(lives == 0)
    {
        lives = constants::player_lives;
        level = 0;
    }
    
    
    state = game_state::paused;
    
    manager.clear();
	manager.create<Background>();
	manager.create<Ball>();
	manager.create<Paddle>();
    
    Game::set_text();
    
    // Create the bricks.
    Brick bricks{manager};
}
