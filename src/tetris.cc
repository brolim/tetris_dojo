#include "tetris.h"

Tetris::Tetris (int w, int h) {
  width = w;
  height = h;
}

int Tetris::get_width () {
  return width;
}

int Tetris::get_height () {
  return height;
}
