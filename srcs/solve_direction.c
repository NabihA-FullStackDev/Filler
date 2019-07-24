/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:22:53 by nabih             #+#    #+#             */
/*   Updated: 2019/07/24 09:03:52 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				check_contact(t_player *p, int x, int y);

int				solve_xplus_yplus(t_solve *s, t_player *p, int x, int y)
{
	if (check_contact(p, x, y) == 1)
	{
		s->x = x;
		s->y = y;
		return (1);
	}
	else
	{
		if (x >= p->space && x - p->space < p->x_plat - p->x_piec)
			if (solve_xplus_yplus(s, p, x + 1, y) == 1)
				return (1);
		if (y >= 1 && y - 1 < p->y_plat - p->y_piec)
			if (solve_xplus_yplus(s, p, x, y + 1) == 1)
				return (1);
	}
	return (0);
}

int				solve_xplus_yminus(t_solve *s, t_player *p, int x, int y)
{
	if (check_contact(p, x, y) == 1)
	{
		s->x = x;
		s->y = y;
		return (1);
	}
	else
	{
		if (x >= p->space && x - p->space < p->x_plat - p->x_piec)
			if (solve_xplus_yminus(s, p, x + 1, y) == 1)
				return (1);
		if (y > 1 && y - 1 < p->y_plat - p->y_piec)
			if (solve_xplus_yminus(s, p, x, y - 1) == 1)
				return (1);
	}
	return (0);
}

int				solve_xminus_yplus(t_solve *s, t_player *p, int x, int y)
{
	if (check_contact(p, x, y) == 1)
	{
		s->x = x;
		s->y = y;
		return (1);
	}
	else
	{
		if (x > p->space && x - p->space < p->x_plat - p->x_piec)
			if (solve_xminus_yplus(s, p, x - 1, y) == 1)
				return (1);
		if (y >= 1 && y - 1 < p->y_plat - p->y_piec)
			if (solve_xminus_yplus(s, p, x, y + 1) == 1)
				return (1);
	}
	return (0);
}

int				solve_xminus_yminus(t_solve *s, t_player *p, int x, int y)
{
	if (check_contact(p, x, y) == 1)
	{
		s->x = x;
		s->y = y;
		return (1);
	}
	else
	{
		if (x > p->space && x - p->space < p->x_plat - p->x_piec)
			if (solve_xminus_yminus(s, p, x - 1, y) == 1)
				return (1);
		if (y > 1 && y - 1 < p->y_plat - p->y_piec)
			if (solve_xminus_yminus(s, p, x, y - 1) == 1)
				return (1);
	}
	return (0);
}

int				change_mask(int *mask)
{
	static int	old = 0;

	old += *mask;
	if (*mask == 10)
		*mask = 18;
	else if (*mask == 18)
		*mask = 12;
	else if (*mask == 12)
		*mask = 20;
	else if (*mask == 20)
		*mask = 10;
	return (old);
}

void			change_xy(t_player *p, int mask, int *x, int *y)
{
	*x = p->x_start;
	*y = p->y_start;
	if (mask == 10)
	{
		*x = (*x - p->x_piec < p->space) ? p->space : *x - (p->x_piec);
		*y = (*y - p->y_piec < 1) ? 1 : *y - (p->y_piec) / 2;
	}
	if (mask == 12)
		*x = (*x - p->x_piec < p->space) ? p->space : *x - (p->x_piec);
	if (mask == 18)
		*y = (*y - p->y_piec < 1) ? 1 : *y - (p->y_piec);
}

int				choose_solver(t_solve *s, t_player *p, int mask)
{
	int		x;
	int		y;
	int		ret;
	int		old;

	x = 0;
	y = 0;
	ret = 0;
	old = 0;
	change_xy(p, mask, &x, &y);
	while (ret == 0 && old <= 120)
	{
		dprintf(2, "MASK = %d\n", mask);
		dprintf(2, "START AT x = %d, y = %d\n", x, y);
//		dprintf(2, "x = %d, y = %d\n", p->x_start - p->x_piec, p->y_start - 1);
		if (mask == 10)
			ret = solve_xplus_yplus(s, p, x, y);
		else if (mask == 18)
			ret = solve_xplus_yminus(s, p, x, y);
		else if (mask == 12)
			ret = solve_xminus_yplus(s, p, x, y);
		else if (mask == 20)
			ret = solve_xminus_yminus(s, p, x, y);
		old = change_mask(&mask);
		change_xy(p, mask, &x, &y);
		dprintf(2, "REET = %d\n", ret);
	}
	dprintf(2, "MASK = %d, REET = %d\n", mask, ret);
	return (ret);
}
