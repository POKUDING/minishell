/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:33:55 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 16:20:50 by junhyupa         ###   ########.fr       */
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

	if (!token.argv)
		exit(0);
	path = find_path(ft_strjoin("/", token.argv[0]), \
					 ft_split(find_env(ft_strdup("PATH"), env), ':'));
	if (!path)
		path = token.argv[0];
	if (execve(path, token.argv, make_envbox(env)) == -1)
		error_control("minishell: command not found: ", token.argv[0], 127);
}

void	connect_pipe(t_token *token)
{
	int	fd[2];

	if (!token->next || !token->next->operator)
		return ;
	pipe(fd);
	token->next->out_fd = fd[0];
	token->next->in_fd = fd[1];
}

void	close_pipe(t_token *token)
{
	close(token->in_fd);
	close(token->out_fd);
}

void	run_process(t_token *token, t_envp_node *env)
{
	connect_pipe(token);
	token->pid = fork();
	if (token->pid == 0)
	{
		if (token->in_fd)
			dup2 (token->in_fd, 0);
		dup2(token->next->in_fd, 1);
		close_pipe(token->next);
		executer(*token, env);
	}
	else
	{
		dup2(token->next->out_fd, 0);
		close_pipe(token->next);
	}
}

void	end_process(t_token *head, t_token *token, t_envp_node *env)
{
	int	status;
	
	token->pid = fork();
	if (token-> pid == 0)
	{
		if (token->in_fd)
			dup2(token->in_fd, 0);
		executer(*token, env);
	}
	else
	{
		close(0);
		close(1);
		close(token->in_fd);
		close(token->out_fd);
		while (head)
		{
			if (!head->operator)
				waitpid(head->pid, &status, 0);
			head = head->next;
		}
		exit (0);
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
	pre_set_process(head);
	while (tmp->next)
	{
		if (!tmp->operator)
		{
			run_process(tmp, env);
			close(tmp->in_fd);
			close(tmp->out_fd);
		}
		tmp = tmp->next;
	}
	end_process(head, tmp, env);
}
