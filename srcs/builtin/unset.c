/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:15:05 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/13 21:53:00 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	name_cmp(char *str, char *env, int name_len)
{
	int	idx;
	
	idx = 0;
	while (idx < name_len)
	{
		if (str[idx] != env[idx])
			return (1);
		idx++;
	}
	if ((str[idx] == '=' || !str[idx]) && !env[idx])
		return (0);
	return (1);	
}

int	check_unset_name(char *str, int name_len)
{
	int idx;
	int	flag;

	idx = 0;
	flag = 0;
	if (str[idx] >= '0' && str[idx] <= '9')
		flag = 1;
	while (idx < name_len)
	{
		if (!((str[idx] >= '0' && str[idx] <= '9')
			|| (str[idx] >= 'a' && str[idx] <= 'z')
			|| (str[idx] >= 'A' && str[idx] <= 'Z')
			|| (str[idx] == '_')))
			flag = 1;
		idx++;
	}
	if (flag)
	{
		write(1, "minishell: unset: `", 20);
		write (1, str, name_len);
		printf("' : not a valid identifier\n");
		return (1);
	}
	return (0);
}

void	del_node(t_envp_node *prev_node, t_envp_node *node)
{
	prev_node->next = node->next;
	free(node->name);
	free(node->value);
	free(node);
}

void	del_env(char *str, t_envp_node *env)
{
	t_envp_node *prev_node;
	
	if (!(ft_strncmp(str, "_", 1)) || check_unset_name(str, ft_strlen(str)))
		return ;
	prev_node = env;
	while (env)
	{
		if (!name_cmp(str, env->name, ft_strlen(str)))
			del_node(prev_node, env);
		prev_node = env;
		env = env->next;
	}
}

void	command_unset(char **arr, t_envp_node *env)
{
	int	idx;

	idx = 1;
	if (!arr[1])
		return ;
	else
	{
		while (arr[idx])
		{
			del_env(arr[idx], env);
			idx++;
		}
	}
}