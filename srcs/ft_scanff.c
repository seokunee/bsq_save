/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:27:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:27:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	pppp(char *buf);


char	*ft_scanff(void)
{
	int		count;
	char	mini_buff;
	char	buff[5000];
	char	*str;

	count = 0;
	while (read(0, &mini_buff, 1))
		buff[count++] = mini_buff;
	buff[count] = 0;
	str = malloc((count) * sizeof(char));
	if (str == NULL)
		return (NULL);
	count = -1;
	while (buff[++count])
		str[count] = buff[count];
	str[count] = 0;
	// pppp(str);
	return (str);
}

void	pppp(char *buf)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (buf[i])
	{
		write(1, &buf[i], 1);
		i++;
	}
	write(1, "\n", 1);
}