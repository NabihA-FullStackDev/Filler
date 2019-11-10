/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:19:37 by nabih             #+#    #+#             */
/*   Updated: 2019/11/10 03:57:58 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void		init_solve(t_solve *s, t_player *p)
{
	s->x = p->x_start - p->space;
	s->y = p->y_start - 1;
}

int				return_value_check(t_player *p, t_resolution *res)
{
	static int	old_pts = 0;

	if (p->flag == 0)
	{
		old_pts = 0;
		p->flag = 1;
	}
	if (res->contact == 1 && old_pts < res->new_pts)
	{
		old_pts = res->new_pts;
		return (res->contact);
	}
	return (0);
}

int				check_contact(t_player *p, t_piece *pi, int x, int y)
{
	unsigned int	i;
	t_resolution	res;
	t_solve			*tmp;

	i = 0;
	res.contact = 0;
	res.new_pts = 0;
	res.c = (p->order == 1) ? 'O' : 'X';
	res.op = (res.c == 'O') ? 'X' : 'O';
	tmp = pi->vec_piec;
	while (i < pi->nb)
	{
		if (((x + tmp[i].x) >= (p->x_plat + p->space)
				|| (y + tmp[i].y) >= (p->y_plat + 1)))
			return (-1);
		if ((x + tmp[i].x) < p->space || (y + tmp[i].y) == 0)
			return (-1);
		if ((p->plateau)[y + tmp[i].y][x + tmp[i].x] == res.c)
			res.contact += 1;
		if ((p->plateau)[y + tmp[i].y][x + tmp[i].x] == res.op)
			return (0);
		res.new_pts += (int)(p->value[y + tmp[i].y][x + tmp[i].x] - '0');
		i++;
	}
	return (return_value_check(p, &res));
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
	print_answer(s.y - 1 - p->s_piec.y, s.x - p->space - p->s_piec.x);
	return (0);
}
