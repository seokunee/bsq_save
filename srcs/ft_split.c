/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:28:05 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:06 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 0)
		i++;
	return (i);
}

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset) == 1)
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

char	*ft_strsplitcpy(char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char *str, char b)
{
	char		**dest;
	char		charset[2];
	int			size;
	int			i;
	int			j;

	charset[0] = b;
	charset[1] = '\0';
	i = 0;
	size = ft_wordcount(str, charset);
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest || ft_strlen(str) <= 1 || ft_check_c(str))
		return (NULL);
	while (i < size)
	{
		while (ft_is_charset(*str, charset))
			str++;
		j = ft_wordlen(str, charset);
		dest[i] = ft_strsplitcpy(str, j);
		str += j;
		i++;
	}
	dest[size] = 0;
	return (dest);
}
