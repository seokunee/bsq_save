/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:27:28 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:27:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int	**make_map(char **map, char *value)
{
	int	h_max;
	int	w_max;
	int	**map_arr;

	h_max = ft_map_height(map) + ft_map_width(map);
	w_max = ft_map_width(map) + ft_map_height(map);
	map_arr = create_map(h_max, w_max);
	if (!map_arr)
		return (0);
	fill_one_zero(map_arr, map, value);
	return (map_arr);
}
