/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:33:55 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/04 21:40:45 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_path(char *cmd, char **paths)
{
	int		i;
	char	*rtn;

	i = 0;
	while (paths[i])
	{
		rtn = ft_strjoin(paths[i++], cmd);
		if (access(rtn, F_OK) == 0)
		{
			free(cmd);
			free_box(paths);
			return (rtn);
		}
		free(rtn);
	}
	free_box(paths);
	free(cmd);
	return (0);
}

void	executer(t_token token, t_envp_node *env)
{
	char	*path;

	path = find_path(ft_strjoin("/", token.argv[0]), \
					 ft_split(find_env(ft_strdup("PATH"), env), ':'));
	if (!path)
		path = token.argv[0];
	if (execve(path, token.argv, make_envbox(env)) == -1)
		error_control("command not found: ", token.argv[0], 127);
}

void	run_process(t_token *token, t_envp_node *env)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1],1);
		close(fd[0]);
		executer(*token, env);
	}
	else
	{
		dup2(fd[0],0);
		close(fd[1]);
	}
}

void	pipex(t_token *head, t_envp_node *env)
{
	t_token	*tmp;
	int		status;
	pid_t	pid;

	tmp = head;
	pid = fork();
	if (pid != 0)
	{
		wait(&status);
		return ;
	}
	while (tmp->next)
	{
		if(!tmp->operator)
			run_process(tmp, env);
		tmp = tmp->next;
	}
	executer(*tmp , env);
}
