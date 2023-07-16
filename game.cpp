#include "game.hpp"

Game::Game()
{
     // Populate the sprites of the game.
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
    
    // Get the text required for the game.
    Game::set_text();
    
    // Find paddle in entity vector to reset paddle when resetting the ball.
    auto check_paddle{std::find_if(manager.get_entities().begin(), manager.get_entities().end(), [](auto& ent){
                        if(Paddle* paddle = dynamic_cast<Paddle*>(ent.get())) return true;
                        return false;})
                     };
         
    if(check_paddle != manager.get_entities().end()){
        paddle = dynamic_cast<Paddle*>(check_paddle->get());
    }
    
}
