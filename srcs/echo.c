/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:44 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/06 15:43:03 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
}