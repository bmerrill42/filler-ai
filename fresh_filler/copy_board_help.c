#include "filler.h"
char *copy_new_map_into_old(t_board *board, char *first_line)
{
    int y;
    int x;

    y = 0;
    while (y < board->boardheight)
    {
        first_line += 4;
        x = 0;
        while (x < board->boardwidth)
        {
            if (board->board[y][x] != first_line[x])
                board->board[y][x] = first_line[x];
            x += 1;
        }
        y += 1;
        get_next_line(0, &first_line);
    }
    return (first_line);
}
