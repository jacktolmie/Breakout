#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "entity.hpp"

using entity_vector = std::vector<std::unique_ptr<Entity>>;
using entity_alias_vector = std::vector<Entity*>;

/* A class to manage the entities in the game. It stores the entities
 * in a vdctor of std::unique_ptr. The manager can create and entity
 * object and add it to the vector.
 * Exampe: Create a ball object at position (x,y) on the screen.
 * manager.create<Ball>(x,y); */
class Entity_Manager
{
private:
    std::map<size_t, entity_alias_vector> grouped_entities;
    entity_vector all_entities;
    
public:
    
template <typename T, typename... Args>
T& create(Args&&... args)
{
    // Check that the type parameter is derived from the eneity base class.
    static_assert(std::is_base_of<Entity, T>::value, R"("T" type parameter in create() must derive from "Entity" class")");
    
    /* Create a unique_ptr to the entity. Forward the arguments to the
     * entity's constructor. */
    auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};
    
    /* Make an alias pointer to the allocated memory. This will be stored
     * in the entity_type_vector. */
    auto ptr_alias{ptr.get()};
    
    // Get the hash code for the entity object's type.
    auto hash{typeid(T).hash_code()};
    
    // Insert the alias pointer into the map.
    grouped_entities[hash].emplace_back(ptr_alias);
    
    // Insert the object's pointer into the entities vector.
    all_entities.emplace_back(std::move(ptr));
    
    // Return the new object.
    return *ptr_alias;
}
    
    template <typename T>
    auto& get_all() {
        return grouped_entities[typeid(T).hash_code()];
    }
        
        void clear();
        void draw(sf::RenderWindow&);    
        void refresh();
        void update();
        entity_vector& get_entities();

    // Apply a function to all entities of a given type
    template <typename T, typename Func>
    void apply_all(const Func& func) {
        auto& entity_group{get_all<T>()};
    
        for (auto ptr : entity_group)
        {
            func(*dynamic_cast<T*>(ptr));
        }
    }
};

#endif // ENTITY_MANAGER_HPP
