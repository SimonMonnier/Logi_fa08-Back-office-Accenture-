/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include "reply_tmp.h"

int				sm_launch(t_reply_tmp *reply_tmp);
void				sm_nbr_M015(t_reply_tmp *reply_tmp);
void				sm_M015_reply(t_reply_tmp *reply_tmp);
int				sm_openM015(t_reply_tmp *reply_tmp);
int				sm_complaint_CRM(t_reply_tmp *reply_tmp);
int				sm_others_PAGE(t_reply_tmp *reply_tmp);
int				sm_counterOrRelay(t_reply_tmp *reply_tmp);
int				sm_invoicing(t_reply_tmp *reply_tmp);
int				sm_Kwh(t_reply_tmp *reply_tmp);
int				sm_error_message(t_reply_tmp *reply_tmp);
int				sm_invoicing_balance(t_reply_tmp *reply_tmp);
int				sm_invoicing_compl(t_reply_tmp *reply_tmp);
int				sm_date_redrss(t_reply_tmp *reply_tmp);
void				sm_order_calc(t_reply_tmp *reply_tmp);
void				sm_supp_order(t_reply_tmp *reply_tmp);
void				sm_finish(t_reply_tmp *reply_tmp);

#endif
