#include "gtest/gtest.h"
#include "../src/tetris.h"

TEST(TetrisSpec, builds_tetris_game_as_parameters_value) {

  Tetris tetris(5, 5);
  int width = tetris.get_width();
  int height = tetris.get_height();

  EXPECT_EQ(width, 5);
  EXPECT_EQ(height, 5);
}

TEST(TetrisSpec, BuildsTetrisGameAsParametersValue) {

  Tetris tetris(5, 5);
  int width = tetris.get_width();
  int height = tetris.get_height();

  EXPECT_EQ(width, 5);
  EXPECT_EQ(height, 5);

  tetris.show_board();
}
