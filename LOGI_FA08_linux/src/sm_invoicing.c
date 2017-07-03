/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_invoicing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sm_putstr.h"
#include "reply_tmp.h"
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

int				sm_invoicing(t_reply_tmp *reply_tmp)
{
	if (reply_tmp->cycle_NC == 1)
	{
		sm_putstr("--> La derniere facture editee");
		sm_putstr(" (MR = 01 dans historique de releves)\n");
		sm_putstr("    est-elle avant la depose (02/X1) ?\n");
		sm_putstr(" /!\\ Tapez 1(oui)");
		sm_putstr(" ou 2(non) /!\\\n");
		sm_reboot_struct(reply_tmp);	
		sm_YesOrNo(reply_tmp);
		if (reply_tmp->reply == 1)
			return 6;
	}
	return 0;
}
