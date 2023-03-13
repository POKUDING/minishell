/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:03:53 by junhyupa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/05 18:15:25 by junhyupa         ###   ########.fr       */
=======
/*   Updated: 2023/03/13 21:56:29 by junhyupa         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_envp_node	*env;
	t_token		*head;

	if (argc > 1 && argv[1])
		return (0);
	env = get_envp(envp);
	set_signal();
	while (1)
	{
		line = readline("minishell$  ");
		if (!line)
			do_sigterm();
		head = parse_token(line, env);
<<<<<<< HEAD
		if (head)
			pipex(head, env);
=======
		pipex(head, env);
>>>>>>> master
		add_history(line);
		free(line);
	}
}
