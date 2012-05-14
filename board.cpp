#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "constants.h"
#include "piece.h"
#include "move.h"
#include "board.h"

Board&
Board::operator = (const Board &src)
{
	this->chessboard = src.chessboard;
	return *this;
}

void
Board::destroy(Piece pc)
{
    coordinate posn = pc.get_loc();
    chessboard[posn[0]][posn[1]];
}

bool 
Board::locIsEmpty(int x, int y)
{
	if((&this->chessboard[x][y])->get_type() == Piece::Empty)
		return true;
	return false;
}

std::vector< Piece* >
Board::get_pieces(int player)
{
	Piece *cur_pc;
	std::vector< Piece* > pc_list;
	for(int i = 0;i<this->chessboard.size();i++)
	{
		for(int j = 0;j<this->chessboard[i].size();j++)
		{
			cur_pc = &(this->chessboard[i][j]);
			if(cur_pc->get_color() == player)
			{
				pc_list.push_back(cur_pc);
			}
		}
	}
	return pc_list;
}
				
void swap_pc(Piece *pc1 , Piece *pc2)
{
	Piece *tmp = pc1;
	pc1 = pc2;
	pc2 = tmp;
}

int get_value(Piece::PieceType pc)
{
	switch(pc)
	{
		case Piece::King:
			return KING;	
		case Piece::Laser:
			return LASER;
		case Piece::Hcube:
			return 0;
		case Piece::Bsplitter:
			return BMSPLTR;
		case Piece::DiaMirror:
			return MIRR;
		case Piece::Block:
			return BLK;
		case Piece::StrMirror:
			return MIRR; 
		case Piece::TriMirror:
			return TRMIRR;
		case Piece::Hhole:
			return 0;
		case Piece::Empty:
			return 0; 
	}
}

