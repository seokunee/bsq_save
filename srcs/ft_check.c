/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:27:46 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:27:47 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_line(char **strs, char *value)
{
	int	i;
	int	j;
	int	line;

	i = 0;
	j = -1;
	while (strs[0][i])
		i++;
	while (++j < i - 3)
		if (strs[0][j] < '0' || strs[0][j] > '9')
			return (0);
	value[0] = strs[0][j];
	value[1] = strs[0][j + 1];
	value[2] = strs[0][j + 2];
	strs[0][j] = '\0';
	if (value[0] == value[1] || value[0] == value[2]
		|| value[1] == value[2])
		return (0);
	line = ft_atoi(strs[0]);
	i = 0;
	while (strs[i])
		i++;
	if (i - 1 != line || line == 0 || i <= 1)
		return (0);
	return (1);
}

int	check_char(char **strs, char *value)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (strs[i][j] != value[0] && strs[i][j] != value[1])
				return (0);
			j++;
		}
		if (j < 1)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i <= 1 || str[i - 1] != '\n')
		return (1);
	return (0);
}
