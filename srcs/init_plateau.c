/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plateau.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:57:21 by nabih             #+#    #+#             */
/*   Updated: 2019/07/19 10:28:39 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>


static int	get_tab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab != NULL && tab[i])
		i++;
	return (i);
}

int			get_board_size(t_player *p)
{
	int		size;

	if ((size = get_next_line(0, &(p->line))) == -1)
		ft_putstr("Bad board info\n");
	else
	{
		p->plateau = ft_strsplit(p->line, ' ');
		if ((size = get_tab_size(p->plateau)) == 3
			&& ft_strncmp(p->line, "Plateau", 7) == 0)
		{
			p->y_plat = ((p->plateau)[1] != NULL) ?
				ft_atoi((p->plateau)[1]) : 0;
			p->x_plat = ((p->plateau)[2] != NULL) ?
				ft_atoi((p->plateau)[2]) : 0;
		}
		free_str_tab(&(p->plateau), size);
		if (p->y_plat == 0 || p->x_plat == 0)
		{
			ft_putstr("Bad board info\n");
			free_str(&(p->line));
			return (-1);
		}
	}
	free_str(&(p->line));
	return ((size == 3) ? 0 : -1);
}

int			count_column_space(char *str)
{
	int		i;

	i = 0;
	while (str != NULL && str[i] == ' ' && str[i])
		i++;
	return (i);
}

int			get_first_board(t_player *p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (get_next_line(0, &(p->line)) == -1)
	{
		ft_putstr("Bad board\n");
		return (-1);
	}
	else
	{
		x = p->x_plat + count_column_space(p->line) + 1;
		y = p->y_plat;
		free_str(&(p->line));
		if ((p->line = (char*)malloc(sizeof(char) * (x * y + 1))) == NULL)
			return (-1);
		if (read(0, p->line, (x * y)) == -1)
			return (-1);
		else
			p->plateau = ft_strsplit(p->line, '\n');
		free_str(&(p->line));
		p->xy_plat = x * (y + 1);
	}
	return (0);
}
