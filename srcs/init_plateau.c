/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plateau.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:57:21 by nabih             #+#    #+#             */
/*   Updated: 2019/07/24 12:28:20 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				get_tab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab != NULL && tab[i])
		i++;
	return (i);
}

int				get_board_size(t_player *p)
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

void			tab_bzero(char ***tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		(*tab)[i] = NULL;
		i++;
	}
	(*tab)[i] = NULL;
}

int				get_board(t_player *p)
{
	int		y;

	y = 0;
	if ((p->plateau = (char**)malloc(sizeof(char*) * (p->y_plat + 1))) == NULL)
		return (-1);
	while (y < (p->y_plat + 1) && get_next_line(0, &(p->line)) != -1)
	{
		if (((p->plateau)[y] = (char*)malloc(sizeof(char) \
								* (ft_strlen(p->line) + 1))) == NULL)
			return (-1);
		ft_strcpy((p->plateau)[y], p->line);
		free_str(&(p->line));
		y++;
	}
	free_str(&(p->line));
	return (0);
}
