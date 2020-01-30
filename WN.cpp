#include "WN.h"
void WN::rotate()
{
	if (WN::i == 4)
	{

		WN::i = 0;
	}


	WN::type = 4 + WN::i;
	++WN::i;
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