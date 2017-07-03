/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_complaint_CRM.c                                 :+:      :+:    :+:   */
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

int				sm_complaint_CRM(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Y'a-t-il une reclamation sur CRM (boule rouge) ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> S'il y a plusieurs contrats :\n");
		sm_putstr("    - La reclamation concerne-t-elle\n");
		sm_putstr("      le contrat du cas PAGE ?\n");
		sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");	
		sm_reboot_struct(reply_tmp);	
		sm_YesOrNo(reply_tmp);
		if (reply_tmp->reply == 1)
		{
			sm_putstr("--> Mettre le cas 'HORS\n");
			sm_putstr("    PERIMETRE' dans Exel/OSA\n");
			sm_putstr("    avec en commentaires\n");
			sm_putstr("    'Reclamation' et passer\n");
			sm_putstr("    le cas PAGE sur le gestionnaire 'D-BORA'\n");
			sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
			sm_wait(reply_tmp);
			return 3;
		}
	}
	sm_putstr("--> Cliquer sur le masque 'cas PAGE'\n");
	sm_putstr("    de la synthese client\n");
	sm_wait(reply_tmp);
	return 0;
}
