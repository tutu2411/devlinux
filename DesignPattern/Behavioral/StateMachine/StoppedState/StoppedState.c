#include <stdio.h>
#include "MusicPlayer.h"
#include "PlayingState.h"
#include "StoppedState.h"

void Stopped_Play(MusicPlayer* player) {
    printf("Starting music...\n");
    changeState(player, getPlayingState());
}

void Stopped_Pause(MusicPlayer* player) {
    printf("Cannot pause. Music is already stopped.\n");
}

void Stopped_Stop(MusicPlayer* player) {
    printf("Music is already stopped.\n");
}

PlayerState* getStoppedState() {
    static PlayerState state = {
        Stopped_Play,
        Stopped_Pause,
        Stopped_Stop
    };
    return &state;
}
