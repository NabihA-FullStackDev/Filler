/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:45 by nabih             #+#    #+#             */
/*   Updated: 2019/11/12 13:05:49 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

char			**cpy_plateau(char **dst, const char **src, unsigned int max)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (src[y][x] != '\0')
		{
			dst[y][x] = src[y][x];
			x = x + 1;
		}
		y = y + 1;
	}
	return (dst);
}

void			update_tab_value(char ***val, int max, char start, char new_c)
{
	int			x;
	int			y;

	y = 1;
	while (y < max)
	{
		x = 0;
		while ((*val)[y][x] != '\0')
		{
			if ((*val)[y][x] == start)
			{
				(x > 0 && (*val)[y][x - 1] == '.') ? \
					(*val)[y][x - 1] = new_c : 0;
				(y > 1 && (*val)[y - 1][x] == '.') ? \
					(*val)[y - 1][x] = new_c : 0;
				((*val)[y][x + 1] != '\0' && (*val)[y][x + 1] == '.') ? \
					(*val)[y][x + 1] = new_c : 0;
				(y < (max - 1) && (*val)[y + 1][x] == '.') ? \
					(*val)[y + 1][x] = new_c : 0;
			}
			x++;
		}
		y++;
	}
}

void			fill_value(char ***val, int max)
{
	int			x;
	int			y;

	y = 1;
	while (y < max)
	{
		x = 0;
		while ((*val)[y][x] != '\0')
		{
			if ((*val)[y][x] == '.')
				(*val)[y][x] = '0';
			x++;
		}
		y++;
	}
}

void			new_or_copy_tab(t_player *p)
{
	if (p->value == NULL)
		init_cp_plat(p, (ft_strlen(p->plateau[0]) + 1), \
						(p->y_plat + 1));
	else
		cpy_plateau(p->value, (const char**)p->plateau, \
					(p->y_plat + 1));
}
