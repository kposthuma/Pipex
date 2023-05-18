/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:58:58 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/25 17:56:00 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<libft.h>
# include<fcntl.h>
# include<stdio.h>
# include<string.h>
# include<errno.h>

# ifndef ERROR
#  define ERROR -1
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000000
# endif

typedef struct s_pipex
{
	int		fd1[2];
	int		fd2[2];
	char	**env;
	char	**argv;
	int		argc;
}	t_pipex;

char	**ft_quote_trimmer(char **src);
char	**argument_splitter(t_pipex *pipex, int i);
int		execute_command(char *arg, char **args, t_pipex *pipex, char **envp);
int		forks(t_pipex *pipex, char **envp);
int		forks_here_doc(t_pipex *pipex, char **envp);

void	process_first(t_pipex *pipex, char **envp);
void	process_first_here_doc(t_pipex *pipex, char **envp);
void	write_to_pipe(t_pipex *pipex);

int		process_middle(t_pipex *pipex, char **envp);
int		process_middle_here_doc(t_pipex *pipex, char **envp);
void	process_middle_child(t_pipex *pipex, int i, char **envp);
void	process_middle_child_here_doc(t_pipex *pipex, int i, char **envp);
int		refresh_pipe(int fd[2]);

int		process_final(t_pipex *pipex, int i, char **envp);
int		process_final_here_doc(t_pipex *pipex, int i, char **envp);

void	pipex_error(char *message, char **environ);
char	**strs_dup(char **src);
char	**make_env(char **envp);
void	command_not_found(char *command, t_pipex *pipex);

// void	f(void);

#endif
