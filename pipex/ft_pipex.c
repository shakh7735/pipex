/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:37 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/27 19:42:47 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_in;
	int	fd_out;

	fd_in = check_and_openfile(argc, argv, &i);
	fd_out = get_openfile (argv[argc - 1], 1);
	dup2 (fd_in, 0);
	dup2 (fd_out, 1);
	ft_create_pipe (argv[i], envp, fd_in);
	while (++i < argc - 2)
		ft_create_pipe (argv[i], envp, 1);
	get_exec (argv[i], envp);
	close (fd_in);
	close (fd_out);
	return (0);
}

int	check_and_openfile(int argc, char **argv, int *i)
{
	int	fd_in;

	*i = 5;
	if (argc != *i)
	{
		write(2, &SAMPLE, ft_strlen(SAMPLE));
		exit(1);
	}
	fd_in = get_openfile (argv[1], 0);
	*i = 2;
	return (fd_in);
}

int	get_openfile(char *path, int mode)
{
	int	fd;

	if (mode)
	{
		fd = open (path, O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (access (path, F_OK) == 0 && fd < 0)
			msg_cmd (ERR_FILEPER, path);
		else if (fd < 0)
			msg (ERR_FILE, path);
	}
	else
	{
		fd = open (path, O_RDONLY);
		if (access (path, F_OK) == 0 && fd < 0)
			msg (ERR_FILEPER, path);
		else if (fd < 0)
			msg_cmd (ERR_FILE, path);
	}
	return (fd);
}

void	get_exec(char *av, char **envp)
{
	int		i;
	char	**path;
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split (av, " ");
	if (!cmd)
		msg_cmd ("", ERR_PERMISSION);
	i = -1;
	while (envp[++i])
		if (!ft_strncmp (envp[i], "PATH=", 5))
			path = ft_split (&envp[i][5], ":");
	i = -1;
	while (path[++i])
	{
		if (cmd[0][0] == '/')
			cmd_path = ft_strdup(cmd[0]);
		else
			cmd_path = ft_strjoin_m (path[i], cmd[0]);
		if (access (cmd_path, X_OK) == 0)
			execve (cmd_path, cmd, envp);
	}
	msg_error (NAME);
}

void	ft_create_pipe(char *cmd, char **envp, int fdin)
{
	pid_t	pid;
	int		fd[2];

	if (pipe (fd) == -1)
		msg_error (ERR_PIPE);
	pid = fork ();
	if (pid == -1)
		msg_error (ERR_FORK);
	if (pid)
	{
		close (fd[1]);
		dup2 (fd[0], 0);
		waitpid (pid, NULL, 0);
	}
	else
	{
		close (fd[0]);
		dup2 (fd[1], 1);
		if (fdin == 0)
			msg_error (NAME);
		else
			get_exec (cmd, envp);
	}
}
