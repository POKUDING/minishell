/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:05:00 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/03 21:27:15 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_SIGNAL_H
# define SET_SIGNAL_H

# include "../minishell.h"

void	signal_heredoc(void);
void	signal_dfl(void);
void	signal_ign(void);
void	set_signal(void);

#endif
