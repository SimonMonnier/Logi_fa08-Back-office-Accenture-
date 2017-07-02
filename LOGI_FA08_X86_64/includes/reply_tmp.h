/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply_tmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_TMP_H
#define REPLY_TMP_H

typedef struct	s_reply_tmp
{
	char	*tmp;
	char	yesORno[255], Date_start[255], Date_invoicing[255];
	int	reply_date_invoicing, sup_order;
	int	reply, i_tmp, Relay, cycle_NC, reply_date_start;
}	t_reply_tmp;

#endif
