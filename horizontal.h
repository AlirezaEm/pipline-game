#include "flat.h"
#ifndef horizontal_h
#define horizontal_h
class horizontal : public flat
{
private:
	int i = 0;
	int type = 2;
	bool water = false;
public:
    virtual void rotate();
    virtual int pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
};
#endif