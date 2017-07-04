/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_date_redrss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sm_wait.h"
#include "sm_putstr.h"
#include "sm_putchar.h"
#include "reply_tmp.h"
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

int				sm_date_redrss(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> La date de debut de redressement est-elle posterieure (apres)\n");
	sm_putstr("    a la date de fin de la derniere facture recue par le client ?\n");   
	sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Nous sommes donc sur un cycle en cours\n");
		sm_wait(reply_tmp);
		sm_putstr("--> Decaler la date d'echeance du cas PAGE a j-15\n");
		sm_putstr("    de la date de la prochaine facture\n");
		sm_putstr("    (ex: UR = 1122NC -> mettre echeance du cas PAGE au 07/11\n");
		sm_wait(reply_tmp);
		sm_putstr("--> Le decalage de la date d'echeance donne-t-il\n");
		sm_putstr("    une date anterieur a la date du jour\n");
		sm_putstr("    ou tres proche (quelque jours) de la date du jour ?\n");
		sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
		sm_reboot_struct(reply_tmp);	
		sm_YesOrNo(reply_tmp);
		reply_tmp->i_tmp++;
		if (reply_tmp->reply == 2)
		{
			sm_putstr("--> Changer le gestionnaire du cas PAGE en RAF_MENS\n");
			sm_wait(reply_tmp);
			sm_putstr("--> Mettre le motif de transfert Z001 dans le cas PAGE\n");
			sm_wait(reply_tmp);		
			sm_putstr("--> Mettre en commentaire dans onglet 'Notes' du cas PAGE :\n");
			sm_putstr("    'Echeance du cas PAGE repoussee au JJ/MM/AAAA\n");
			sm_putstr("     car redressement sur cycle en cours\n");
			sm_wait(reply_tmp);
			sm_putstr("--> 'Creer demande' sur CRM avec en commentaires :\n");
			sm_putstr("    'Echeance du cas PAGE numero XXXX repoussee au JJ/MM/AAAA\n");
			sm_putstr("     car redressement sur cycle en cours\n");
			sm_wait(reply_tmp);
			sm_putstr("--> Creer courrier/mail (via 'Gerer les contrats'...)\n");
			sm_putstr("    'Redressement distributeur / Report cas PAGE' sur Edifuzz\n");
			sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
			sm_wait(reply_tmp);
			sm_putstr("--> Mettre le cas PAGE en CLOS dans Exel/OSA\n");
			sm_wait(reply_tmp);
			return 11;
		}
	}
	sm_putstr("--> Nous sommes donc sur un cycle facture ou a cheval\n");
	sm_wait(reply_tmp);
	return 0;
}
