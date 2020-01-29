#include "NE.h"
void NE::rotate()
{   
    NE::type=5;
}
int NE::pipe_type()
{
    return NE::type;
}
bool NE::get_water()
{
    return NE::water;
}
void NE::set_water_true()
{
    NE::water = true;
}
void NE::set_water_false()
{
    NE::water = false;
}