#include <stdio.h>
#include "MusicPlayer.h"

void changeState(MusicPlayer* player, PlayerState* newState) {
    player->currentState = newState;
}

void clickPlayButton(MusicPlayer* player) {
    player->currentState->pressPlay(player);
}

void clickPauseButton(MusicPlayer* player) {
    player->currentState->pressPause(player);
}

void clickStopButton(MusicPlayer* player) {
    player->currentState->pressStop(player);
}
