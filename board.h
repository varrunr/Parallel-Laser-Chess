#ifndef __BOARD_H__
#define __BOARD_H__

class Piece;

class Board
{
	public:
	
	    std::vector< coordinate > get_empty_cells();
	    int make_move( mv::Move );
	    int set_piece( Piece );	
	    int get_piece( coordinate );
	    void destroy( Piece );
	    void init();
	    void print();
		int evaluate(int);
		Board& operator = (const Board &src);
		std::vector< Piece* > get_pieces(int player);	
		bool locIsEmpty(int ,int);
	private:
	    std::vector < std::vector< Piece > > chessboard;	/* 2D Array */			
	    Hyper hyperhole;									/* Only 1 hyper hole for a board */

};


void fire( Piece & , Board & , int );

#endif
