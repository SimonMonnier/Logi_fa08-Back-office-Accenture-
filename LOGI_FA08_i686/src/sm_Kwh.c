/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_Kwh.c                        	                :+:      :+:    :+:   */
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

int				sm_Kwh(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> La derniere facture editee est-elle estimee (01/03)\n");
	sm_putstr("    de +++++ 100 Kwh par rapport a la depose (02/X1) qui suit ?\n");
	sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
		return 7;
	return 0;
}
