/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_monthly.c             	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "sm_wait.h"
#include "sm_putstr.h"
#include "reply_tmp.h"
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

void				sm_monthly(t_reply_tmp *reply_tmp)
{
	double	monthly_result, monthly_tmp2, monthly_tmp;
	double	monthly_payment, redress, monthly;
	char	tmp[255];
	int	rturn;

	rturn = 2;
	while (rturn == 2)
	{
		sm_putstr("--> ENTREZ LE MONTANT DES ECHEANCES (/!\\ utiliser '.' pas ',' : 54.36):\n");
		scanf("%s", &tmp[0]);
		getchar();
		monthly = atof(tmp);
		if (monthly != 0)
		{
			printf("\n - Vous avez entre %.2f est-ce correct ?\n", monthly);
			sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
			sm_reboot_struct(reply_tmp);	
			sm_YesOrNo(reply_tmp);
			if (reply_tmp->reply == 1)
				rturn = 1;
		}
		else
			sm_putstr(" /!\\ ERREUR 'Caracteres non autorises' /!\\\n");
	}
	rturn = 2;
	while (rturn == 2)
	{
		sm_putstr("--> ENTREZ LE MONTANT DU REDRESSEMENT (utiliser '.' pas ',' : 54.36):\n");
		scanf("%s", &tmp[0]);
		getchar();
		redress = atof(tmp);
		if (redress != 0)
		{
			printf("\n - Vous avez entre %.2f est-ce correct ?\n", redress);
			sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
			sm_reboot_struct(reply_tmp);	
			sm_YesOrNo(reply_tmp);
			if (reply_tmp->reply == 1)
				rturn = 1;
		}
		else
			sm_putstr(" /!\\ ERREUR 'Caracteres non autorises' /!\\\n");
	}
	rturn = 2;
	while (rturn == 2)
	{
		sm_putstr("--> COMBIEN D'ECHEANCES ON DEJA ETE PAYEES ?\n");
		scanf("%s", &tmp[0]);
		getchar();
		monthly_payment = atof(tmp);
		if (monthly_payment < 11 && monthly_payment >= 0)
		{
			printf("\n - Vous avez entre %.2f est-ce correct ?\n", monthly_payment);
			sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");
			sm_reboot_struct(reply_tmp);	
			sm_YesOrNo(reply_tmp);
			if (reply_tmp->reply == 1)
				rturn = 1;
		}
		else
			sm_putstr(" /!\\ ERREUR 'Le nombre d'echeance doit etre < 11 & >= 1' /!\\\n");
	}
	monthly_tmp = monthly * 12;
	monthly_tmp += redress;
	monthly_tmp2 = monthly_tmp - (monthly * monthly_payment);
	monthly_result = monthly_tmp2 / (12 - monthly_payment);
	printf("\n--> Echeances re-calculees = '%.2f' Euro/Mois\n", monthly_result);
	sm_wait(reply_tmp);
}
