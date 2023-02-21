/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:39:45 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/21 16:43:09 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*s;
	char	**cmd_box;
	int		i;

	s = readline("test:");
	while (s)
	{
		i = -1;
		cmd_box = parse_argv(s);
		while(cmd_box[++i])
			printf("%s\n", cmd_box[i]);
		free(s);
		s = readline("test:");
	}
	exit(0);
}
