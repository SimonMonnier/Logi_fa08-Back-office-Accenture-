/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				main(void)
{
	t_reply_tmp		reply_tmp;

	if (sm_launch(&reply_tmp) == 1)
		return 0;
	sm_nbr_M015(&reply_tmp);
	sm_M015_reply(&reply_tmp);
	if (sm_openM015(&reply_tmp) == 2)
		return 0;
	if (sm_complaint_CRM(&reply_tmp) == 3)
		return 0;
	if (sm_others_PAGE(&reply_tmp) == 4)
		return 0;
	if (sm_counterOrRelay(&reply_tmp) == 5)
		return 0;
	if (reply_tmp.Relay < 1)
	{	
		if (sm_invoicing(&reply_tmp) == 6)
		{
			if (sm_Kwh(&reply_tmp) == 7)
			{
				if (sm_error_message(&reply_tmp) == 8)
					return 0;
				sm_invoicing_balance(&reply_tmp);
			}
		}
	}
	if (sm_invoicing_compl(&reply_tmp) == 9)
		return 0;
	else if (sm_invoicing_compl(&reply_tmp) != 10)
		{
			if (sm_date_redrss(&reply_tmp) == 11)
			return 0;
		}
	sm_order_calc(&reply_tmp);
	sm_supp_order(&reply_tmp);
	sm_finish(&reply_tmp);
	return 0;
}
