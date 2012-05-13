#include <iostream>
#include <vector>
#define MOVE 0
#define ROTATE 1
#define FIRE 2
#include "constants.h"
#include "piece.h"

void
Piece::destroy()
{
	this->type = Piece::Empty;
	this->posn[0] = (-1); // x coord
	this->posn[1] = (-1); // y coord
}

int 
Piece::getX()
{
	return this->posn[0];
}

int
Piece::getY()
{
	return this->posn[1];
}

void
Piece::destroy(Piece src)
{
	//dst_pc->type = (Piece::PieceType) src_pc.;
	//dst_pc->color( src_pc->get_color() );
	// TODO: set valid moves
	//dst_pc->set_valid_moves( src_pc->get_valid_moves() );
	//dst_pc->set_angle( src_pc->get_angle());


}

int
Piece::get_angle()
{
    return this->face_angle;
}

void 
Piece::set_valid_moves(std::vector<int> val_mv)
{
	this->valid_moves = val_mv;
}
void 
Piece::set_angle( int angle )
{
	this->face_angle = angle;
}

void
Piece::set_color( int clr )
{
	this->color = clr;
}

int
Piece::get_color()
{
	return this->color;
}

Piece::PieceType
Piece::get_type()
{
	return this->type;
}


std::vector<int>
Piece::get_valid_moves()
{
	return this->valid_moves;
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

void
Piece::set_loc(int x, int y)
{
	if(posn.size() == 2){
		posn[0] = x;
		posn[1] = y;
	}
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
	this->posn.push_back(-1); // x coord
	this->posn.push_back(-1); // y coord
	this->color = 0;
	this->face_angle = -1;
}

Piece&
Piece::operator = (const Piece &src)
{
	this->face_angle = src.face_angle;
	this->valid_moves = src.valid_moves;
	this->color = src.color;
	this->posn = src.posn;
	return *this;
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

std::vector< mv::Move >
Piece::get_moves( Board &brd)
{
	//std::vector< Move > moves;

	// TODO:

	//return moves;
}
