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
	return (str);
}
