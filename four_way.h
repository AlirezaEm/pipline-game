#ifndef four_way_h
#define four_way_h
#include "pipe.h"
class four_way : public pipe
{
private:
	int type = 1;
	bool water = false;
public:
   virtual void rotate();
   virtual int pipe_type();
   virtual void set_water_true();
   virtual void set_water_false();
   virtual bool get_water();
};

#endif