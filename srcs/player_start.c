/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:46:14 by nabih             #+#    #+#             */
/*   Updated: 2019/11/12 12:56:04 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				get_space(t_player *p)
{
	int			i;

	i = 0;
	while (p->plateau[0][i] == ' ' && p->plateau[0][i] != '\0')
		i++;
	p->space = i;
	return (0);
}

void			get_start_check(t_player *p, int x, int y)
{
	char		c;
	char		op;

	c = (p->order == 1) ? 'O' : 'X';
	op = (p->order == 1) ? 'X' : 'O';
	if ((p->plateau)[y][x] == c || (p->plateau)[y][x] == c)
	{
		p->y_start = y;
		p->x_start = x;
	}
	if ((p->plateau)[y][x] == op || (p->plateau)[y][x] == op)
	{
		p->y_op_st = y;
		p->x_op_st = x;
	}
}

int				get_start(t_player *p)
{
	int			x;
	int			y;

	y = 1;
	while (y < p->y_plat + 1)
	{
		x = p->space;
		while (x < (p->x_plat + p->space) && (p->plateau)[y][x] != '\0')
		{
			get_start_check(p, x, y);
			x++;
		}
		y++;
	}
	if (p->y_start == -1 || p->x_start == -1)
		return (-1);
	return (0);
}
