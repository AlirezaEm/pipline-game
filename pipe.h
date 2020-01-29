#ifndef pipe_h
#define pipe_h
class pipe
{
private:
    
public:
    virtual int pipe_type()=0;
    virtual void rotate()=0;
    virtual void set_water_true()=0;
    virtual void set_water_false()=0;
    virtual bool get_water()=0;
 
};
#endif