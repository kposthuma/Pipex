/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_first.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 09:25:39 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/19 13:57:57 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	process_first(t_pipex *pipex, char **envp)
{
	int		fd_infile;
	char	**args;

	close(pipex->fd1[0]);
	close(pipex->fd2[0]);
	close(pipex->fd2[1]);
	args = NULL;
	if (pipex->argv[2] != NULL)
		args = argument_splitter(pipex, 2);
	fd_infile = open(pipex->argv[1], O_RDONLY, 0777);
	if (fd_infile < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(pipex->argv[1]);
		exit (EXIT_FAILURE);
	}
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(pipex->fd1[1], STDOUT_FILENO);
	close(pipex->fd1[1]);
	if (args != NULL)
		execute_command(args[0], args, pipex, envp);
	else
		execute_command(NULL, NULL, pipex, envp);
	wait(NULL);
}

void	write_to_pipe(t_pipex *pipex)
{
	char	*buffer;
	int		rv;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!buffer)
		pipex_error("Memory allocation error\n", pipex->env);
	while (ft_strncmp(pipex->argv[2], buffer, strlen(pipex->argv[2])) != 0)
	{
		write(STDIN_FILENO, "pipex here_doc> ", 16);
		rv = read(STDOUT_FILENO, buffer, BUFFER_SIZE);
		if (rv == ERROR)
			pipex_error("Read error\n", NULL);
		buffer[rv] = '\0';
		if (strncmp(pipex->argv[2], buffer, strlen(pipex->argv[2])) != 0)
			write(pipex->fd2[1], buffer, ft_strlen(buffer));
	}
	close(pipex->fd2[1]);
	free(buffer);
}

void	process_first_here_doc(t_pipex *pipex, char **envp)
{
	char	**args;
	int		pv;

	close(pipex->fd1[0]);
	args = NULL;
	if (pipex->argv[3] != NULL)
		args = argument_splitter(pipex, 3);
	dup2(pipex->fd2[0], STDIN_FILENO);
	close(pipex->fd2[0]);
	dup2(pipex->fd1[1], STDOUT_FILENO);
	close(pipex->fd1[1]);
	if (args != NULL)
		execute_command(args[0], args, pipex, envp);
	else
		execute_command(NULL, NULL, pipex, envp);
	wait(NULL);
}
