#include "flat.h"
#ifndef horizontal_h
#define horizontal_h
class horizontal : public flat
{
private:
public:
    int type = 2;
    virtual void rotate();
    virtual int pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
    bool water = false;
};
#endif