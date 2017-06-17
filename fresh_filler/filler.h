#ifndef FILLER_H
#define FILLER_H
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_xypair
{
    int x;
    int y;
} t_xypair;

typedef struct s_movelist
{
    t_xypair position;
    int my_piece_count;
    int opponant_piece_count;
    struct s_movelist *next;
} t_movelist;

typedef struct s_board
{
    char **board;
    int boardwidth;
    int boardheight;
    char playerme;
    char playerop;
    t_xypair current_position;
} t_board;

typedef struct s_piece
{
    int me_count;
	int op_count;
	t_xypair searchboundnw;
	t_xypair searchboundse;
    char **piece;
    int pieceheight;
    int piecewidth;
    t_xypair bound_nw;
    t_xypair bound_se;
    t_movelist *movelist;
} t_piece;

int	check_player_board(char check, char player);
void set_corner(t_piece *piece, t_xypair *corner);
void double_inc(int *a, int *b);
int	overlap_help(t_board *b, t_piece *p,
				 t_xypair *p_xy, t_xypair *o_xy);
int	collision_help(t_board *b, t_piece *p,
				   t_xypair *p_xy, t_xypair *o_xy);
void score_and_add_position(t_board *board, t_piece *piece, int x, int y);
void get_players(t_board *state, char *first_line);
void get_xy_from_str(int *x, int *y, char *line);
char *dup_the_board(t_board *board, char *line);
char *copy_new_map_into_old(t_board *board, char *first_line);
int lowest_y(t_piece *piece);
int lowest_x(t_piece *piece);
int highest_y(t_piece *piece);
int highest_x(t_piece *piece);
char *new_board_matrix(t_board *board, char *first_line);
char *copy_board_matrix(t_board *board, char *first_line);
void new_piece(t_piece *piece, char *line);
void find_bounding(t_piece *piece);
int is_legal(t_board *board, t_piece *piece, int x, int y);
int scan(t_board *board, t_piece *piece, int x, int y);
#endif
