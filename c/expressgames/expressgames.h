#ifndef _EXPRESSGAMES_H_
#define _EXPRESSGAMES_H_

#include <vector>
#include <memory>

#include "button.h"
#include "expressgame.h"

using namespace std;

class ExpressGames {
private:
    vector<shared_ptr<ExpressGame>> _games;
    int _gameNumber;
    Button _buttonLeft;
    Button _buttonRight;
public:
    explicit ExpressGames();
    ~ExpressGames();
    void AddGame(const shared_ptr<ExpressGame> game);
    void Loop();
    bool Break();
private:
    bool InMenu() const;
    void ShowMenu() const;
    void Menu();
    void NextGameNumber();
    void NextGameParameter();
    void Game();
};

#endif //_EXPRESSGAMES_H_
