/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_set_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:11:23 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 15:33:53 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	redirection(t_token *token)
// {
// 	return ;
// }



void	check_unexpected_token(t_token *head)
{
	while(head)
	{
		if (head->operator && \
			(!head->prev || head->prev->operator || !head->prev->argv ||\
			 !head->next || head->next->operator || !head->next->argv))
		error_control("minishell:", "syntax error near unexpected token `|'", 1);
		head = head->next;
	}
}

void	pre_set_process(t_token *head)
{
	check_unexpected_token(head);
}