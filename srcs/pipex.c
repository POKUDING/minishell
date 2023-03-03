/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:33:55 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 20:52:13 by junhyupa         ###   ########.fr       */
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
					 ft_split(find_env("PATH", env), ':'));
	if (!path)
		path = token.argv[0];
	if (execve(path, token.argv, env) == -1)
		error_control("command not found: ", token.argv[0], 127);
}

void	run_process(t_token *token)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1],1);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
	}
}

void	pipex(t_token *head)
{
	t_token	*tmp;

	tmp = head;
	while (tmp)
	{
		run_process(tmp);
		tmp = tmp->next;
	}
	dup2(1, 0);
}
