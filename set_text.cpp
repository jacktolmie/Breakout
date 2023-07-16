#include "game.hpp"

void Game::set_text(){
    
    text_state.setFont(verdana);
    text_state.setPosition(constants::centre_width - 100.0f, constants::centre_height - 100.0f);
    text_state.setCharacterSize(20);
    text_state.setFillColor(sf::Color::White);
    text_state.setString("Paused");
    
    text_lives.setFont(verdana);
    text_lives.setPosition(constants::centre_width - 65.0f, constants::centre_height - 50.0f);
    text_lives.setCharacterSize(20);
    text_lives.setFillColor(sf::Color::White);
    text_lives.setString("Lives: " + std::to_string(lives));
    
    text_level.setFont(verdana);
    text_level.setPosition(constants::centre_width - 40.0f, constants::centre_height - 40.0f);
    text_level.setCharacterSize(20);
    text_level.setFillColor(sf::Color::Black);
    text_level.setString("Level: " + std::to_string(level));
}
