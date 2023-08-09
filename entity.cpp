#include "entity.hpp"

sf::FloatRect Entity::get_bounding_box() const noexcept
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Entity::get_centre() const noexcept
{
    auto box{get_bounding_box()};
    return {box.width/2.0f, box.height/2.0f};
}

float Entity::x() const noexcept
{
    return sprite.getPosition().x;
}

float Entity::y() const noexcept
{
    return sprite.getPosition().y;
}

float Entity::left() const noexcept
{
    auto box{get_bounding_box()};
    return x() - box.width/2.0f;
}

float Entity::right() const noexcept
{
    auto box{get_bounding_box()};
    return x() + box.width/2.0f;
}

float Entity::top() const noexcept
{
    auto box{get_bounding_box()};
    return y() - box.height/2.0f;
}

float Entity::bottom() const noexcept
{
    auto box{get_bounding_box()};
    return y() + box.height/2.0f;
}

// Function to print to console of an image failed to load.
void Entity::error(std::string_view image_name)
{
    std::cerr<<"Failed to load image " << image_name << "\n";
    exit(1);
}

// Helper functions for the state of the entity
void Entity::destroy() noexcept 
{ 
    destroyed = true; 
}
bool Entity::is_destroyed() const noexcept 
{ 
    return destroyed; 
}
