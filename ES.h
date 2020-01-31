#ifndef ES_h
#define ES_h
#include "curved.h"

class ES : public curved
{
private:
	int i = 0;
	int type = 5;
	bool water = false;
public:
    virtual void rotate();
    virtual int pipe_type();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
};
#endif