#include <gtest/gtest.h>

#include "bowling.h"

static void roll_many(int n, int pins) {
  for (int i = 0; i < n; i++) {
    bowling_game_roll(pins);
  }
}

static void roll_spare() {
  bowling_game_roll(5);
  bowling_game_roll(5);
}

static void roll_strike() { bowling_game_roll(10); }

class Game : public testing::Test {
public:
  virtual void SetUp() { bowling_game_new(); }
};

TEST_F(Game, gutter_game) {
  roll_many(20, 0);
  EXPECT_EQ(bowling_game_score(), 0);
}

TEST_F(Game, all_ones) {
  roll_many(20, 1);
  EXPECT_EQ(bowling_game_score(), 20);
}

TEST_F(Game, one_spare) {
  roll_spare();
  bowling_game_roll(3);
  roll_many(17, 0);
  EXPECT_EQ(bowling_game_score(), 16);
}

TEST_F(Game, one_strike) {
  roll_strike();
  bowling_game_roll(3);
  bowling_game_roll(4);
  EXPECT_EQ(bowling_game_score(), 24);
}

TEST_F(Game, perfect_game) {
  roll_many(12, 10);
  EXPECT_EQ(bowling_game_score(), 300);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
