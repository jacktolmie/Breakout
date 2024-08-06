#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "entity_manager.hpp"
#include "game_state.hpp"

class Textbox: public Entity
{
private:
    const float height{constants::textbox_height};
    const float width {constants::textbox_width};

    void update() override;
    void draw(sf::RenderWindow&) override;
    
    sf::RectangleShape text_background;
    
    // sf::Font verdana;
    sf::Font font;
    sf::Text text_titlebox, text_state, text_lives, text_level;
    
public:
    
    Textbox();
    virtual ~Textbox() = default;
    
    void display_text(sf::RenderWindow&, game_state&, Entity_Manager&);
    
    // Set the text for the game.
    void set_text();
    
};
#endif // TEXTBOX_HPP
