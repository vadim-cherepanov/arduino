#include "button.h"

#include <Adafruit_CircuitPlayground.h>
static auto &Express = CircuitPlayground;

Button::Button(bool right, unsigned long timeMinimum, unsigned long timeRepeatDelay, unsigned long timeRepeatRate) : 
        _right(right), _down(false), _state(0), 
        _timeDelays({timeMinimum, timeRepeatDelay, 1000 / timeRepeatRate}), 
        _timeLastClick(0ul) {
    Clicked();
}

bool Button::Clicked() {
    if (!_right) _down = Express.leftButton();
    else _down = Express.rightButton();
    if (!_down) {
        _state = 0;
        return false;
    }
    unsigned long now = millis();
    if (now >= _timeLastClick + _timeDelays[_state]) {
        if (_state < 2) ++_state;
        _timeLastClick = now;
        return true;
    }
    return false;
}
