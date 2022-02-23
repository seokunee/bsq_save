/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:26:57 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:26:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_int_arr(int **to_free, char **map)
{
	int	i;

	i = 0;
	while (i < ft_map_height(map) + ft_map_width(map))
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	free_char_arr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
}
