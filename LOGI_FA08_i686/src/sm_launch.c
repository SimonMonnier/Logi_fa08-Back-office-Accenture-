/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_launch.c                              	        :+:      :+:    :+:   */
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

int				sm_launch(t_reply_tmp *reply_tmp)
{
	sm_putstr("/**************************************************************************/\n");
	sm_putstr("/*                                                                        */\n");
	sm_putstr("/*                                                     :::      ::::::::  */\n");
	sm_putstr("/*  ***LOGI_FA08***                                  :+:      :+:    :+:  */\n");
	sm_putstr("/*                                                 +:+ +:+         +:+    */\n");
	sm_putstr("/*  By: smonnier <s.monnier44440@gmail.com>      +#+  +:+       +#+       */\n");
	sm_putstr("/*        <https://github.com/SimonMonnier>    +#+#+#+#+#+   +#+          */\n");
	sm_putstr("/*                                                  #+#    #+#            */\n");
	sm_putstr("/*  Created: 2017/07/01 by smonnier                ###   ########.fr      */\n");
	sm_putstr("/*                                                                        */\n");
	sm_putstr("/**************************************************************************/\n\n");
	sm_putstr("      Logigramme pour traitement Back-office de cas 'PAGE FA08'.\n\n");
	sm_putstr("                 /!\\ (Tapez ENTREE pour continuer) /!\\\n\n");
	sm_wait(reply_tmp);	
	sm_putstr("--> Lancer EMMACL (ISU)\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Ouvrir le cas PAGE\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Le cas PAGE est-il deja cloture ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");		
	sm_reboot_struct(reply_tmp);
	sm_YesOrNo(reply_tmp);
	if (reply_tmp->reply == 1)
	{
		sm_putstr("--> Mettre le cas PAGE 'OBSOLETE'\n");
		sm_putstr("    dans Exel/OSA avec en commentaires :\n");
		sm_putstr("    - Cas PAGE deja cloture (courrier et demande non necessaires)\n");
		sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
		sm_wait(reply_tmp);
		return 1;
	}
	sm_putstr("--> Recuperer le PDL du cas PAGE\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Lancer le PDL dans SGE\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Ouvrir Onglet 'Historique d'affaires'\n");
	sm_wait(reply_tmp);
	return 0;
}
