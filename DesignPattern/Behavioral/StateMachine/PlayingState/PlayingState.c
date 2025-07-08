#include <stdio.h>
#include "MusicPlayer.h"
#include "PausedState.h"
#include "StoppedState.h"
#include "PlayingState.h"

void Playing_Play(MusicPlayer* player) {
    printf("Music is already playing.\n");
}

void Playing_Pause(MusicPlayer* player) {
    printf("Pausing music...\n");
    changeState(player, getPausedState());
}

void Playing_Stop(MusicPlayer* player) {
    printf("Stopping music...\n");
    changeState(player, getStoppedState());
}

PlayerState* getPlayingState() {
    static PlayerState state = {
        Playing_Play,
        Playing_Pause,
        Playing_Stop
    };
    return &state;
}
