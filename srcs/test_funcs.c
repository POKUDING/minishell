/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:41:48 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:13:09 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_token_list(t_token *head)
{
	size_t	i;

	while (head)
	{
		i = 0;
		printf("\n---------------------\n\n");
		printf("cmd : %s \n", head->cmd);
		while (head->argv && head->argv[i])
		{
			printf("argv%ld : %s\n", i, head->argv[i]);
			i++;
		}
		printf("operator %d \n", head->operator);
		head = head->next;
	}
}
