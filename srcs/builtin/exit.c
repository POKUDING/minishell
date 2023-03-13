/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:14:20 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/13 21:52:47 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_arg(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			return (1);
		idx++;
	}
	return (0);
}

void	command_exit(char **arr)
{
	printf("exit\n");
	if (!arr[1])
		exit(1);
	if (check_arg(arr[1]))
	{	
		printf("minishell: exit: %s: numeric argument required\n", arr[1]);
		exit(1);
	}
	if (arr[2])
		printf("minishell: exit: too many arguments\n");
}