#ifndef _MONKEYROOMS_H_
#define _MONKEYROOMS_H_

#include <vector>

#include "button.h"
#include "expressgame.h"

using namespace std;

class MonkeyRooms : public ExpressGame {
protected:
    unsigned long _states; // 2 bits per room: 1 if the monkey can be there + 2 if marked
    int _steps;
    int _cursor;
    Button _buttonLeft;
    Button _buttonRight;
public:
    explicit MonkeyRooms() : ExpressGame(2, 5), 
            _buttonLeft(false), _buttonRight(true) {}
    void Reset() override;
    bool Move() override;
    void Draw() const override;
protected:
    void Transform();
    void Win();
};

#endif // _MONKEYROOMS_H_
