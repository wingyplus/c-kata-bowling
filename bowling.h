#ifndef BOWLING_H_
#define BOWLING_H_

#ifdef __cplusplus
extern "C" {
#endif

void bowling_game_new();
void bowling_game_roll(int pins);
int bowling_game_score();

#ifdef __cplusplus
}
#endif

#endif // BOWLING_H_
