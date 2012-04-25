#include <vector>
#include <iostream>
#include "constants.h"
#include "piece.h"
#include "board.h"

void
Board::destroy(Piece pc)
{
    coordinate posn = pc.get_loc();
    chessboard[posn[0]][posn[1]];
}


