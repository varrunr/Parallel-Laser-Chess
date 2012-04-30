#include<iostream>
#include<cstring>
#include<cassert>
#include "move.h"

bool 
Move::is_valid_angle()
{
	if(angle == 90 || angle == -90) return true;
	return false;
}

bool 
Move::is_valid_type()
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

bool 
Move::is_valid_loc(char *loc)
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

bool 
Move::is_valid()
{
	assert( this->is_valid_type() );
	switch(type)
	{
		case 'M':
			assert( this->is_valid_loc(src_loc) );
			assert( this->is_valid_loc(dst_loc) );
			/* TODO: Check if src_loc has a piece */
			break;
		case 'R':
			assert( this->is_valid_angle() );
			/* TODO: Check if dst_loc has a piece */
			break;
		case 'F':
			/* TODO: Make sure piece at src_loc is a laser */
			break;
	}
	return true;
}
