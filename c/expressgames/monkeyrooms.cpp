#include "monkeyrooms.h"

#include <Adafruit_CircuitPlayground.h>
static auto &Express = CircuitPlayground;

static const unsigned long stateMask = 0x55555ul;
static const unsigned long colors[4] { 0x000000ul, 0x101010ul, 0x000010ul, 0x001000ul };
static const unsigned long colorCursor = 0x400000ul;
static const int stepsOptimal[6] {0, 0, 8, 4, 3, 2};

void MonkeyRooms::Reset() {
    _states = stateMask;
    _steps = 0;
    _cursor = 9;
}

unsigned long TransformStates(unsigned long states) {
    states &= ~states >> 1;
    return stateMask & ((states << 2) | (states >> 2) | ((states >> 18) & 1) | ((states & 1) << 18));
}

bool MonkeyRooms::Move() {
    bool stateChanged = false;
    if (_buttonLeft.Clicked()) {
        if (--_cursor < 0) _cursor = 9;
        stateChanged = true;
    }
    if (_buttonRight.Clicked()) {
        unsigned long bit = 2 << (_cursor << 1);
        if (_states & bit) {
            _states &= ~bit;
        }
        else {
            _states |= bit;
            int marked = 0;
            for (unsigned long i = 0, b = 2; i < 10; ++i, b <<= 2) if (_states & b) ++marked;
            if (!TransformStates(_states) || marked == _parameter) Transform();
        }
        stateChanged = true;
    }
    return stateChanged;
}

void MonkeyRooms::Draw() const {
    for (int i = 0; i < 10; ++i) {
        unsigned long color = colors[(_states >> (i << 1)) & 3];
        if (i == _cursor) color |= colorCursor;
        Express.setPixelColor(i, color);
    }
}

void MonkeyRooms::Transform() {
    _states = TransformStates(_states);
    ++_steps;
    if (!_states) Win();
}

void MonkeyRooms::Win() {
    vector<unsigned long> states;
    if (_steps == stepsOptimal[_parameter]) {
        unsigned long state = 0;
        for (int i = 0; i < 7 || !state; ++i) {
            state += random(1, 3);
            states.push_back(1 + state % 3);
        }
    }
    states.push_back(1);
    for (int i = 0; i < 10 * states.size(); ++i) {
        _states &= ~(3 << (_cursor << 1));
        _states |= states[i / 10] << (_cursor << 1);
        if (--_cursor < 0) _cursor = 9;
        Draw();
        delay(25);
    }
    while (_cursor) {
        --_cursor;
        Draw();
        delay(25);
    }
    Reset();
    Draw();
}
