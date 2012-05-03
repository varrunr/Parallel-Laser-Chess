#include <iostream>
#include <vector>
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
Piece::set_type(int typ)
{
	this->type = (Piece::PieceType) type;
}

coordinate
Piece::get_loc()
{
    return this->posn;
}

Piece::Piece(int x , int y , TwoDarray val_mv , int clr)
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
