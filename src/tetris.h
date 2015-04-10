#ifndef TETRIS_H_
#define TETRIS_H_

class Tetris {

  int width, height;

  public: 
    Tetris (int width, int height);
    int get_width();
    int get_height();
};

#endif  // TETRIS_H_