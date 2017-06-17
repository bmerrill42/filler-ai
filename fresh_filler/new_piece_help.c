#include "filler.h"

void find_bounding(t_piece *piece)
{
    piece->bound_nw.y = lowest_y(piece);
    piece->bound_nw.x = lowest_x(piece);
    piece->bound_se.y = highest_y(piece);
    piece->bound_se.x = highest_x(piece);
}
