#ifndef __PIECE_H__
#define __PIECE_H__
#define coordinate std::vector<int>

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
			Hhole
		} type;

		void 	    set_angle(int);
		int 	    get_angle();
		void 	    add_move(int , int , int , int);
		void	    set_type(int);
		//pt   get_type();
		void	    set_color(int);
		int	        get_color();
	    coordinate  get_loc();	
	private:

	    /* e.g. 45, 90, 135 (0..360) */
		int face_angle;	
	    /* e.g  +1,-1, +90, -90 */
		std::vector< std::vector<int> > valid_moves;
        
		/* e.g. "green" or "red	*/	
		int color;
		/* Coordinates */
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
		int gen_rand_loc(int,int); 	/* Generate Random location to teleport */
};

class MirrorPiece: public Piece
{
	public:
	
	private:

		int nfaces;					/* 1,2,3,4 */
		std::vector<int> mirrors; 	/* If a face has a mirror 0 else 1 
									 e.g. {0,1,0,1} */
};

class TriangularMirror: public MirrorPiece
{
	public:

	private:
		int mirrorFace; 		/* Which side of triangle has the mirror */
};

class Beamsplitter: public MirrorPiece
{
	public:

	private:
		int nonMirrorFace; 		/* Which side of beam splitter doesnt have the mirror */
};

#endif
