#ifndef __LCHESS_H__
#define __LCHESS_H__

class Piece
{
	public:
				
	private:

		int face_angle;  				/* e.g 	45, 90, 135 (0..360) 	*/
		std::vector<int> valid_moves; 	/* e.g  +1,-1, +90, -90 	 	*/
		int type;						/* e.g. "King","Block"			*/
		int color;						/* e.g. "green" or "red			*/
};

class Hyper: public Piece
{
	public:
	
	private:
		int loc;				
		void gen_rand_loc(Piece); 	/* Generate Random location to teleport */
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

class Board
{
	public:

	private:
		std::vector < std::vector< Piece > > chessboard;	/* 2D Array */
		Hyper hyperhole;									/* Only 1 hyper hole for a board */
};

#endif
