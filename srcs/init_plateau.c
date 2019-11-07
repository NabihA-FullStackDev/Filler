/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plateau.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:57:21 by nabih             #+#    #+#             */
/*   Updated: 2019/11/07 14:27:17 by nabih            ###   ########.fr       */
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

int				init_cp_plat(t_player *p, int x, int y)
{
	int			i;

	i = 0;
	if (((p->cp_plat) = (char**)malloc(sizeof(char*) * y)) == NULL)
		return (-1);
	while (i < y)
	{
		if (((p->cp_plat)[i] = (char*)malloc(sizeof(char) * x)) == NULL)
			return (-1);
		ft_strcpy((p->cp_plat)[i], (p->plateau)[i]);
		i++;
	}
	return (0);
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
	/* TEST + MODIFICATION*/
	ft_putstr("plateau:\n");
	print_tab_for_test(p->plateau, p->y_plat);
	if (p->cp_plat == NULL)
		init_cp_plat(p, (ft_strlen(p->plateau[0]) + 1), (p->y_plat + 1));
	else
		cpy_plateau(p->cp_plat, (const char**)p->plateau, p->y_plat + 1);
	ft_putchar('\n');
	ft_putstr("cp_plat:\n");
	print_tab_for_test(p->cp_plat, p->y_plat);
	ft_putchar('\n');
	/* TEST + MODIFICATION*/
	free_str(&(p->line));
	return (0);
}
