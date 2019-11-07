/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabih <naali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:45 by nabih             #+#    #+#             */
/*   Updated: 2019/11/07 14:26:46 by nabih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			dst[y][x] = (dst[y][x] == '.' && src[y][x] != '.') ? src[y][x] + 32 : src[y][x];
			x = x + 1;
		}
		y = y + 1;
	}
	return (dst);
}
