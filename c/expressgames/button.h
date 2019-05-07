#ifndef _BUTTON_H_
#define _BUTTON_H_

class Button {
private:
    bool _right;
    bool _down;
    int _state;
    unsigned long _timeDelays[3];
    unsigned long _timeLastClick;
public:
    explicit Button(bool right, unsigned long timeMinimum = 150ul, unsigned long timeRepeatDelay = 750ul, unsigned long timeRepeatRate = 10); 
    bool Clicked(); 
    bool Down() const { return _state > 0; }
};

#endif // _BUTTON_H_
