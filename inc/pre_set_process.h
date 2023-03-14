/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_set_process.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:20:55 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/14 13:40:43 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_SET_PROCESS_H
# define PRE_SET_PROCESS_H

# include "../minishell.h"

void	check_unexpected_token(t_token *head);
void	pre_set_process(t_token *head);

#endif

