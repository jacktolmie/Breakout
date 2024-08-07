#include "../include/textbox.hpp"

Textbox::Textbox(): Entity()
{
/* Load font from system. Check if Windows or Linux. */
#ifdef linux
    font.loadFromFile("NotoSans-Black.ttf");
#endif

#ifdef _WIN32
    font.loadFromFile("C:/Windows/fonts/Verdana.ttf");
#endif
}

void Textbox::display_text(sf::RenderWindow& game_window, game_state& state, Entity_Manager& manager)
{   
    game_window.draw(text_background);
    game_window.draw(text_lives);
    game_window.draw(text_level);
    
    if (state != game_state::running)
    {
        switch (state)
        {
            case game_state::paused:
            {
                manager.draw(game_window);
                game_window.draw(text_background);
                game_window.draw(text_lives);
                game_window.draw(text_level);
                text_state.setString("Paused");
                game_window.draw(text_state);
                break;
            }
            case game_state::game_over:
            {
                text_state.setString("Game Over!");
                game_window.draw(text_state);
                break;
            }
            default:
            {
                break;
            }
        }    
    }
}

void Textbox::set_text()
{
    text_background.setFillColor(sf::Color::Black);
    text_background.setPosition(0.0f, 0.0f);
    text_background.setSize(sf::Vector2f(constants::window_width, constants::window_top));
    
    // Set and centre game's state.
    text_state.setFont(font);
    text_state.setString("Paused");
    text_state.setPosition(constants::centre_width - (text_state.getGlobalBounds().width/2.0f), constants::centre_height);
    text_state.setCharacterSize(20);
    text_state.setFillColor(sf::Color::White);
    
    // Set 'lives' text and place top left of screen.
    text_lives.setFont(font);
    text_lives.setStyle(text_lives.Italic);
    text_lives.setString("Lives: " + std::to_string(g_lives));
    text_lives.setPosition(5.0f, 1.0f);
    text_lives.setCharacterSize(20);
    text_lives.setFillColor(sf::Color::White);
    
    // Set 'level' text and place top right of screen.
    text_level.setFont(font);
    text_level.setStyle(text_level.Italic);
    text_level.setString("Level: " + std::to_string(g_level));
    text_level.setPosition(constants::window_width - text_level.getGlobalBounds().width - 10.0f, 1.0f);
    text_level.setCharacterSize(20);
    text_level.setFillColor(sf::Color::White);
}

void Textbox::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Textbox::update(){}
