/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 01:46:14 by nabih             #+#    #+#             */
/*   Updated: 2019/07/20 05:35:46 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				get_space(t_player *p)
{
	int			i;

	i = 0;
	while (p->plateau[0][i] == ' ' && p->plateau[0][i] != '\0')
		i++;
	p->space = i;
	return (0);
}

char			get_char_player(t_player *p)
{
	if (p->order == 1)
		return ('O');
	else
		return ('X');
}

int				get_start(t_player *p)
{
	char		c;
	int			x;
	int			y;

	y = 0;
	c = get_char_player(p);
	while (y < p->y_plat)
	{
		x = 0;
		while ((p->plateau)[y][x] != '\0')
		{
			if ((p->plateau)[y][x] == c)
			{
				p->y_start = y;
				p->x_start = x;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}
