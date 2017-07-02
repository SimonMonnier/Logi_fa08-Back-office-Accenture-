/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_invoicing_balance.c                             :+:      :+:    :+:   */
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

int				sm_invoicing_balance(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Lancer 'Corriger facture' pour annuler facture estimee\n");
	sm_putstr("    (Date du jour, Motif 'Divers') :\n");
	sm_putstr("    - Annuler le rapprochement --> OUI\n");
	sm_putstr("    - Annuler document de facturation manuelle (en 900..)--> NON\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer EL29 pour corriger en Z1 la derniere\n");
	sm_putstr("    releve estime avant la depose\n");
	sm_putstr("    (la remplacer pour la releve de depose)\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer EASIBI :\n");
	sm_putstr("    - avec l'installation ou le contrat\n");
	sm_putstr("    - en decochant 'Saisir OrdCalFactr...'\n");
	sm_putstr("    - en cochant 'Entrer dans calc. de facturation'\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer sur CRM 'Difficultes de paiement/Creer un blocage'\n");
	sm_wait(reply_tmp);	
	sm_putstr("--> Selectionner la piece 'AF' :\n");
	sm_putstr("    - Cette piece est-elle d'un montant debiteur ou crediteur ?\n");
	sm_putstr(" /!\\ Tapez 1 pour Crediteur (XX,XX E)");
	sm_putstr(" ou Tapez 2 pour Debiteur (-XX,XX E) /!\\\n");		
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Cochez les 3 blocages (Paiement, Interets et Relance)\n");
		sm_wait(reply_tmp);
	}
	else
	{
		sm_putstr("--> Cochez le dernier blocage (Paiement/Decaissement)\n");
		sm_wait(reply_tmp);
	}
	return 0;
}
