#include<iostream>
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
