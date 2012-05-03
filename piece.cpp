#include <iostream>
#include <vector>
#define MOVE 0
#define ROTATE 1
#define FIRE 2
#include "constants.h"
#include "piece.h"

int
Piece::get_angle()
{
    return this->face_angle;
}

void 
Piece::set_angle( int angle )
{
	this->face_angle = angle;
}

Piece::PieceType
Piece::get_type()
{
	return this->type;
}

void 
Piece::set_type(int ptype)
{
	this->type = (Piece::PieceType) ptype;
}

coordinate
Piece::get_loc()
{
    return this->posn;
}

Piece::Piece(int x , int y , std::vector<int> val_mv , int clr)
{
	this->posn.push_back(x);
	this->posn.push_back(y);	
	this->color = clr;
	this->valid_moves = val_mv;
}

Piece::Piece()
{
	this->type = Piece::Empty;
}

void
Piece::set_valid_moves(int move , int rotate , int fire)
{
	this->valid_moves.push_back(move);
	this->valid_moves.push_back(rotate);
	this->valid_moves.push_back(fire);
}

bool
Piece::canMove()
{
	if( this->valid_moves[MOVE] ) return true;
	return false;
}

bool
Piece::canRotate()
{
	if( this->valid_moves[ROTATE] ) return true;
	return false;
}

bool
Piece::canFire()
{
	if( this->valid_moves[FIRE] ) return true;
	return false;
}
