#ifndef CONSTANTS_H
#define CONSTANTS_H

struct constants {
    
    static constexpr int    level{1}; //change to 1 when done
    
    static constexpr int    window_width{520};
    static constexpr int    window_height{640};
    static constexpr int    window_top{25};
    
    static constexpr float  centre_width{window_width/2.0f};
    static constexpr float  centre_height{window_height/2.0f};
    
    static constexpr float  ball_start_width{constants::centre_width};
    static constexpr float  ball_start_height{constants::window_height/3.5f};
    static constexpr float  ball_speed{6.0f}; //set to 6
    
    static constexpr float  paddle_width{60.0f};
    static constexpr float  paddle_height{20.0f};
    static constexpr float  paddle_speed{8.0f};
    
    static constexpr float  textbox_width{window_width};
    static constexpr float  textbox_height{25.0f};
    
    static constexpr float  brick_width{43.0f};
    static constexpr float  brick_height{20.0f};
    static constexpr float  brick_offset{brick_width/2.0f};
    static constexpr int    brick_columns{1}; //change to 10 when done
    static constexpr int    brick_rows{1}; //change to 1 when done
    static constexpr int    brick_max_rows{6};
    static constexpr int    regular_brick_strength{1};
    static constexpr int    strong_brick_strength{3};
    static constexpr float  increase_brick_slow{3.0f};
    static constexpr float  increase_brick_fast {5.0f};
    
    static constexpr int    player_lives{3};
};
#endif //CONSTANTS_H
