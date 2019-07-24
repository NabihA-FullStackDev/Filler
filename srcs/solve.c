/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:19:37 by nabih             #+#    #+#             */
/*   Updated: 2019/07/24 08:59:36 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void		init_solve(t_solve *s, t_player *p)
{
	s->x = p->x_start;
	s->y = p->y_start;
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
		while (p->piece[i][j] && j < p->x_piec
			   && p->plateau[y + i][x + j]
			   && (x + j) < (p->x_plat + p->space))
		{
			if ((p->piece)[i][j] == '*'
				&& ((p->plateau)[y + i][x + j] == c
				|| (p->plateau)[y + i][x + j] == (c + 32)))
				contact += 1;
			if ((p->piece)[i][j] == '*'
				&& ((p->plateau)[y + i][x + j] == op
				|| (p->plateau)[y + i][x + j] == (op + 32)))
				return (0);
			j++;
		}
		i++;
	}
	if (p->piece[i - 1][j] != '\0')
		return (-1);
	return (contact);
}

int				start_solve_xplus_yplus(t_solve *s, t_player *p, int x, int y);
int				start_solve_xplus_yminus(t_solve *s, t_player *p, int x, int y);
int				start_solve_xminus_yplus(t_solve *s, t_player *p, int x, int y);
int				start_solve_xminus_yminus(t_solve *s, t_player *p, int x, int y);

int				get_last_op_pos(t_player *p)
{
	char		op;
	int			x;
	int			y;

	y = 0;
	op = (p->order == 1) ? 'x' : 'o';
	while (y < p->y_plat)
	{
		x = 0;
		while ((p->plateau)[y][x] != '\0')
		{
			if ((p->plateau)[y][x] == op)
			{
				p->y_op_st = y;
				p->x_op_st = x;
			}
			x++;
		}
		y++;
	}
	if (p->y_op_st == -1 || p->x_op_st == -1)
	{
		p->x_op_st = 0;
		p->y_op_st = 0;
		return (-1);
	}
	return (0);
}

int				solve(t_player *p)
{
	int			ret;
	t_solve		s;
	int			mask;
	static int	test = 0;

	ret = 0;
	init_solve(&s, p);
	test = (test == 0) ? get_last_op_pos(p) : -1;
	mask = (p->x_start < p->x_op_st) ? XPLUS : XMOIN;
	mask |= (p->y_start < p->y_op_st) ? YPLUS : YMOIN;
	ret = choose_solver(&s, p, mask);
	dprintf(2, "X = %d, Y = %d\n", s.x, s.y);
	print_answer(s.y - 1, s.x - p->space);
	return (0);
}
