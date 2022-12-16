/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:52:12 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/27 19:52:14 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	copy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!copy)
		return (0);
	i = -1;
	while (s[++i])
		copy[i] = s[i];
	copy[i] = '\0';
	return (copy);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = -1;
	while (s && s[++i])
		write(fd, &(s[i]), fd);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	ft_strncmp(const char *s, const char *reject, int n)
{
	int	i;

	i = -1;
	if (!s || !reject || !reject[0])
		return (1);
	while (++i < n && s[i] && reject[i])
	{
		if (s[i] != reject[i])
			return (s[i] - reject[i]);
	}
	return (0);
}

char	*ft_strjoin_m(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (i + j + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		str[i++] = '/';
		j = -1;
		while (s2[++j])
			str[i++] = s2[j];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
