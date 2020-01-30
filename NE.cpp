#include "NE.h"
void NE::rotate()
{   
	if (NE::i == 3)
	{
		NE::i = -1;
	}


	NE::type = 5 + NE::i;
	++NE::i;
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