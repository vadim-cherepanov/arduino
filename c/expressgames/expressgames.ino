#include <Arduino.h>
#undef min
#undef max
#include "expressgames.h"
#include "monkeyrooms.h"

void setup() {
    ExpressGames expressGames;
    expressGames.AddGame(make_shared<MonkeyRooms>());
    expressGames.Loop();
}

void loop() {
}
