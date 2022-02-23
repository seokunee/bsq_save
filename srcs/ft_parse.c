/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:27:51 by seokchoi          #+#    #+#             */
/*   Updated: 2022/02/23 12:27:52 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_file_read(int fd, int size, int len)
{
	char	buf[2048];
	char	*value;
	char	*tmp;

	value = malloc(sizeof(char));
	if (!value)
		return (NULL);
	len = read(fd, buf, 2048);
	while (len > 0)
	{
		tmp = malloc((size + len + 1) * sizeof(char));
		if (tmp == NULL)
			break ;
		tmp = ft_strncpy(tmp, value, size);
		free(value);
		ft_strncpy(tmp + size, buf, len);
		value = tmp;
		size += len;
		value[size] = '\0';
		len = read(fd, buf, 2048);
	}
	if (len)
		free(value);
	return (value);
}

int	ft_strlen_content(const char *str, int n)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (n == 1)
	{
		while (str[i] && str[i] <= '9' && str[i] >= '0')
			i++;
		return (i);
	}
	else if (n == 1)
	{
		while (str[k] && str[k] != ':')
			k++;
		k++;
		while (str[k] && str[k] == ' ')
			k++;
		while (str[k] && str[k + i] != '\n')
			i++;
		return (i);
	}
	return (i);
}

char	**ft_parse(char *filename, int cn_len, int fd, int len)
{
	char	*content;
	char	**dest;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd, 0, 0);
	if (fd != 0)
		close(fd);
	while (content[cn_len])
		cn_len++;
	if (content[cn_len - 1] != '\n')
		return (NULL);
	dest = ft_split(content, '\n');
	free(content);
	cn_len = 0;
	if (dest[cn_len + 1])
		len = ft_strlen(dest[cn_len + 1]);
	else
		return (NULL);
	while (dest[++cn_len])
		if (len != ft_strlen(dest[cn_len]))
			return (NULL);
	return (dest);
}
