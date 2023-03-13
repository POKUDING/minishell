/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:58:43 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/13 21:53:30 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_box(char **box)
{
	size_t	i;

	i = 0;
	while (box[i])
		free(box[i++]);
	free(box[i]);
	free(box);
}

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head && head->next)
	{
		tmp = head;
		head = head->next;
		free (tmp->cmd);
		free_box (tmp->argv);
		free (tmp);
	}
	free (head);
}
