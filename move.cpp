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
