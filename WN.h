#ifndef WN_h
#define WN_h
#include "curved.h"
class WN : public curved
{
private:
    
public:
	int i = 0;
    virtual void rotate();
    int type = 7;
    virtual int  pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
    bool water = false;

};
#endif