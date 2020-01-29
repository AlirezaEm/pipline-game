#include "vertical.h"
void vertical::rotate()
{
    vertical::type = 2; 
}
int vertical::pipe_type()
{
    return vertical::type;
}
bool vertical::get_water()
{
    return vertical::water;
}
void vertical::set_water_true()
{
    vertical::water = true;
}
void vertical::set_water_false()
{
    vertical::water = false;
}