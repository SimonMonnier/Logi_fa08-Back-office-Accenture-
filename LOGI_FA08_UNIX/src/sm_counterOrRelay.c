/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_counterOrRelay.c                                :+:      :+:    :+:   */
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
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

int				sm_counterOrRelay(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> La M015 concerne-t-elle un Relais bloque\n");
	sm_putstr("    ou un Compteur bloque ?\n");
	sm_putstr(" /!\\ Tapez 1 pour Relais ou 2 pour Compteur /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	reply_tmp->i_tmp = 0;
	reply_tmp->Relay = 1;
	if (reply_tmp->reply == 2)
	{
		reply_tmp->Relay = 0;
		sm_putstr("--> Le changement de compteur est-il present sur SAP ?\n");
		sm_putstr("    (02/X1 puis 21/Z1)\n");
		sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n\n");
		sm_reboot_struct(reply_tmp);
		sm_YesOrNo(reply_tmp);
		if (reply_tmp->reply == 2)
		{
		sm_putstr("--> Mettre le cas 'HORS PERIMETRE' dans Exel/OSA\n");
		sm_putstr("    avec en commentaires 'Depose/Pose non presente'\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
		sm_wait(reply_tmp);
		return 5;
		}
	}
	return 0;
}
