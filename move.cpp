#include<iostream>
#include<cstring>
#include<cassert>
#include<vector>
#include "move.h"
#include "constants.h"

using namespace mv;

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
valid_loc(int x , int y)
{
	if(	x < BRD_SZ && 
		x < BRD_SZ &&
		x >= 0 && y >=0) return true;

	return false;
}

bool 
Move::loc_is_valid()
{
	return ( valid_loc(this->src_x , this->src_y) && 
			 valid_loc(this->dst_x , this->dst_y) );
}

bool 
Move::is_valid()
{
	assert( this->is_valid_type() );
	switch(type)
	{
		case 'M':
			assert( this->loc_is_valid() );
			break;
		case 'R':
			assert( this->is_valid_angle() );
			break;
		case 'F':
			/* TODO: Make sure piece at src_loc is a laser */
			break;
	}
	return true;
}

Move::Move()
{
	this->src_x = 0;
	this->src_y = 0;
	this->angle = 0;
}

Move::Move(	char mv_type , int angle , 
			int s_x = 0 , int s_y = 0,
			int d_x = 0 , int d_y = 0)
{
	this->type = mv_type;
	this->angle = angle;
	this->src_x = s_x;
	this->src_y = s_y;
	this->dst_x = d_x;
	this->dst_y = d_y;
}

