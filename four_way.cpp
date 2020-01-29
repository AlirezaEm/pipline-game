#include "four_way.h"
void four_way::rotate(){}
int four_way::pipe_type()
{
    return four_way::type;
}
void four_way::set_water_true()
{
    four_way::water = true;
}
bool four_way::get_water()
{
    return four_way::water;
}
void four_way::set_water_false()
{
    four_way::water = false;
}