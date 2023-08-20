#include "game.hpp"

Game::Game()
{
    // Sets the frame rate per second. 60 is the norm for games.
    game_window.setFramerateLimit(60);
    
     // Populate the sprites of the game.
    Game::reset();
}

Entity_Manager& Game::get_manager()
{
    return manager;
}
