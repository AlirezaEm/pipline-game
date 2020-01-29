#ifndef ES_h
#define ES_h
#include "curved.h"

class ES : public curved
{
private:
    
public:
    virtual void rotate();
    int type = 5;
    virtual int pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
    bool water = false;
};
#endif