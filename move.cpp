#include<iostream>
#include<cstring>
#include "move.h"

bool Move::is_valid_move()
{
	return true;
}

bool Move::is_valid_angle()
{
	if(angle == 90 || angle == -90) return true;
	return false;
}

bool Move::is_valid_type()
{
	switch(type)
	{
		case 'M':
			/* Move a piece */
			break;
		case 'R':
			/* Rotate a piece */
			break;
		case 'F':
			/* Fire a laser */
			break;
		default:
			return false;
	}
	return true;
}

bool is_valid_loc(char *loc)
{
	if( strlen(loc) == 2)
	{
		char x = loc[0];
		char y = loc[1];

		bool test = ( x >= 'A' && x <= 'H') &&
					( y >= '1' && y <= '8');
		if(test) return true;
	}
	return false;
}
		
