/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_order_calc.c                                    :+:      :+:    :+:   */
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

void				sm_order_calc(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Y'a-t-il presence d'un ordre de calcul vide\n");
	sm_putstr("    (rouge) sur l'installation ?\n");	
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);
	sm_YesOrNo(reply_tmp);
	reply_tmp->sup_order = 0;
	if (reply_tmp->reply == 1)
	{
		reply_tmp->sup_order = 1;
		sm_putstr("--> Supprimer l'ordre de calcul via 'EL37'\n");
		sm_wait(reply_tmp);
	}
	sm_putstr("--> La periode de redressement est-elle\n");
	sm_putstr("    a cheval sur 2015 et 2016 ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Utiliser CRAF pour repartir la consomation\n");
		sm_putstr("    anterieur a 2015 et post 2016\n");
		sm_wait(reply_tmp);
	}
	sm_putstr("--> Creer le ou les ZOSARM (via 'Facture Complementaire')\n");
	sm_putstr("    en facturation ou annulation.\n");
	sm_putstr("    /!\\ RAPPELS !!! /!\\\n");
	sm_putstr("    - Bien faire attention au numero du contrat impacte\n");
	sm_putstr("    - Cadran 1: Base, Heures Creuses, Jours Pointes ou Gaz\n");
	sm_putstr("    - Cadran 2: Heures Pleines, Jours Normaux\n");
	sm_putstr("    - Ne jamais choisir 'Annulation & Facturation' sur le meme ZOSARM\n");
	sm_putstr("    - Faire attention a ne pas choisir 'Annulation'\n");
	sm_putstr("      au lieu de 'Facturation' et inversement\n");
	sm_putstr("    - Mettre date de fin de contrat dans 'date du redressement'\n");
	sm_putstr("      pour les contrats resilies\n");	
	sm_putstr("    - Bien noter les montants TTC des ZOSARM\n");
	sm_putstr("      (cliquer sur 'Voir' et 'Simulation de facture' a la fin du ZOSARM)\n");
	sm_wait(reply_tmp);
}
