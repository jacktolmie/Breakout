#include "game.hpp"

// Begin/reset the game.
void Game::reset()
{
    // Reset the lives, brick rows, and level.
    g_lives = constants::player_lives;
    g_level = constants::level;
    rows  = constants::brick_rows;

    
    state = game_state::paused;

    manager.clear();
	manager.create<Background>();
	manager.create<Ball>();
	manager.create<Paddle>();
    manager.create<Textbox>();

    textbox.display_text(game_window, state, manager);
    
    // Create the bricks.
    bricks.bricks_reset(manager, rows, textbox);
    
    // Find paddle in entity vector to reset paddle when resetting the ball.
    auto check_paddle{std::find_if(manager.get_entities().begin(), manager.get_entities().end(), [](auto& ent){
                        if(Paddle* paddle = dynamic_cast<Paddle*>(ent.get())) return true;
                        return false;})
                     };
         
    if(check_paddle != manager.get_entities().end()){
        paddle = dynamic_cast<Paddle*>(check_paddle->get());
    }
    
    // Find ball in the entity vector to reset the ball when finished a level.
    auto check_ball{std::find_if(manager.get_entities().begin(), manager.get_entities().end(), [](auto& ent){
                        if(Ball* ball = dynamic_cast<Ball*>(ent.get())) return true;
                        return false;})
                     };
                     
    if(check_ball != manager.get_entities().end()){
        ball = dynamic_cast<Ball*>(check_ball->get());
    }
    
}
