#include<iostream>
#include<cstring>
#include<cassert>
#include<vector>
#include "move.h"
#include "constants.h"

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
Move::is_valid_loc(int *loc)
{
	if(	loc[0] < BRD_SZ && loc[1] < BRD_SZ &&
		loc[0] >= 0 && loc[1] >=0)
		return true;

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

Move::Move()
{
	for(int i=0;i<2;i++)
	{
		src_loc[i] = 0;
		dst_loc[i] = 0;
	}
	angle = 0;
}

Move::Move(	char mv_type , int angle , 
			int src_x = 0 , int src_y = 0,
			int dst_x = 0 , int dst_y = 0)
{
	this->type = mv_type;
	this->angle = angle;
	this->src_loc[0] = src_x;
	this->src_loc[1] = src_y;
	this->dst_loc[0] = dst_x;
	this->dst_loc[1] = dst_y;
}

