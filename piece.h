#ifndef __PIECE_H__
#define __PIECE_H__

class Board;

class Piece
{
	public:
		enum PieceType
		{
			King,
			Laser,
			Hcube,
			Bsplitter,
			Block,
			StrMirror,
			DiaMirror,
			TriMirror,
			Hhole,
			Empty
		} type;

		void 	    add_move(int , int , int , int);
		void 	    set_angle(int);
		void	    set_type(int);
		void	    set_color(int);
		int	        get_color();
	    coordinate  get_loc();
		PieceType	get_type();
		int 	    get_angle();
		Piece(int , int , TwoDarray , int);
		Piece();
	private:
        
		int face_angle;
		TwoDarray valid_moves;
        int color;
		coordinate posn;
};

class Laser: public Piece
{
	public:
		void fire(Board &);
};
	
class Hyper: public Piece
{
	public:

		coordinate teleport( std::vector< coordinate > );
		
	private:

		int loc;				
		int gen_rand_loc(int,int);
};

class MirrorPiece: public Piece
{
	public:
	
	private:

		int nfaces;				
		std::vector<int> mirrors;

};

class TriangularMirror: public MirrorPiece
{
	public:

	private:
		int mirrorFace; 	
};

class Beamsplitter: public MirrorPiece
{
	public:

	private:
		int nonMirrorFace;
};

#endif
