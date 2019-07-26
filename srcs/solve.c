/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:19:37 by nabih             #+#    #+#             */
/*   Updated: 2019/07/26 09:08:05 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void		init_solve(t_solve *s, t_player *p)
{
	s->x = (p->x_start - p->x_piec > p->space) ? (p->x_start - p->x_piec + 1) : p->x_start;
	s->y = (p->y_start - p->y_piec > 1) ? (p->y_start - p->y_piec + 1) : p->y_start;
}

int				check_contact(t_player *p, int x, int y)
{
	int		i;
	int		j;
	char	c;
	char	op;
	int		contact;

	i = 0;
	contact = 0;
	c = (p->order == 1) ? 'O' : 'X';
	op = (c == 'O') ? 'X' : 'O';
	while (i < p->y_piec && (y + i) < (p->y_plat + 1))
	{
		j = 0;
		while (p->piece[i][j] && j < p->x_piec)
		{
			if ((p->piece)[i][j] == '*'
				&& ((x + j) >= (p->x_plat + p->space)
				|| (y + i) >= (p->y_plat + 1)))
				return (-1);
			if ((p->piece)[i][j] == '*'
				&& ((p->plateau)[y + i][x + j] == c))
				contact += 1;
			if ((p->piece)[i][j] == '*'
				&& ((p->plateau)[y + i][x + j] == op))
				return (0);
			j++;
		}
		i++;
	}
	/* if (p->piece[i - 1][j] != '\0') */
	/* 	return (-1); */
	return (contact);
}

int				solve(t_player *p)
{
	int			ret;
	t_solve		s;
	int			mask;

	ret = 0;
	init_solve(&s, p);
	mask = (p->x_start >= p->x_op_st) ? XPLUS : XMOIN;
	mask |= (p->y_start >= p->y_op_st) ? YPLUS : YMOIN;
	ret = choose_solver(&s, p, mask);
	print_answer(s.y - 1, s.x - p->space);
	return (0);
}
