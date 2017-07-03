/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_others_PAGE.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sm_wait.h"
#include "sm_putstr.h"
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

int				sm_others_PAGE(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Y'a-t-il d'autres 'cas PAGE' (Hors FA07-08)\n");
	sm_putstr("    sur le PDL qui nous concerne ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Mettre le cas PAGE 'HORS PERIMETRE'\n");
		sm_putstr("    dans Exel/OSA avec en commentaires :\n");
		sm_putstr("    - Presence d'autre cas PAGE XXXX\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
		sm_wait(reply_tmp);
		return 4;
	}
	sm_putstr("--> Y'a-t-il Presence d'une inversion de PDL/PCE\n");
	sm_putstr("    (cf.'Historique Relation Client') ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Mettre le cas 'HORS PERIMETRE' dans EXEL/OSA\n");
		sm_putstr("    avec en commentaires 'Inversion de PDL'\n\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n");
		sm_wait(reply_tmp);
		return 4;
	}
	sm_putstr("--> Quel est le cycle de facturation du client ?\n");
	sm_putstr(" /!\\ Tapez 1 pour 'NC' (Mensualisation) ou 2 pour 'BC/SC /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	reply_tmp->cycle_NC = 0;
	if (reply_tmp->reply == 1)
		reply_tmp->cycle_NC = 1;
	return 0;
}
