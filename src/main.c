/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 12:54:53 by kposthum      #+#    #+#                 */
/*   Updated: 2023/04/06 12:53:33 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

// void	f(void)
// {
// 	system("lsof -c pipex");
// 	system("leaks pipex");
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		pv1;
	int		pv2;

	if (argc < 5)
		pipex_error("Incorrect argument count\n", NULL);
	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (!pipex)
		pipex_error("Memory allocation error\n", NULL);
	pipex->argc = argc;
	pipex->env = make_env(envp);
	pipex->argv = strs_dup(argv);
	pv1 = pipe(pipex->fd1);
	pv2 = pipe(pipex->fd2);
	if (pv1 == ERROR || pv2 == ERROR)
		pipex_error("Failed to pipe\n", pipex->env);
	if (strncmp(argv[1], "here_doc", 8) == 0)
		return (forks_here_doc(pipex, envp));
	else
		return (forks(pipex, envp));
}
