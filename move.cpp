#include<iostream>
#include<cstring>
#include<cassert>
#include<vector>
#include<cmath>
#include "move.h"
#include "constants.h"

using namespace mv;

bool 
Move::is_valid_angle()
{
	if(angle == 90 || angle == -90) return true;
	return false;
}

Move& 
Move::operator = (const Move &src)
{
	this->src_x = src.src_x;
	this->dst_x = src.dst_x;
	this->src_y = src.src_y;
	this->dst_y = src.dst_y;
	this->type = src.type;
	this->angle = src.angle;	
	return *this;
}

void
Move::print()
{
	switch(type)
	{
		case 'M':
			std::cout<<"Move "<<this->src_x<<" "<<this->src_y<<" to "<<
					this->dst_x<<this->dst_y<<std::endl;
			break;
		case 'R':
			std::cout<<"Rotate "<<this->angle<<std::endl;
			break;
		case 'F':
			std::cout<<"Fire laser"<<std::endl;
			break;
	}
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
		y < BRD_SZ &&
		x >= 0 && y >=0) return true;

	return false;
}

bool 
Move::loc_is_valid()
{
	int a = std::abs(this->src_x - this->dst_x);
	int b = std::abs(this->src_y - this->dst_y);

	return ( ((a == 1 && b == 0) ||(a == 0 && b == 1)) &&
			 valid_loc(this->src_x , this->src_y) && 
			 valid_loc(this->dst_x , this->dst_y) );
}

bool 
Move::is_valid()
{
	if( !(this->is_valid_type()) )
		return false;

	switch(type)
	{
		case 'M':
			return ( this->loc_is_valid() );
		case 'R':
			return ( this->is_valid_angle() &&
					 valid_loc( this->src_x,
						 		this->src_y));
		case 'F':
			/* TODO: Make sure piece at src_loc is a laser */
			break;
		default:
			return false;
	}
	return true;
}

Move::Move()
{
	this->src_x = 0;
	this->src_y = 0;
	this->angle = 0;
	this->type = '-';
}

Move::Move(	char mv_type , int angle, 
			int s_x  , int s_y,
			int d_x, int d_y)
{
	this->type = mv_type;
	this->angle = angle;
	this->src_x = s_x;
	this->src_y = s_y;
	this->dst_x = d_x;
	this->dst_y = d_y;
}
