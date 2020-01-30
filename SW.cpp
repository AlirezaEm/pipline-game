#include "SW.h"
void SW::rotate()
{
	if (SW::i == 1)
	{
		SW::i = -3;
	}


	SW::type = 7 + SW::i;
	++SW::i;
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