/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 02:35:38 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 02:38:06 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "libft.h"

void	init_my_colors(void)
{
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_CYAN, COLOR_CYAN);
	init_pair(4, COLOR_GREEN, COLOR_GREEN);
	init_color(COLOR_CYAN, 150, 150, 150);
}

void	place_colored_char(char a, int n)
{
	attron(COLOR_PAIR(n));
	addch(a);
	attroff(COLOR_PAIR(n));
}

void	line_work(char *line, int *i)
{
	while (line[*i] != '\0')
	{
		if (line[*i] == 'o' || line[*i] == 'x')
			place_colored_char(line[*i], 4);
		else if (line[*i] == 'O')
			place_colored_char(line[*i], 1);
		else if (line[*i] == 'X')
			place_colored_char(line[*i], 2);
		else if (line[*i] == '.')
			place_colored_char(line[*i], 3);
		else
			addch(line[*i]);
		if (line[0] == '<')
		{
			refresh();
			break ;
		}
		(*i)++;
	}
}

int		main(void)
{
	char	*line;
	int		fp;
	int		i;

	i = 0;
	line = NULL;
	initscr();
	while (get_next_line(0, &line))
	{
		start_color();
		init_my_colors();
		if (line[0] == '0' || (line[0] == 'P' && line[1] != 'i') ||
			line[0] == ' ' || line[0] == '<')
		{
			line_work(line, &i);
			if (line[0] == '<')
				mvaddch(0, 0, ' ');
			addch('\n');
			i = 0;
		}
	}
	sleep(2);
	endwin();
	return (0);
}

/* Local Variables: */
/* compile-command: "gcc -g visualizer.c -L libft/ -lft -lncurses" */
/* End: */
