#include "ES.h"
void ES::rotate()
{
    ES::type = 6;
}
int ES::pipe_type()
{
    return ES::type;
}
void ES::set_water_true()
{
    ES::water = true;
}
bool ES::get_water()
{
    return ES::water;
}
void ES::set_water_false()
{
    ES::water = false;
}