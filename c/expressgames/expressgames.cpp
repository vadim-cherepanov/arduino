#include "expressgames.h"

#include <Adafruit_CircuitPlayground.h>
static auto &Express = CircuitPlayground;

using namespace std;

ExpressGames::ExpressGames() : 
        _gameNumber(0), _buttonLeft(false), _buttonRight(true) {
    Express.begin();
}

ExpressGames::~ExpressGames() {
    
}

void ExpressGames::AddGame(const shared_ptr<ExpressGame> game) {
    _games.push_back(game);
}

void ExpressGames::Loop() {
    while (true) {
        if (InMenu()) Menu();
        else Game();
    }
}

bool ExpressGames::InMenu() const {
    return Express.slideSwitch();
}

void ExpressGames::ShowMenu() const {
    bool show = InMenu();
    Express.redLED(show ? HIGH : LOW);
    if (show) {
        for (int i = 0; i < 5; ++i) Express.setPixelColor(i, 0, (i <= _gameNumber ? 255 : 0), 0);
        int param = _games[_gameNumber]->GetParameter();
        for (int i = 9; i >= 5; --i) Express.setPixelColor(i, 0, 0, (--param >= 0 ? 255 : 0));
    }
    else {
        Express.clearPixels();
    }
}

void ExpressGames::Menu() {
    ShowMenu();
    while (InMenu()) {
        if (_buttonLeft.Clicked()) NextGameNumber();
        if (_buttonRight.Clicked()) NextGameParameter();
    }
}

void ExpressGames::NextGameNumber() {
    if (++_gameNumber >= _games.size()) _gameNumber = 0;
    ShowMenu();
}

void ExpressGames::NextGameParameter() {
    auto &game = _games.at(_gameNumber);
    auto parameter = game->GetParameter() + 1;
    game->SetParameter(parameter <= game->GetParameterMax() ? parameter : game->GetParameterMin());
    ShowMenu();
}

void ExpressGames::Game() {
    ShowMenu();
    auto &game = _games[_gameNumber];
    game->Draw();
    while (!InMenu() && !game->Break()) if (game->Move()) game->Draw();
}
