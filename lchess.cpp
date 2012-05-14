#include<vector>
#include<iostream>
#include "constants.h"
#include "piece.h"
#include "board.h"
#include "move.h"
#include "lchess.h"

std::vector< mv::Move > 
get_next_moves( Board & brd, int player)
{
	std::vector< Piece* > player_pcs = brd.get_pieces(player);
	Piece *cur_pc;
	std::vector< mv::Move > moves;
	for(int i = 0; i < player_pcs.size(); i++)
	{
		cur_pc = player_pcs[i];
		int x = cur_pc->getX();
		int y = cur_pc->getY();

		if(cur_pc->canMove())
		{
			mv::Move m1('M', 0 , x, y, x + 1 , y);
			if(m1.is_valid())
				moves.push_back(m1);
			
			mv::Move m2('M', 0 , x, y, x -1 , y);
			if(m2.is_valid())
				moves.push_back(m2);
			
			mv::Move m3('M', 0 , x, y, x , y + 1);
			if(m3.is_valid())
				moves.push_back(m3);
			
			mv::Move m4('M', 0 , x, y, x, y - 1);
			if(m4.is_valid())
				moves.push_back(m4);
		}
		if(cur_pc->canRotate())
		{
			mv::Move m5('R', 90 , x , y , 0 , 0);
			if(m5.is_valid())
				moves.push_back(m5);

			mv::Move m6('R', -90 , x , y , 0 , 0);
			if(m6.is_valid())
				moves.push_back(m6);
		}
		if(cur_pc->canFire())
		{
			mv::Move m7('F', 0 , x , y , 0 , 0 );
			if(m7.is_valid())
				moves.push_back(m7);
		}
	}
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

mv::Move 
Game_Tree_Search(Board brd, int depth)
{
	std::cout<< "Computer to make the Move !!\n";

}

int main(int argc, char *argv[])
{
	Board b;
	int moveCount = 0;
	b.init();
	b.print();
	while(1)
	{
		if(moveCount != 2)
		{	
			mv::Move mv1 = input_move();
			if(mv1.is_valid())
			{
				moveCount++;
				std::cout<<"Move is valid\n";
				b.make_move(mv1);
				b.print();
			}
			else
				std::cout<<"Move is invalid\n";
		}
		else
		{
			moveCount = 0;
			Game_Tree_Search(b, 1);
		}
	}
	return 0;
}
