/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:44:04 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/27 19:44:09 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H

# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include<errno.h>
# include <string.h>

# define NAME "pipex"
# define SAMPLE "Usage : file1 cmd1 cmd2 file2\n"
# define SAMPLE_B "Usage : file1 cmd1 cmd2 cmd3 ... cmdn file2\n"
# define ERR_FILE "pipex: no such file or directory: "
# define ERR_FILEPER "pipex: permission denied: "
# define ERR_INPUT "pipex: invalid number of arguments\n"
# define ERR_FORK "pipex: fork failed "
# define ERR_CMD "pipex: Command not found: "
# define ERR_PIPE "pipex: unable to create pipe"
# define ERR_HEREDOC "Usage : here_doc LIMITER cmd cmd1 file"
# define ERR_PERMISSION "pipex: permission denied: "
# define HD_FILENAME ".hd_tmp"

//  ft_pipex.c & ft_pipex_bonus.c
//int main
int		check_and_openfile(int argc, char **argv, int *i);
int		get_openfile(char *path, int mode);
void	get_exec(char *av, char **envp);
void	ft_create_pipe(char *cmd, char **envp, int fdin);

//  ft_freeable.c
void	ft_free_split(char **s);
void	ft_err_print(char *str, char *col, int enter);
void	msg_error(char *err);
void	msg(char *err, char *arg);
void	msg_cmd(char *err, char *arg);

//  ft_split.c
char	*ft_substr(const char *str, int begin_index, int end_index);
char	**ft_split(char *str, char *s);

// mini_gnl.c
char	*mini_gnl(int fd);
int		here_doc(char *argv);

//  utils.c
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin_m(char const *s1, char const *s2);
size_t	ft_strncmp(const char *s, const char *reject, int n);
size_t	ft_strlen(const char *s);

#endif
