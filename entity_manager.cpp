// #include "entity_manager.hpp"
#include "game.hpp"

void Entity_Manager::refresh()
{
    /* Remove alias pointers from the vector before deleting
     * the std::unique_ptr, to avoid dangling references. */
    for(auto& [type, alias_vector] : grouped_entities)
    {
        alias_vector.erase(std::remove_if(std::begin(alias_vector), std::end(alias_vector),[](auto p){return p->is_destroyed();}), std::end(alias_vector));
    }
    
    all_entities.erase(std::remove_if(std::begin(all_entities), std::end(all_entities), [] (const auto& p){return p->is_destroyed();}), std::end(all_entities));
}

void Entity_Manager::clear()
{
    grouped_entities.clear();
    all_entities.clear();
}

void Entity_Manager::update()
{
    for(auto& e: all_entities)
    {
        e->update();
    }
}

void Entity_Manager::draw(sf::RenderWindow& window)
{
    for(auto& e: all_entities)
    {
        e->draw(window);
    }
}

entity_vector& Entity_Manager::get_entities()
{
    return all_entities;
}
