#ifndef __LCHESS_H__
#define __LCHESS_H__

namespace lchess
{
	/* Function prototypes */
	void fire( Piece& , Board& , int );
	std::vector< mv::Move > get_next_moves( Board & , Piece& , int);
}

#endif
