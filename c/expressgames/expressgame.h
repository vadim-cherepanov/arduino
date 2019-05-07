#ifndef _EXPRESSGAME_H_
#define _EXPRESSGAME_H_

#include <functional>

using namespace std;

class ExpressGame {
protected:
    int _parameterMin;
    int _parameterMax;
    int _parameter;
public:
    explicit ExpressGame(int parameterMin, int parameterMax) : 
            _parameterMin(parameterMin), _parameterMax(parameterMax), 
            _parameter(parameterMin) {}
    int GetParameter() const { return _parameter; }
    virtual void NextParameter() { if (++_parameter > _parameterMax) _parameter = _parameterMin; Reset(); }
    virtual void Reset() = 0;
    virtual void Loop(function<bool()> Break) { while (!Break()) if (Move()) Draw(); }
    virtual bool Move() = 0;
    virtual void Draw() const = 0;
};

#endif // _EXPRESSGAME_H_
