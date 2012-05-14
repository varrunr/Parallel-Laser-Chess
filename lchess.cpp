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
	/* get pieces belonging to player */
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
			if(m1.is_valid() && brd.locIsEmpty(x+1, y))
				moves.push_back(m1);
			
			mv::Move m2('M', 0 , x, y, x -1 , y);
			if(m2.is_valid() && brd.locIsEmpty(x-1, y))
				moves.push_back(m2);
			
			mv::Move m3('M', 0 , x, y, x , y + 1);
			if(m3.is_valid() && brd.locIsEmpty(x, y+1))
				moves.push_back(m3);
			
			mv::Move m4('M', 0 , x, y, x, y - 1);
			if(m4.is_valid() && brd.locIsEmpty(x, y-1))
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
/*		if(cur_pc->canFire())
		{
			mv::Move m7('F', 0 , x , y , 0 , 0 );
			if(m7.is_valid())
				moves.push_back(m7);
		}
*/	}
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

void printMove(mv::Move m1)
{
	std::cout << m1.type << " " << m1.angle << " " \
			  << m1.src_x << " " << m1.src_y << " " \
			  << m1.dst_x << " " << m1.dst_y << std::endl;
}

/*int
Game_Tree_Search(Board &brd1, int depth, int origDepth, int player, int masterPlayer, int value)
{
	Board brd = brd1;
	std::vector< mv::Move > all_moves = get_next_moves(brd, player);

//	std::cout << all_moves.size() << std::endl;
	int worth2 = -1, worth = -1;
	mv::Move good_move1, good_move2;
	int finalVal, currentValue;
	good_move1 = all_moves[0];
	
	for(int i = 0; i < all_moves.size(); i++)
	{
		Board copyBoard = brd;
		worth = copyBoard.make_move(all_moves[i]);
	
		std::vector< mv::Move > all_moves2 = get_next_moves(copyBoard, player);

		for(int j = 0; j < all_moves2.size(); j++)
		{
			Board copyBoard2 = copyBoard;
			worth2 = copyBoard2.make_move(all_moves2[j]);

			if(player == masterPlayer)
				value += worth + worth2;
			else
				value -= worth + worth2;


			int newPlayer = (player == PLAYER2) ? PLAYER1 : PLAYER2 ;

			if(depth != 0)
			{
				currentValue = Game_Tree_Search(copyBoard2, depth-1, depth, newPlayer, masterPlayer, value);				
			}
			else
			{
				return value;
			}

			if(depth == origDepth )
			{
				if(finalVal < currentValue)
				{
					good_move1 = all_moves[i];
					good_move2 = all_moves2[j];
					finalVal = currentValue;
				}
			}
		}
	}

	if(depth == origDepth)
	{
		brd1.make_move(good_move1);
		brd1.make_move(good_move2);
		return 0;
	}
	else
		return currentValue;
}
*/

int n_ply_lookahead(Board brd, int player, int depth, int origDepth , std::vector<mv::Move> &best_mv)
{
	int r=0, k=0, move1score=0, move2score=0 , totalscore = 0;
	//std::cout<<"...\n";
	int bestScore = -10000;
	if(depth == 0)
	{
		return 0;
	}
	else
	{
		std::vector< mv::Move > all_moves1 = get_next_moves(brd, player);
		//std::cout << "All moves 1: " << all_moves.size() << std::endl;
		for(int i = 0; i < all_moves1.size(); i++)
		{
			Board copyBoard = brd;
			if( (r = copyBoard.make_move(all_moves1[i]) ) == -1 )
			{
				continue;
			}
			else
			{
				move1score = r;
			}

			std::vector< mv::Move > all_moves2 = get_next_moves(copyBoard, player);
			//std::cout << "All moves 2: " << all_moves2.size() << std::endl;
			for(int j = 0; j < all_moves2.size(); j++)
			{
				Board copyBoard2 = copyBoard;
				move2score = 0;
				r = 0;
				if( (r = copyBoard2.make_move(all_moves2[j]) ) == -1 )
				{
					continue;
				}
				else
				{
					move2score = r;
				}
				totalscore = move1score + move2score;
				int newPlayer = (player == PLAYER2) ? PLAYER1 : PLAYER2;
				int score = totalscore - n_ply_lookahead(copyBoard2, newPlayer, depth-1, origDepth, best_mv);
				
				if(score > bestScore)
				{
					//std::cout<<"score:"<<score<<" level"<<depth<<std::endl;
					bestScore = score;
					if(depth == origDepth){
					best_mv.clear();
					best_mv.push_back(all_moves1[i]);
					best_mv.push_back(all_moves2[j]);
					}
				}
			}
		}
		return bestScore;
	}	
}

int main(int argc, char *argv[])
{
	Board b;
	int moveCount = 0, tmp , test;
	b.init();
	b.print();

	while(1)
	{
		if(moveCount != 1)
		{	
			mv::Move mv1 = input_move();
			if(mv1.is_valid())
			{
				std::cout<<"Move is valid\n";
				tmp = b.make_move(mv1);
				b.print();
				std::cout<<"Computers Turn now(ok?)\n";
				std::cin>>test;

				if(tmp != -1)
					moveCount++;
			}
			else
				std::cout<<"Move is invalid\n";
		}
		else
		{
			moveCount = 0;
			std::vector<mv::Move> v;
			int lookahead = 2;
			n_ply_lookahead(b, PLAYER2, lookahead, lookahead, v);
			//std::cout<<"Lookahead done "<<v.size()<<"\n";
			//b.print();
			
			if( v.size() == 2)
			{
				printMove(v[0]);
				b.make_move(v[0]);
				b.print();
		
				printMove(v[1]);
				b.make_move(v[1]);
				b.print();
			}
			else std::cout<<"PROBLEM!!!\n";
		}
	}
	return 0;
}
