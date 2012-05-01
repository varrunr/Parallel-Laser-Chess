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

coordinate
Piece::get_loc()
{
    return this->posn;
}
