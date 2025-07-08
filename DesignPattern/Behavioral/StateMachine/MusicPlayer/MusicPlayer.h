#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "PlayerState.h"

typedef struct MusicPlayer {
    PlayerState* currentState;
} MusicPlayer;

void changeState(MusicPlayer* player, PlayerState* newState);
void clickPlayButton(MusicPlayer* player);
void clickPauseButton(MusicPlayer* player);
void clickStopButton(MusicPlayer* player);

#endif
