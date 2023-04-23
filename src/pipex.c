/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 10:08:32 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/19 13:56:42 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	**ft_quote_trimmer(char **src)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (src[i])
	{
		if (src[i][0] == '\'' || src[i][0] == '\"')
		{
			temp = ft_substr(src[i], 1, ft_strlen(src[i]) - 2);
			if (!temp)
				pipex_error("Memory allocation error", src);
			free(src[i]);
			src[i] = ft_strdup(temp);
			if (!src[i])
				pipex_error("Memory allocation error", src);
			free(temp);
		}
		i++;
	}
	return (src);
}

char	**argument_splitter(t_pipex *pipex, int i)
{
	char	**split_string;

	split_string = ft_split_quotes(pipex->argv[i], ' ');
	if (!split_string)
		pipex_error("Memory allocation error", NULL);
	split_string = ft_quote_trimmer(split_string);
	if (!split_string)
		pipex_error("Memory allocation error", NULL);
	return (split_string);
}

int	execute_command(char *arg, char **args, t_pipex *pipex, char **envp)
{
	char	*path;
	size_t	i;

	i = 0;
	path = ft_strdup(arg);
	if (!path)
		pipex_error("Memory allocation error", NULL);
	if (pipex->env)
	{
		while (access(path, F_OK | X_OK) == -1 && pipex->env[i])
		{
			free(path);
			path = ft_strjoin(pipex->env[i], arg);
			if (!path)
				pipex_error("Memory allocation error", NULL);
			i++;
		}
		if (!pipex->env[i])
			command_not_found(arg, pipex);
	}
	if (execve(path, args, envp) == -1)
		perror("error");
	wait (NULL);
	exit (EXIT_FAILURE);
}

int	forks(t_pipex *pipex, char **envp)
{
	pid_t	process;
	int		i;

	process = fork();
	if (process == ERROR)
		pipex_error("Failed to fork\n", pipex->env);
	else if (process == 0)
		process_first(pipex, envp);
	i = process_middle(pipex, envp);
	return (process_final(pipex, i, envp));
}

int	forks_here_doc(t_pipex *pipex, char **envp)
{
	pid_t	process;
	int		i;

	if (pipex->argc < 6)
		pipex_error("Incorrect argument count\n", pipex->env);
	write_to_pipe(pipex);
	process = fork();
	if (process == ERROR)
		pipex_error("Failed to fork\n", pipex->env);
	else if (process == 0)
		process_first_here_doc(pipex, envp);
	i = process_middle_here_doc(pipex, envp);
	return (process_final_here_doc(pipex, i, envp));
}
