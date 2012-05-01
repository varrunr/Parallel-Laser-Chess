#ifndef __BOARD_H__
#define __BOARD_H__

class Piece;

class Board
{
	public:
	
	    std::vector< coordinate > get_empty_cells();
	    int move_piece( Piece, coordinate );
	    int set_piece( Piece );	
	    int get_piece( coordinate );
	    void destroy( Piece );
	    void init();
	    void print();
	
	private:
	    std::vector < std::vector< Piece > > chessboard;	/* 2D Array */			
	    Hyper hyperhole;									/* Only 1 hyper hole for a board */

};

#endif
