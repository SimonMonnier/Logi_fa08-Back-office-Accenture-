/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_supp_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sm_wait.h"
#include "sm_putstr.h"
#include "reply_tmp.h"
#include "sm_monthly.h"
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

void				sm_supp_order(t_reply_tmp *reply_tmp)
{
	if (reply_tmp->sup_order == 1)
	{
		sm_putstr("--> Recreer l'ordre vide (rouge)\n");
		sm_putstr("    supprime a sa date d'origine via EASIBI\n");
		sm_wait(reply_tmp);
	}
	if (reply_tmp->cycle_NC == 1)
	{
		sm_putstr("--> Aller, via la synthese client CRM sur le solde client :\n");
		sm_putstr("    - Le nombre d'echeances restant a regler\n");
		sm_putstr("      par le client est-il superieur a 2 ?\n");
		sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
		sm_reboot_struct(reply_tmp);	
		sm_YesOrNo(reply_tmp);
		if (reply_tmp->reply == 1)
		{	
			sm_putstr("--> Re-calcul des echeances :\n");
			sm_monthly(reply_tmp);
			sm_putstr("--> Le montant des echeances versees par le client\n");
			sm_putstr("    est-il incoherent avec sa consommation ?\n");
			sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
			sm_reboot_struct(reply_tmp);	
			sm_YesOrNo(reply_tmp);
			if (reply_tmp->reply == 1)
			{
				sm_putstr("--> Modifier les echeances du client via CRM\n");
				sm_putstr("    'Modes de paiement/Modifier montants sans index'\n");
				sm_wait(reply_tmp);
			}
		}
	}
}
