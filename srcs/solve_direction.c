/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:22:53 by nabih             #+#    #+#             */
/*   Updated: 2019/11/10 03:58:28 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				solve_xplus_yplus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;
	int			ret;

	y_cp = y;
	ret = 0;
	while (x <= p->x_plat + p->space)
	{
		y = y_cp;
		while (y <= p->y_plat + 1)
		{
			if (check_contact(p, &(p->s_piec), x, y) == 1)
			{
				ret = 1;
				s->x = x;
				s->y = y;
			}
			y++;
		}
		x++;
	}
	return (ret);
}

int				solve_xplus_yminus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;
	int			ret;

	y_cp = y;
	ret = 0;
	while (x <= p->x_plat + p->space)
	{
		y = y_cp;
		while (y >= 1)
		{
			if (check_contact(p, &(p->s_piec), x, y) == 1)
			{
				ret = 1;
				s->x = x;
				s->y = y;
			}
			y--;
		}
		x++;
	}
	return (ret);
}

int				solve_xminus_yplus(t_solve *s, t_player *p, int x, int y)
{
	int			y_cp;
	int			ret;

	y_cp = y;
	ret = 0;
	while (x >= p->space)
	{
		y = y_cp;
		while (y <= p->y_plat + 1)
		{
			if (check_contact(p, &(p->s_piec), x, y) == 1)
			{
				ret = 1;
				s->x = x;
				s->y = y;
			}
			y++;
		}
		x--;
	}
	return (ret);
}

int				solve_xminus_yminus(t_solve *s, t_player *p, int x, int y)
{
	int			x_cp;
	int			ret;

	x_cp = x;
	ret = 0;
	while (y >= 1)
	{
		x = x_cp;
		while (x >= p->space)
		{
			if (check_contact(p, &(p->s_piec), x, y) == 1)
			{
				ret = 1;
				s->x = x;
				s->y = y;
			}
			x--;
		}
		y--;
	}
	return (ret);
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
	*x = (mask == 10 || mask == 18) ? p->space : p->x_plat + p->space;
	*y = (mask == 10 || mask == 12) ? 1 : p->y_plat;
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
	while (ret == 0 && old <= 60)
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
		p->flag = 0;
	}
	return (ret);
}
