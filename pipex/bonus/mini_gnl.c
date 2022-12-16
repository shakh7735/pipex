/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:56:56 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/27 19:57:02 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pipex.h"

static void	unlink_here(void);

char	*mini_gnl(int fd)
{
	char	*line;
	char	temp;
	int		i;

	line = malloc(10000);
	i = 0;
	while (1)
	{
		if (read(fd, &temp, 1) < 0)
			return (NULL);
		if (temp == '\n' || temp == '\0')
			break ;
		line[i++] = temp;
	}
	line[i] = 0;
	return (line);
}

int	here_doc(char *limit)
{
	int		file;
	char	*buf;

	file = open (HD_FILENAME, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_error (ERR_HEREDOC);
	while (1)
	{
		write (1, "hd> ", 4);
		buf = mini_gnl (0);
		if (!buf)
			exit (1);
		if (!ft_strncmp (limit, buf, ft_strlen (limit)))
			break ;
		write (file, buf, ft_strlen (buf));
		write (file, "\n", 1);
		if (buf)
			free (buf);
	}
	free (buf);
	close (file);
	file = open (HD_FILENAME, O_RDONLY);
	if (file < 0)
		unlink_here();
	return (file);
}

static void	unlink_here(void)
{
	unlink (HD_FILENAME);
	msg_error (ERR_HEREDOC);
}
