#include "vertical.h"
void vertical::rotate()
{
	if (vertical::i > 1)
	{
		vertical::i = 0;
	}
	vertical::type = 2 + vertical::i; 
	i++;
	
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