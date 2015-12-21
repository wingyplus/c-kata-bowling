static const int max_rolls = 21;
static int rolls[max_rolls];
static int current_roll;

void bowling_game_new() {
  current_roll = 0;
  for (int i = 0; i < max_rolls; i++) {
    rolls[i] = 0;
  }
}

void bowling_game_roll(int pins) {
  rolls[current_roll] = pins;
  current_roll++;
}

static int is_spare(int frame_index) {
  return rolls[frame_index] + rolls[frame_index + 1] == 10;
}

static int is_strike(int frame_index) {
  return rolls[frame_index] == 10;
}

static int strike_bonus(int frame_index) {
  return rolls[frame_index + 1] + rolls[frame_index + 2];
}

static int spare_bonus(int frame_index) {
  return rolls[frame_index + 2];
}

static int sum_of_balls_in_frame(int frame_index){
  return rolls[frame_index] + rolls[frame_index + 1];
}

int bowling_game_score() {
  int score = 0, frame_index = 0;

  for (int frame = 0; frame < 10; frame++) {
    if (is_strike(frame_index)) {
      score += 10 + strike_bonus(frame_index);
      frame_index++;
    } else if (is_spare(frame_index)) {
      score += 10 + spare_bonus(frame_index);
      frame_index += 2;
    } else {
      score += sum_of_balls_in_frame(frame_index);
      frame_index += 2;
    }
  }

  return score;
}
