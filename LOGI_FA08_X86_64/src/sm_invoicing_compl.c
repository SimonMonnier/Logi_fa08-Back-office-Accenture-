/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_invoicing_compl.c                               :+:      :+:    :+:   */
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

int				sm_invoicing_compl(t_reply_tmp *reply_tmp)
{
	if (reply_tmp->i_tmp < 1)
	{
		sm_putstr("--> Y'a-t-il deja une facture complementaire\n");
		sm_putstr("    (document en 900...) sur la periode de redressement ?\n");
		sm_putstr(" /!\\ Tapez 1 (oui) ou Tapez 2 (non) /!\\\n");	
		sm_reboot_struct(reply_tmp);	
		sm_YesOrNo(reply_tmp);
		reply_tmp->i_tmp++;
		if (reply_tmp->reply == 1)
		{
			sm_putstr("--> Verifier que le ZOSARM deja effectue\n");
			sm_putstr("    est en correlation avec la M015\n");
			sm_putstr("    Si oui :\n    - Cloturer le PAGE\n");
			sm_putstr("    - Mettre le cas en OBSOLETE\n");
			sm_putstr("    dans le fichier Excel/OSA\n");
			sm_putstr("    (courrier et demande non necessaires)\n");
			sm_putstr(" /!\\ (Tapez ENTREE pour quitter) /!\\\n\n\n");
			sm_wait(reply_tmp);
			return 9;
		}
	}
	if (reply_tmp->cycle_NC == 1 && reply_tmp->Relay == 1)
		return 10;
	if (reply_tmp->cycle_NC == 0)
		return 10;
	return 0;
}
