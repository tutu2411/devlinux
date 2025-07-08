#include <stdio.h>
#include "MusicPlayer.h"
#include "StoppedState.h"

int main() {
    MusicPlayer player;
    changeState(&player, getStoppedState());

    clickPlayButton(&player);   // Starting music...
    clickPauseButton(&player);  // Pausing music...
    clickPlayButton(&player);   // Resuming music...
    clickStopButton(&player);   // Stopping music...
    clickPauseButton(&player);  // Cannot pause. Music is already stopped.

    return 0;
}
