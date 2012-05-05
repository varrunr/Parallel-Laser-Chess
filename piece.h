#ifndef __PIECE_H__
#define __PIECE_H__

class Board;

namespace mv{

	class Move;
};

class Piece
{
	public:
		enum PieceType
		{
			King = 0,
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

		/* Setters and getters */
		void 	    add_move(int , int , int , int);
		void 	    set_angle(int);
		void	    set_type(int);
		void	    set_color(int);
		void		set_valid_moves(int , int , int);
		int	        get_color();
	    coordinate  get_loc();
		PieceType	get_type();
		int 	    get_angle();

		/* Function prototypes */
		bool		canMove();
		bool		canFire();
		bool		canRotate();
		std::vector< mv::Move > get_moves(Board &);

		/* Constructors */
		Piece(int , int , std::vector<int> , int);
		Piece();
		
		/* Copy constructor */
		Piece& operator = (const Piece&);

	private:
        /* Class members */
		int face_angle;
		std::vector<int> valid_moves;
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
