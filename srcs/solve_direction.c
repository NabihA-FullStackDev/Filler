/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:22:53 by nabih             #+#    #+#             */
/*   Updated: 2019/07/20 09:18:39 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				check_contact(t_player *p, int x, int y);

int				start_solve_xplus_yplus(t_solve *s, t_player *p, int x, int y)
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
			return (start_solve_xplus_yplus(s, p, x + 1, y));
		if (y >= 1 && y - 1 < p->y_plat - p->y_piec)
			return (start_solve_xplus_yplus(s, p, x, y + 1));
	}
	return (0);
}

int				start_solve_xplus_yminus(t_solve *s, t_player *p, int x, int y)
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
			return (start_solve_xplus_yminus(s, p, x + 1, y));
		if (y > 1 && y - 1 < p->y_plat - p->y_piec)
			return (start_solve_xplus_yminus(s, p, x, y - 1));
	}
	return (0);
}

int				start_solve_xminus_yminus(t_solve *s, t_player *p, int x, int y)
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
			return (start_solve_xminus_yminus(s, p, x - 1, y));
		if (y > 1 && y - 1 < p->y_plat - p->y_piec)
			return (start_solve_xminus_yminus(s, p, x, y - 1));
	}
	return (0);
}

int				start_solve_xminus_yplus(t_solve *s, t_player *p, int x, int y)
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
			return (start_solve_xminus_yplus(s, p, x - 1, y));
		if (y >= 1 && y - 1 < p->y_plat - p->y_piec)
			return (start_solve_xminus_yplus(s, p, x, y + 1));
	}
	return (0);
}
