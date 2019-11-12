/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:22:53 by nabih             #+#    #+#             */
/*   Updated: 2019/11/12 13:12:28 by naali            ###   ########.fr       */
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
