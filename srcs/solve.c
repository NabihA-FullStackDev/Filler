/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:19:37 by nabih             #+#    #+#             */
/*   Updated: 2019/07/20 09:26:39 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void		init_solve(t_solve *s, t_player *p)
{
	(void)p;
	s->x = 0;// p->x_start;
	s->y = 0;// p->y_start;
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
	c = get_char_player(p);
	op = (c == 'O') ? 'X' : 'O';
	while (i < p->y_piec && (y + i) < (p->y_plat + 1))
	{
		j = 0;
		while (j < p->x_piec && (x + j) < (p->x_plat + p->space))
		{
			if ((p->piece)[i][j] == '*'							\
				&& ((p->plateau)[y + i][x + j] == c				\
				|| (p->plateau)[y + i][x + j] == (c + 32)))
				contact += 1;
			/* if (((p->plateau)[y + i][x + j] == op			\ */
			/* 	 || (p->plateau)[y + i][x + j] == (op + 32))	\ */
			/* 	&& (p->piece)[i][j] == '*') */
			/* 	return (0); */
			j++;
		}
		i++;
	}
	return (contact);
}

int				start_solve_xplus_yplus(t_solve *s, t_player *p, int x, int y);
int				start_solve_xplus_yminus(t_solve *s, t_player *p, int x, int y);
int				start_solve_xminus_yplus(t_solve *s, t_player *p, int x, int y);
int				start_solve_xminus_yminus(t_solve *s, t_player *p, int x, int y);

int				solve(t_player *p)
{
	int			ret;
	t_solve		s;

	ret = 0;
	init_solve(&s, p);
	/* testtest(&s, p, p->space, 1); */
	if (ret == 0)
		ret = start_solve_xplus_yplus(&s, p, s.x, s.y);
	if (ret == 0)
		ret = start_solve_xminus_yplus(&s, p, s.x, s.y);
	if (ret == 0)
		ret = start_solve_xplus_yminus(&s, p, s.x, s.y);
	if (ret == 0)
		ret = start_solve_xminus_yminus(&s, p, s.x, s.y);
	dprintf(2, "RET = %d\n", ret);
	dprintf(2, "X = %d, Y = %d\n", s.x, s.y);
	print_answer(s.y - 1, s.x - p->space);
	return (0);
}
