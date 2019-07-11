#include <Arduino.h>
#undef min
#undef max
#include "expressgames.h"
#include "monkeyrooms.h"

void setup() {
    ExpressGames expressGames;
    expressGames.AddGame(make_shared<MonkeyRooms>());
    for (auto &p : expressGames.GetGames()) p->Reset();
    expressGames.Loop();
}

void loop() {
}
