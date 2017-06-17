/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_board_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 07:28:41 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/17 02:45:38 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void get_players(t_board *state, char *first_line)
{
    int i;

    i = 0;
    while (first_line[i++] != 'p')
        ;
    if (first_line[i] == '1')
    {
        state->playerop = 'X';
        state->playerme = 'O';
    }
    else
    {
        state->playerop = 'O';
        state->playerme = 'X';
    }
    free(first_line);
}

void get_xy_from_str(int *x, int *y, char *line)
{
    int i;

    i = 0;
    while (!ft_isdigit(line[i]))
        i += 1;
    *y = ft_atoi(line + i);
    while (ft_isdigit(line[i]))
        i += 1;
    *x = ft_atoi(line + i);
}

char *dup_the_board(t_board *board, char *line)
{
    int y;

    y = 0;
    board->board = (char**)malloc(board->boardheight * sizeof(char*));
    while (y < board->boardheight)
    {
        line += 4;
        board->board[y] = ft_strdup(line);
        get_next_line(0, &line);
        y += 1;
    }
    return (line);
}
