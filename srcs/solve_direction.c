/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:22:53 by nabih             #+#    #+#             */
/*   Updated: 2019/07/24 14:07:53 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				solve_xplus_yplus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;

	y_cp = y;
	while (x < p->x_plat + p->space - p->x_piec)
	{
		y = y_cp;
		while (y <= p->y_plat + 1 - p->y_piec)
		{
			if (check_contact(p, x, y) == 1)
			{
				s->x = x;
				s->y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int				solve_xplus_yminus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;

	y_cp = y;
	while (x < p->x_plat + p->space - p->y_piec)
	{
		y = y_cp;
		while (y >= 1)
		{
			if (check_contact(p, x, y) == 1)
			{
				s->x = x;
				s->y = y;
				return (1);
			}
			y--;
		}
		x++;
	}
	return (0);
}

int				solve_xminus_yplus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;

	y_cp = y;
	while (x >= p->space)
	{
		y = y_cp;
		while (y < p->y_plat + 1 - p->y_piec)
		{
			if (check_contact(p, x, y) == 1)
			{
				s->x = x;
				s->y = y;
				return (1);
			}
			y++;
		}
		x--;
	}
	return (0);
}

int				solve_xminus_yminus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;

	y_cp = y;
	while (x >= p->space)
	{
		y = y_cp;
		while (y >= 1)
		{
			if (check_contact(p, x, y) == 1)
			{
				s->x = x;
				s->y = y;
				return (1);
			}
			y--;
		}
		x--;
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
	*x = (mask == 10 || mask == 18) ? p->space : p->x_plat + p->space - p->x_piec;
	*y = (mask == 10 || mask == 12) ? 1 : (p->y_plat - p->y_piec);
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
	while (ret == 0 && old <= 30)
	{
		if (mask == 10)
			ret = solve_xplus_yplus(s, p, x, y);
		else if (mask == 18)
			ret = solve_xplus_yminus(s, p, x, y);
		else if (mask == 12)
			ret = solve_xminus_yplus(s, p, x, x);
		else if (mask == 20)
			ret = solve_xminus_yminus(s, p, x, y);
		old = change_mask(&mask);
		change_xy(p, mask, &x, &y);
	}
	return (ret);
}
