#include "game.hpp"

void Game::set_text(){
    
    text_background.setFillColor(sf::Color::Black);
    text_background.setPosition(0.0f, 0.0f);
    text_background.setSize(sf::Vector2f(constants::window_width, 25.0f));
    game_window.draw(text_background);
    
    // Set and centre game's state.
    text_state.setFont(verdana);
    text_state.setString("Paused");
    text_state.setPosition(constants::centre_width - (text_state.getGlobalBounds().width/2.0f), constants::centre_height);
    text_state.setCharacterSize(20);
    text_state.setFillColor(sf::Color::White);
    
    // Set 'lives' text and place top left of screen.
    text_lives.setFont(verdana);
    text_lives.setStyle(text_lives.Italic);
    text_lives.setString("Lives: " + std::to_string(lives));
    text_lives.setPosition(5.0f, 1.0f);
    text_lives.setCharacterSize(20);
    text_lives.setFillColor(sf::Color::White);
    
    // Set 'level' text and place top right of screen.
    text_level.setFont(verdana);
    text_level.setStyle(text_level.Italic);
    text_level.setString("Level: " + std::to_string(level));
    text_level.setPosition(constants::window_width - text_level.getGlobalBounds().width - 10.0f, 1.0f);
    text_level.setCharacterSize(20);
    text_level.setFillColor(sf::Color::White);
    
}
