/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:26:50 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:26:51 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	revert;
	int	n;

	result = 0;
	n = 0;
	revert = 1;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
		n++;
	while (str[n] == '-' || str[n] == '+')
		if (str[n++] == '-')
			revert *= -1;
	result = 0;
	while (str[n] >= '0' && str[n] <= '9')
		result = result * 10 + str[n++] - '0';
	return (result * revert);
}
