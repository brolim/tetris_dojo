#include "gtest/gtest.h"

TEST(TetrisSpec, Fails) {
  EXPECT_EQ(1, 2);
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }

// compile using de following command
// g++ -I ../gtest-1.7.0/include/ -L ../gtest-1.7.0/lib -lgtest -o tetris tetris_spec.cc
