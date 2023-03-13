/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/builtin/echo.c
/*   Created: 2023/03/06 15:38:44 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/13 21:52:33 by junhyupa         ###   ########.fr       */
=======
/*   Created: 2023/03/03 21:05:56 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/05 18:14:23 by junhyupa         ###   ########.fr       */
>>>>>>> 28add55d43a6124e70152ba19aa65c083b2a757e:srcs/builtin.c
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_echo_option(char *option)
{
	int	idx;

	idx = 0;
	if (!option)
		return (0);
	if (ft_strncmp(option, "-n", 2))
		return (0);
	idx = 2;
	while (option[idx])
	{
		if (option[idx] != 'n')
			return (0);
		idx++;
	}
	return (1);
}

void	command_echo(char **str)
{
	int	idx;
	int	option;

	option = 0;
	idx = 1;
	while (check_echo_option(str[idx]))
	{
		option = 1;
		idx++;
	}
	while (str[idx])
	{
		printf("%s", str[idx]);
		if (str[idx + 1] != 0)
			printf(" ");
		idx++;
	}
	if (option == 0)
		printf("\n");
<<<<<<< HEAD:srcs/builtin/echo.c
}
=======
}

void	command_pwd(void)
{
	char	buff[1000];

	getcwd(buff, 1000);
	printf("%s\n", buff);
}

void	command_env(t_envp_node *env)
{
	t_envp_node	*temp;

	temp = env;
	while (temp)
	{
		if (temp->value)
			printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
}

// void	add_env(char *envp, t_envp_node *env)
// {
// 	t_envp_node	*temp;

// 	temp = env;
// 	while (temp)
// 	{
// 		if ()
// 		{
// 			node->value = ;
// 		}
// 		else
// 			make_node(par, arr[idx++]);
// 		temp = temp->next;
// 	}
// }

void	print_export_env(t_envp_node *env)
{
	t_envp_node	*temp;

	temp = env;
	while (temp)
	{
		if (temp->value)
			printf("declare -x %s=\"%s\"\n", temp->name, temp->value);
		else
			printf("declare -x %s\n", temp->name);
		temp = temp->next;
	}
}

// void	command_export(char **arr, t_envp_node *env)
// {
// 	int	idx;

// 	idx = 1;
// 	if (!arr[1])
// 		print_export_env(env);
// 	else
// 	{
// 		while (arr[idx++])
// 			add_env(arr[idx], env);
// 	}

// }
>>>>>>> 28add55d43a6124e70152ba19aa65c083b2a757e:srcs/builtin.c
