/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:11:58 by naali             #+#    #+#             */
/*   Updated: 2019/11/12 13:12:23 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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
