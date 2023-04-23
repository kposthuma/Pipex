/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_middle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 09:45:21 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/05 14:48:58 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	refresh_pipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
	return (pipe(fd));
}

int	process_middle(t_pipex *pipex, char **envp)
{
	pid_t	process;
	int		pv;
	int		i;

	i = 3;
	while (i < (pipex->argc - 2))
	{
		if (i % 2 == 1)
			pv = refresh_pipe(pipex->fd2);
		else
			pv = refresh_pipe(pipex->fd1);
		if (pv == ERROR)
			pipex_error("Failed to pipe\n", pipex->env);
		process = fork();
		if (process == ERROR)
			pipex_error("Failed to fork\n", pipex->env);
		else if (process == 0)
			process_middle_child(pipex, i, envp);
		i++;
	}
	return (i);
}

void	process_middle_child(t_pipex *pipex, int i, char **envp)
{
	char	**args;

	args = NULL;
	if (pipex->argv[i] != NULL)
		args = argument_splitter(pipex, i);
	if (i % 2 == 1)
	{
		dup2(pipex->fd1[0], STDIN_FILENO);
		dup2(pipex->fd2[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->fd2[0], STDIN_FILENO);
		dup2(pipex->fd1[1], STDOUT_FILENO);
	}
	close(pipex->fd1[0]);
	close(pipex->fd1[1]);
	close(pipex->fd2[0]);
	close(pipex->fd2[1]);
	if (args != NULL)
		execute_command(args[0], args, pipex, envp);
	else
		execute_command(NULL, NULL, pipex, envp);
	wait(NULL);
}

int	process_middle_here_doc(t_pipex *pipex, char **envp)
{
	pid_t	process;
	int		pv;
	int		i;

	i = 4;
	while (i < (pipex->argc - 2))
	{
		if (i % 2 == 0)
			pv = refresh_pipe(pipex->fd2);
		else
			pv = refresh_pipe(pipex->fd1);
		if (pv == ERROR)
			pipex_error("Failed to pipe\n", pipex->env);
		process = fork();
		if (process == ERROR)
			pipex_error("Failed to fork\n", pipex->env);
		else if (process == 0)
			process_middle_child_here_doc(pipex, i, envp);
		i++;
	}
	return (i);
}

void	process_middle_child_here_doc(t_pipex *pipex, int i, char **envp)
{
	char	**args;

	args = NULL;
	if (pipex->argv[i] != NULL)
		args = argument_splitter(pipex, i);
	if (i % 2 == 0)
	{
		dup2(pipex->fd1[0], STDIN_FILENO);
		dup2(pipex->fd2[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->fd2[0], STDIN_FILENO);
		dup2(pipex->fd1[1], STDOUT_FILENO);
	}
	close(pipex->fd1[0]);
	close(pipex->fd1[1]);
	close(pipex->fd2[0]);
	close(pipex->fd2[1]);
	if (args != NULL)
		execute_command(args[0], args, pipex, envp);
	else
		execute_command(NULL, NULL, pipex, envp);
	wait(NULL);
}
