#ifndef WN_h
#define WN_h
#include "curved.h"
class WN : public curved
{
private:
	int i = 0;
	int type = 7;
	bool water = false;
public:
    virtual void rotate();
    virtual int  pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
};
#endif