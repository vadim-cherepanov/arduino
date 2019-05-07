#ifndef _EXPRESSGAME_H_
#define _EXPRESSGAME_H_

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
    virtual bool Break() { return false; };
    virtual bool Move() = 0;
    virtual void Draw() const = 0;
};

#endif // _EXPRESSGAME_H_
