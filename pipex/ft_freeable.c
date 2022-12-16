/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:39:40 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/27 19:39:48 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_free_split(char **s)
{
	int	i;

	i = -1;
	while (s && s[++i])
		free(s[i]);
	if (s)
		free(s);
}

void	ft_err_print(char *str, char *col, int enter)
{
	strerror(0);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(col, 2);
	if (enter)
		write(1, "\n", 2);
	exit (1);
}

void	msg_error(char *err)
{
	write(2, (err), ft_strlen(err));
	exit (1);
}

void	msg(char *err, char *arg)
{
	write(2, err, ft_strlen(err));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

void	msg_cmd(char *err, char *arg)
{
	write(2, err, ft_strlen(err));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	exit (1);
}
