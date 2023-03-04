/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:05:00 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/04 16:48:39 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_SIGNAL_H
# define SET_SIGNAL_H

# include "../minishell.h"

void	do_sigterm(void);
void	do_sigint(int signum);
void	terminal_print(void);
void	terminal_no_print(void);

#endif
