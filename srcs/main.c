/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:39:45 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:03:12 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char*argv[], char **env)
{
	char	*s;
	t_token	*head;

	(void)argc;
	(void)argv;
	s = readline("shell:");
	while (*s)
	{
		head = parse_token(s, env);
		print_token_list(head);
		s = readline("test:");
	}
	free(s);
	exit(0);
}
