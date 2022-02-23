/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:28:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int	ft_map_width(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	**create_map(int h, int w)
{
	int	i;
	int	**map;

	i = 0;
	map = (int **)malloc(sizeof(int *) * h);
	if (!map)
		return (0);
	while (i < w)
	{
		map[i] = (int *)malloc(sizeof(int) * w);
		if (map[i] == NULL)
			return (0);
		i++;
	}
	return (map);
}
