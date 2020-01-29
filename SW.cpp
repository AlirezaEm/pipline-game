#include "SW.h"
void SW::rotate()
{
    SW::type = 7;
}
int SW::pipe_type()
{
    return SW::type;
}
void SW::set_water_true()
{
    SW::water = true;
}
void SW::set_water_false()
{
    SW::water = false;
}
bool SW::get_water()
{
    return SW::water;
}