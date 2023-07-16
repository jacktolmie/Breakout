#ifndef GAME_HPP
#define GAME_HPP

#include "background.hpp"
#include "ball.hpp"
#include "constants.hpp"
#include "entity_manager.hpp"
#include "interactions.hpp"
#include "paddle.hpp"

/* A class to manage the entities in the game. It stores the entities
 * in a vdctor of std::unique_ptr. The manager can create and entity
 * object and add it to the vector.
 * Exampe: Create a ball object at position (x,y) on the screen.
 * manager.create<Ball>(x,y); */
class Game
{
    Entity_Manager manager;
        
    /* Creat the game's window using an object of the class RenderWindow.
    * The constructor takes an SFML 2D vector with the window dimensions
    * and a std::string with the window title. */
    sf::RenderWindow game_window{{constants::window_width, constants::window_height}, "Simple Breakout Game."};
    
    sf::Font verdana;
    sf::Text text_state, text_lives, text_level;
    
    int lives{constants::player_lives};
    int level{1};
    
    // Enums for game state.
    enum class game_state{paused, running, game_over, player_wins};
    
    // Member to store current state of the game.
    game_state state{game_state::game_over};
    
    // Set the text for the game.
    void set_text();
    
    Paddle* paddle;
    
public:
    Game();
    
    // Reinitialize the game.
    void reset();
    
    // Game loop.
    void run();
};
#endif // GAME_HPP
