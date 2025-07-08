#include <stdio.h>
#include "MusicPlayer.h"
#include "PlayingState.h"
#include "StoppedState.h"
#include "PausedState.h"

void Paused_Play(MusicPlayer* player) {
    printf("Resuming music...\n");
    changeState(player, getPlayingState());
}

void Paused_Pause(MusicPlayer* player) {
    printf("Music is already paused.\n");
}

void Paused_Stop(MusicPlayer* player) {
    printf("Stopping music from paused state...\n");
    changeState(player, getStoppedState());
}

PlayerState* getPausedState() {
    static PlayerState state = {
        Paused_Play,
        Paused_Pause,
        Paused_Stop
    };
    return &state;
}