int
Board::make_move(mv::Move m)
{
	Piece *src_pc , *dst_pc;
	int src_clr , dst_clr;
	
	switch(m.type)
	{
		case 'M':
		{
			src_pc = &(this->chessboard[m.src_x][m.src_y]); 
			dst_pc = &(this->chessboard[m.dst_x][m.dst_y]);
	
			src_clr = src_pc->get_color();
			dst_clr = dst_pc->get_color();

			if(src_clr != dst_clr)
			{
				int value = 0;
				if(dst_pc->get_type() == Piece::Empty)
				{
//					std::cout<<" Moving from "<<m.src_x<<","<<m.src_y<< \
							   " to an empty place at "<<m.dst_x<<","<<m.dst_y<<"\n";
					value = 0;
				}
				else{
					value = get_value(dst_pc->get_type());
				}
				dst_pc->set_type( src_pc->get_type() );
				dst_pc->set_color( src_pc->get_color() );
				dst_pc->set_valid_moves( src_pc->get_valid_moves() );
				dst_pc->set_angle( src_pc->get_angle());
				src_pc->destroy();	
				return value;
			}
			else
			{
				if( src_clr == dst_clr) {
//					std::cout<<"Cannot make move\n";
				}
				return -1;
			}
			break;
		}	
		case 'R':
		{
			src_pc = &(this->chessboard[m.src_x][m.src_y]);
			int new_angle = src_pc->get_angle();
			if(new_angle == 0 && m.angle == -90)
			{
				new_angle = 270;
			}
			else
			{
				new_angle = ( new_angle + m.angle ) % 360;
			}
			src_pc->set_angle(new_angle);	
			break;
		}
		case 'F':
		{
			fire( *src_pc , *this , m.angle);
			return 1;
			break;
		}
		default: return -1;
	}
	return -1;
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

std::string
wrap_angle(int angle)
{
	switch(angle)
	{
		case 0:
			return " 0 ";
		case 90:
			return " 90";
		case 180:
			return "180";
		case 270:
			return "270";
		default:
			return "   ";
	}
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
	bool angle = true;	
	print_line('-', 46 , '-', true);
	std::cout<<"    ";
	for(int i = 0;i < this->chessboard.size();i++)
	{
		std::cout<<"    "<<i<<"     ";
	}std::cout<<"\n";
		
	for(unsigned int i = 0 ; i < this->chessboard.size() ; i++)
	{
		std::cout<< get_chr(i)<<" | "; 
		for(unsigned int j = 0 ; j < this->chessboard[i].size() ; j++)
		{
			std::cout<< "|"<< wrap( this->chessboard[i][j].get_type() );
			if(angle)
				std::cout<< "," << wrap_angle(this->chessboard[i][j].get_angle()); 
			std::cout<<"| ";
		}
		std::cout<<std::endl;
	}
	print_line('-', 49 , '-', true);
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
					cur_pc->set_loc(i,j);
					// Tentative
					if( i == 0 || i == 1) cur_pc->set_color(PLAYER1);
					if( i == BRD_SZ -2 || i == BRD_SZ - 1) cur_pc->set_color(PLAYER2);

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

void 
fire( Piece &laser , Board &board , int angle)
{
	bool x_dir , y_dir; 
	Piece pc;
	if( angle == 90 || angle == 270 )
	{
		// Iterate in x direction
		// pc = first non null entry
        x_dir = true;
	}
	else
	{
		// Iterate in y direction
		// pc = first non null entry
		y_dir = true;
	}	
	if(x_dir == false && y_dir == false)
    {
		// Out of bounds 
        return;
	}

    int face_angle = pc.get_angle();
    int new_angle = 0;
	
	switch (pc.type)
	{
		case Piece::DiaMirror:
	    {		
			if(x_dir)
			{
				if(face_angle  == 0 || face_angle == 180)
				{
					if(angle == 270) new_angle = 0;      // +y 
					if(angle == 90)  new_angle = 180;    // -y
				}
				if(face_angle == 90 || face_angle == 270)
				{
					if(angle == 270) new_angle = 180;   // -y
					if(angle == 90)  new_angle = 0 ;    // +y
				}
			}
			if(y_dir)
			{
				if(face_angle == 0 || face_angle == 180)
				{
					if(angle == 0)   new_angle = 90 ;   // -x
					if(angle == 180) new_angle = 270;   // +x
				}
				if(face_angle == 90 || face_angle == 270)
				{
					if(angle == 0)   new_angle = 270;   // +x
					if(angle == 180) new_angle = 90;    //  -x
				}
			}
			fire(pc , board, new_angle);
			break;
    	}
        case Piece::StrMirror:
        {
			if( angle == 90 || angle == 270)
		    {
			    new_angle = 360 - face_angle;
		    }
		    else 
            {
                new_angle = 180 - face_angle;
		    }
		    fire( pc, board, new_angle);
	        break;
        }
        case Piece::TriMirror:
        {
			if(x_dir)
			{
				if(face_angle == 0)
				{
					if(angle == 270) new_angle = 0; // +y 
					if(angle == 90) 
                    {
                        board.destroy(pc);
                        return;
                    }
				}

				if(face_angle == 180 )
				{
					if(angle == 270) 
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 90) new_angle = 180; // -y
				}

				if( face_angle == 90)
				{
					if(angle == 270) new_angle = 180;
					if(angle == 90 ) 
                    {
                        board.destroy(pc);
                        return;
                    }
                }
				
				if(face_angle == 270)
				{
					if(angle == 270)
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 90) new_angle = 0;
				}
				fire(pc , board , new_angle);

			}

			if(y_dir)
			{
				if(face_angle == 0)
				{
					if(angle == 0) new_angle = 90; // -x 
					if(angle == 180)
                    {
                        board.destroy(pc);
                        return;
                    }
				}

				if(face_angle == 180 )
				{
					if(angle == 0)
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 180) new_angle = 270; // +x
				}

				if(face_angle == 90)
				{
					if(angle == 180) new_angle = 90;
					if(angle == 0 )
                    {
                        board.destroy(pc);
                        return;
                    }
				}

				if(face_angle == 270)
				{
					if(angle == 180)
                    {
                        board.destroy(pc);
                        return;
                    }
					if(angle == 0) new_angle = 270;
				}
				fire(pc , board , new_angle);
			}
            break;
		}
        case Piece::Block:
		{
			if( (angle - face_angle) == 180) 
                new_angle = face_angle;
			else
            {
                board.destroy(pc);
                return;
            }
			fire(pc , board , new_angle);
            break;
		}
        case Piece::King:
		{
			board.destroy(pc);
            return;
		}
        case Piece::Hcube:
		{
			break;
		}
        case Piece::Hhole:
        {
            break;
        }
        case Piece::Bsplitter:
		{
			if(face_angle == angle) 
            {
                board.destroy(pc);
            }
			if(face_angle == 0 || face_angle == 180)
			{
				new_angle = face_angle;
				fire(pc , board , new_angle);
			}
			else
			{
				int new_angle1 = (angle - 90) % 360;
				int new_angle2 = (angle + 90) % 360;
				fire(pc , board , new_angle1);
				fire(pc , board , new_angle2);
			}
            break;
		}
	}
}
