/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_error_message.c                                 :+:      :+:    :+:   */
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

int				sm_error_message(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Prendre le numero de document le plus ancien\n");
	sm_putstr("    lie a la facture estimee (hors 900...)\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer un EA20 avec ce numero de document et cliquer sur 'journal'\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Un message d'erreur d'archivage est-il present ?\n");
	sm_putstr("    (document archive ou periode d'archivage)\n");
	sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Mettre le cas 'HORS PERIMETRE' dans Exel/OSA\n");
		sm_putstr("    avec en commentaires 'Document archive'\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
		sm_wait(reply_tmp);
		return 8;
	}
	return 0;
}
