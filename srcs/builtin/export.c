/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:42:18 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/13 21:52:52 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	change_value(char *str, t_envp_node *node)
{
	int	find_idx;
	
	find_idx = find_char(str, '=');
	if (find_idx)
	{
		free(node->value);
		node->value = ft_strdup(&str[find_idx + 1]);
	}
}

int	check_name(char *str, int name_len)
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
		write(1, "minishell: export: `", 21);
		write (1, str, name_len);
		printf("' : not a valid identifier\n");
		return (1);
	}
	return (0);
}
void	add_env(char *str, t_envp_node *env)
{
	t_envp_node	*temp;
	int			name_len;

	temp = env;
	name_len = find_char(str, '=');
	if (!name_len)
		name_len = ft_strlen(str);
	if (!(ft_strncmp(str, "_", 1)) || check_name(str, name_len))
		return ;
	while (env)
	{
		if (!name_cmp(str, env->name, name_len))
		{
			change_value(str, env);
			return ;
		}
		env = env->next;
	}
	make_node(temp, str);
}

void	print_export_env(t_envp_node *env)
{
	while (env)
	{
		if (env->value)
			printf("declare -x %s=\"%s\"\n", env->name, env->value);
		else if (env->value == 0)
			printf("declare -x %s\n", env->name);
		env = env->next;
	}

}

void	command_export(char **arr, t_envp_node *env)
{
	int	idx;

	idx = 1;
	if (!arr[1])
		print_export_env(env);
	else
	{
		while (arr[idx])
		{
			add_env(arr[idx], env);
			idx++;
		}
	}
}

