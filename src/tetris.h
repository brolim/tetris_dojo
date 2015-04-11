#ifndef TETRIS_H_
#define TETRIS_H_

#include <ctime>

class Tetris {

  int get_user_input (int timeout);
  int end_game();

  int step_forward();
  int move_block(int pressed_key);

  public: 
    Tetris ();
    int show_board();
    int start_game();
};

#endif  // TETRIS_H_