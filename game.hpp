#ifndef GAME_HPP
#define GAME_HPP

#include "background.hpp"
#include "constants.hpp"
#include "entity_manager.hpp"
#include "game_state.hpp"
#include "interactions.hpp"

/* A class to manage the entities in the game. It stores the entities
 * in a vector of std::unique_ptr. The manager can create and entity
 * object and add it to the vector.
 * Example: Create a ball object at position (x,y) on the screen.
 * manager.create<Ball>(x,y); */
class Game
{
    Entity_Manager manager;
        
    /* Create the game's window using an object of the class RenderWindow.
    * The constructor takes an SFML 2D vector with the window dimensions
    * and a std::string with the window title. */
    sf::RenderWindow game_window{{constants::window_width, constants::window_height}, "Simple Breakout Game."};
    
    // Member to store current state of the game.
    game_state state{game_state::game_over};
    
    Paddle* paddle;
    Textbox textbox;

    int     rows{constants::brick_rows};
    
public:
    Game();
    
    // Reinitialize the game.
    void reset();
    
    // Game loop.
    void run();
};
#endif // GAME_HPP
