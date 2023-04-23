/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_final.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 09:37:30 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/06 11:05:51 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	process_final(t_pipex *pipex, int i, char **envp)
{	
	char	**args;
	int		fd_outfile;

	close(pipex->fd1[1]);
	close(pipex->fd2[1]);
	args = NULL;
	if (pipex->argv[i] != NULL)
		args = argument_splitter(pipex, i);
	if (i % 2 == 1)
		dup2(pipex->fd1[0], STDIN_FILENO);
	else
		dup2(pipex->fd2[0], STDIN_FILENO);
	close(pipex->fd1[0]);
	close(pipex->fd2[0]);
	fd_outfile = open(pipex->argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
		return (perror("pipex"), EXIT_FAILURE);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	if (args != NULL)
		execute_command(args[0], args, pipex, envp);
	else
		execute_command(NULL, NULL, pipex, envp);
	return (2);
}

int	process_final_here_doc(t_pipex *pipex, int i, char **envp)
{	
	char	**args;
	int		fd_outfile;

	close(pipex->fd1[1]);
	close(pipex->fd2[1]);
	args = NULL;
	if (pipex->argv[i] != NULL)
		args = argument_splitter(pipex, i);
	if (i % 2 == 0)
		dup2(pipex->fd1[0], STDIN_FILENO);
	else
		dup2(pipex->fd2[0], STDIN_FILENO);
	close(pipex->fd1[0]);
	close(pipex->fd2[0]);
	fd_outfile = open(pipex->argv[i + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd_outfile < 0)
		return (perror("pipex"), EXIT_FAILURE);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	if (args != NULL)
		execute_command(args[0], args, pipex, envp);
	else
		execute_command(NULL, NULL, pipex, envp);
	return (2);
}
