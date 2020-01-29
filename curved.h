#ifndef curved_h
#define curved_h
#include "pipe.h"
class curved : public pipe
{
private:    
public:
    virtual void rotate()=0;
    virtual int pipe_type()=0;
    virtual void set_water_true()=0;
    virtual bool get_water()=0;
    virtual void set_water_false()=0;
 

};
#endif