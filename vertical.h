#include "flat.h"
#ifndef vertical_h
#define vertical_h
class vertical : public flat
{
private:
public:
    int type = 3;
    virtual void rotate();
    virtual int pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
    bool water = false;
};
#endif