#include "game.hpp"

// Begin/reset the game.
void Game::reset()
{
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
    
    // Create the bricks.
    Brick bricks{manager};
}
