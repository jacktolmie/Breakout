#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "constants.hpp"

/* Global level and lives variable for multiple functions
 * instead of passing them as arguments. */
inline int g_level{constants::level};
inline int g_lives{constants::player_lives};
inline bool ball_missed{false};
inline bool is_hit{false}; 
inline bool is_increased{false}; 

#endif // GLOBAL_HPP
