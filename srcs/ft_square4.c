/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:28:21 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:22 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

void	write_best(t_bsq *best, int **map, int i, int j)
{
	best->x = i - map[i][j] + 1;
	best->y = j - map[i][j] + 1;
	best->size = map[i][j];
}

t_bsq	find_best(int **fill, char **map, int i, int j)
{
	t_bsq	best;

	best.size = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (fill[i][j] > best.size)
				write_best(&best, fill, i, j);
			j++;
		}
		i++;
	}
	return (best);
}
