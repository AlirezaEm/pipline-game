#ifndef NE_h
#define NE_h
#include "curved.h"
#include <string>

class NE : public curved
{
private:
    
public:
	int i=0;
    int type = 4;
    virtual int pipe_type();
    virtual void rotate();
    virtual void set_water_true();
    virtual void set_water_false();
    virtual bool get_water();
    bool water = false;
  
};
#endif