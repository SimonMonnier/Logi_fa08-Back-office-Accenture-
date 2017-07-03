/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_openM015.c                                      :+:      :+:    :+:   */
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

int				sm_openM015(t_reply_tmp *reply_tmp)
{

	if (reply_tmp->reply == 2)
	{
		sm_putstr("--> Mettre le cas 'EN COURS DE TRAITEMENT' dans Exel/OSA\n");
		sm_putstr("    avec en commentaires la date a laquelle\n");
		sm_putstr("    le delai de 30 jours sera passe\n");
		sm_putstr("    (pour que nous reprenions le cas)\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
		sm_wait(reply_tmp);
		return 2;
	}
	sm_putstr("--> Ouvrir la M015(pdf)\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer le PDL dans CRM\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Selectionner le contrat impacte par le redressement\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer la Synthese Client\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Confirmer l'accord commercial concerne\n");
	sm_wait(reply_tmp);
	sm_putstr("--> L'offre du client est-elle TEMPO (6 cadrans) ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Mettre le cas 'HORS PERIMETRE' dans Exel/OSA\n");
		sm_putstr("    avec en commentaires 'Client TEMPO'\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
		sm_wait(reply_tmp);
		return 2;
	}
	return 0;
}
