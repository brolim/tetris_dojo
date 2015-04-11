#ifndef TETRIS_H_
#define TETRIS_H_

#include <ctime>

class Tetris {

  int width, height, step;
  bool game_started;

  public: 
    Tetris (int width, int height);
    int get_width();
    int get_height();
    int show_board(int);
    int start_game();
    int step_forward();
    int move_block(int pressed_key);
    int get_user_input (int timeout);
};

#endif  // TETRIS_H_