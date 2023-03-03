/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:06:36 by jisulee           #+#    #+#             */
/*   Updated: 2023/03/03 21:28:09 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include "../minishell.h"

void	set_signal(void);
void	signal_ign(void);
void	signal_dfl(void);
void	do_sigterm(void);
void	do_sigint(int signum);
void	terminal_print(void);
void	terminal_no_print(void);

#endif
