#include "gtest/gtest.h"
#include "../src/tetris.h"

#include <iostream>
using namespace std;

TEST(TetrisSpec, BuildsTetrisGameAsParametersValue) {

  Tetris tetris(5, 5);
  int width = tetris.get_width();
  int height = tetris.get_height();

  EXPECT_EQ(width, 5);
  EXPECT_EQ(height, 5);
}
