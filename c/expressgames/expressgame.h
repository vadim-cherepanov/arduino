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
    int GetParameterMin() const { return _parameterMin; }
    int GetParameterMax() const { return _parameterMax; }
    int GetParameter() const { return _parameter; }
    virtual void SetParameter(int parameter) { _parameter = parameter; Reset(); }
    virtual void Reset() = 0;
    virtual bool Break() { return false; };
    virtual bool Move() = 0;
    virtual void Draw() const = 0;
};

#endif // _EXPRESSGAME_H_
