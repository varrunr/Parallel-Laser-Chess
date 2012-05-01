#include <vector>
#include <iostream>
#include <string>
#include "constants.h"
#include "piece.h"
#include "board.h"

void
Board::destroy(Piece pc)
{
    coordinate posn = pc.get_loc();
    chessboard[posn[0]][posn[1]];
}

std::string 
wrap( Piece::PieceType pc)
{
	switch(pc)
	{
		case Piece::King:
			return "Kng";
		case Piece::Laser:
			return "Lsr";
		case Piece::Hcube:
			return "HCu";
		case Piece::Bsplitter:
			return "Bsp";
		case Piece::Block:
			return "Blk";
		case Piece::StrMirror:
			return "SMi";
		case Piece::TriMirror:
			return "TMi";
		case Piece::Hhole:
			return "Hho";
		default:
			return "ERR";
	};
}

void
Board::print()
{
	for(unsigned int i = 0 ; i < chessboard.size() ; i++)
	{
		for(unsigned int j = 0 ; j < chessboard[i].size() ; i++)
		{
			std::cout<< wrap( chessboard[i][j].get_type() )<<"\t";
		}
	}
}

