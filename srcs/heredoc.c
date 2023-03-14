/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:13:02 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 16:24:24 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_doc(t_token *token, char *eof)
{
	char	*s;
	int		fd[2];

	s = readline("<");
	pipe(fd);
	token->in_fd = fd[0];
	while(ft_strncmp(s, eof, sizeof(eof)))
	{
		write(fd[1], s, ft_strlen(s));
		write(fd[1], "\n", 1);
		free(s);
		s = readline("<");
	}
	close(fd[1]);
	free(s);
}
