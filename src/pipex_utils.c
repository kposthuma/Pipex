/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 10:08:32 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/25 17:54:48 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	pipex_error(char *message, char **environ)
{
	ft_putstr_fd(message, STDERR_FILENO);
	if (environ)
		ft_free(environ);
	exit(EXIT_FAILURE);
}

char	**strs_dup(char **src)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = ft_calloc((strofstrlen(src) + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy[i])
			return (ft_free(copy), NULL);
		i++;
	}
	return (copy);
}

char	**add_slash_to_env(char **env)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (env[i])
	{
		temp = ft_strjoin(env[i], "/");
		if (!temp)
			pipex_error("Memory allocation error", env);
		free(env[i]);
		env[i] = ft_strdup(temp);
		free(temp);
		if (!env[i])
			pipex_error("Memory allocation error", env);
		i++;
	}
	return (env);
}

char	**make_env(char **envp)
{
	char	**env;
	char	*temp;
	size_t	i;

	i = 0;
	if (!envp || !envp[0])
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	temp = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	if (!temp)
		pipex_error("Memory allocation error", NULL);
	env = ft_split(temp, ':');
	if (!env)
		pipex_error("Memory allocation error", NULL);
	free(temp);
	return (add_slash_to_env(env));
}

void	command_not_found(char *command, t_pipex *pipex)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	wait(NULL);
	free(command);
	ft_free(pipex->env);
	ft_free(pipex->argv);
	free(pipex);
	exit(127);
}
