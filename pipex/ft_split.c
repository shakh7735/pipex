/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:45:55 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/27 19:46:01 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_substr(const char *str, int begin_index, int end_index)
{
	char	*temp;
	int		i;
	int		j;

	if (end_index - begin_index <= 0 || !str)
		return (NULL);
	temp = malloc(sizeof(char) * (end_index - begin_index + 1));
	if (!temp)
		return (NULL);
	i = begin_index;
	j = -1;
	while (str[i] && i < end_index)
		temp[++j] = str[i++];
	temp[++j] = '\0';
	return (temp);
}

static int	ft_eq(char c, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (0);
	return (1);
}

static int	ft_sizetab(char *str, char *s)
{
	int	len_tab;
	int	begin_word;
	int	i;

	len_tab = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_eq(str[i], s))
			begin_word = i;
		if (ft_eq(str[i], s) && begin_word != -1)
		{
			len_tab++;
			begin_word = -1;
		}
	}
	return (len_tab);
}

static char	**ft_split_loop(char *str, char *s, char **tab)
{
	int	len_tab;
	int	begin_word;
	int	i;

	i = -1;
	len_tab = 0;
	begin_word = 0;
	while (str[++i])
	{
		if (!ft_eq(str[i], s))
			begin_word = i + 1;
		if (ft_eq(str[i], s) && begin_word != -1)
		{
			while (str[i] && ft_eq(str[i], s))
				i++;
			tab[len_tab] = ft_substr(str, begin_word, i);
			len_tab++;
			begin_word = -1;
			i--;
		}
	}
	tab[len_tab] = NULL;
	return (tab);
}

char	**ft_split(char *str, char *s)
{
	int		len_tab;
	char	**tab;

	len_tab = ft_sizetab(str, s);
	if (len_tab == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (len_tab + 1));
	if (!tab)
		return (NULL);
	return (ft_split_loop(str, s, tab));
}
