#include <vector>
#include <iostream>
#include <string>
#include <fstream>
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
	std::string ptype;
	switch(pc)
	{
		case Piece::King:
			ptype = "Kng";
			break;
		case Piece::Laser:
			ptype = "Lsr";
			break;
		case Piece::Hcube:
			ptype = "Hcu";
			break;
		case Piece::Bsplitter:
			ptype = "Bsp";
			break;
		case Piece::DiaMirror:
			ptype = "DMi";
			break;
		case Piece::Block:
			ptype = "Blk";
			break;
		case Piece::StrMirror:
			ptype = "SMi";
			break;
		case Piece::TriMirror:
			ptype = "TMi";
			break;
		case Piece::Hhole:
			ptype = "Hho";
			break;
		case Piece::Empty:
			ptype = "   ";
			break;
		default:
			ptype = "ERR";
			break;
	};
	return ptype;
}

char get_chr(int i)
{
	return (char) (i + 65);
}

void print_line(char c , int n_line , char sep, bool end)
{
	for(int i=0;i<n_line;i++)
		std::cout<< c << sep;
	
	if(end)
		std::cout<<std::endl;
}

void
Board::print()
{
	bool angle = false;	
	print_line('-', 29 , '-', true);
	for(unsigned int i = 0 ; i < this->chessboard.size() ; i++)
	{
		std::cout<< get_chr(i)<<" | "; 
		for(unsigned int j = 0 ; j < this->chessboard[i].size() ; j++)
		{
			std::cout<< "|"<< wrap( this->chessboard[i][j].get_type() );
			if(angle)
				std::cout<< "," << this->chessboard[i][j].get_angle(); 
			std::cout<<"| ";
		}
		std::cout<<std::endl;
	}
	print_line('-', 29 , '-', true);
}

void
Board::init()
{
	/* Define valid moves for the different pieces here */
	std::ifstream f_mov("VALID_MOVES");
		
	for(int i = 0; i < BRD_SZ ; i++)
	{
		std::vector<Piece> temp;
		for(int j = 0; j< BRD_SZ ; j++)
		{
			temp.push_back(Piece());
		}
		this->chessboard.push_back(temp);
	}

	/* Read initial board state from file */
	std::ifstream f_brd("INIT_BOARD");
	int ptype , angle , color;
	Piece *cur_pc;
	if( f_brd.is_open() )
	{
		for(int i = 0; i < BRD_SZ ; i++)
		{
			for(int j = 0; j < BRD_SZ ; j++)
			{
				f_brd >> ptype >> angle;
				cur_pc = &(this->chessboard[i][j]);
				if(ptype != -1)
				{				
					cur_pc->set_type(ptype);
					cur_pc->set_angle(angle);
					
					switch(ptype)
					{
						case Piece::King:
							cur_pc->set_valid_moves(1 , 0 , 0);
							break;
						case Piece::Laser:
							cur_pc->set_valid_moves(1 , 1 , 1);
							break;
						case Piece::Hcube:
							cur_pc->set_valid_moves(1 , 0 , 0);
							break;
						case Piece::Bsplitter:
							cur_pc->set_valid_moves(1 , 1 , 0);
							break;
						case Piece::DiaMirror:
							cur_pc->set_valid_moves(1 , 1 , 0);
							break;
						case Piece::Block:
							cur_pc->set_valid_moves(1 , 1 , 0);
							break;
						case Piece::StrMirror:
							cur_pc->set_valid_moves(1 , 1 , 0);
							break;
						case Piece::TriMirror:
							cur_pc->set_valid_moves(1 , 1 , 0);
							break;
						case Piece::Hhole:
							cur_pc->set_valid_moves(0 , 0 , 0);
							break;
						case Piece::Empty:
							break;
						default:
							break;
					};	
				}
			}
		}
	}
	f_brd.close();
}
