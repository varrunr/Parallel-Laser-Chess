#include<vector>
#include<iostream>
#include "constants.h"
#include "piece.h"
#include "board.h"
#include "move.h"
#include "lchess.h"

std::vector< mv::Move > 
get_next_moves( Board & brd , Piece& pc , int player = 0)
{
	std::vector< mv::Move > moves;
	
	/* 
	   For every piece of player on board
			if color == player
	   			pc_moves = Piece.get_moves(brd);
				for i in pc_moves
					moves.push_back(pc_moves[i]);
		TODO: 1. Define Piece::get_moves(Board&);
			  2. Define Player class
	*/
	
	return moves;
}




mv::Move 
input_move()
{
	int s1 = 0, s2 =0 ;
	int d1 = 0, d2 =0 ;
	char type; 
	int angle = 0;

	std::cin>>type;
	switch(type)
	{
		case 'M':
			std::cin>>s1>>s2>>d1>>d2;
			break;
		case 'R':
			std::cin>>angle>>s1>>s2;
			break;
		case 'F':
			break;
	}
	return mv::Move(type , angle , s1 , s2 , d1 , d2);
}

int main(int argc, char *argv[])
{
	Board b;
	b.init();
	b.print();
	while(1)
	{
		mv::Move mv1 = input_move();
		if(mv1.is_valid())
		{
			std::cout<<"Move is valid\n";
			b.make_move(mv1);
			b.print();
		}
		else
			std::cout<<"Move is invalid\n";
	}
	return 0;
}
