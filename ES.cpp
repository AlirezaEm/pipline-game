#include "ES.h"
void ES::rotate()
{
	if (ES::i == 2)
	{
		ES::i = -2;
	}
	ES::type = 6 + ES::i;
	++ES::i;
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