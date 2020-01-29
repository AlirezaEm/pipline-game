#include "WN.h"
void WN::rotate()
{
    WN::type = 4;
}
int WN::pipe_type()
{
    return WN::type;
}
bool WN::get_water()
{
    return WN::water;
}
void WN::set_water_true()
{
    WN::water = true;
}
void WN::set_water_false()
{
    WN::water = false;
}