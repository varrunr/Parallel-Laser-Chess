#include "piece.h"

int
Piece::get_angle()
{
    return this->face_angle;
}

coordinate
Piece::get_loc()
{
    return posn;
}
