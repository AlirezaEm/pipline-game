#ifndef four_way_h
#define four_way_h
#include "pipe.h"
class four_way : public pipe
{
private:
    
public:
   virtual void rotate();
   int type =1;
   virtual int pipe_type();
   virtual void set_water_true();
   virtual void set_water_false();
   virtual bool get_water();
   bool water = false;
 

};

#endif