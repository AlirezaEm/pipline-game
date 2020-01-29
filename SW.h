#ifndef SW_h
#define SW_h
#include "curved.h"
class SW : public curved
{
private:
    
public:
    virtual void rotate();
    int type = 6;
    virtual int pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
    bool water = false;
};
#endif