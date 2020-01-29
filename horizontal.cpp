#include "horizontal.h"
void horizontal::rotate()
{
    horizontal::type = 3;
}
int horizontal::pipe_type()
{
    return horizontal::type;
}
bool horizontal::get_water()
{
    return horizontal::water;
}
void horizontal::set_water_true()
{
    horizontal::water = true;
}
void horizontal::set_water_false()
{
    horizontal::water = false;
}