/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_finish.c                   	                :+:      :+:    :+:   */
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

void				sm_finish(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Creer demande sur CRM :\n");
	sm_putstr("    - Canal '04 interne'\n");
	sm_putstr("    - Code Motif 'D010'\n");
	sm_putstr("    - 'Importer trame' et l'adapter au contexte\n");
	sm_putstr("    - Bien preciser le montant du (des) redressemet(s)\n");
	sm_putstr("    - Preciser si mensualites recalculees\n");
	sm_putstr("    - Rattacher le M015\n");
	sm_wait(reply_tmp);
	sm_putstr("--> Creer courrier/mail (via 'Gerer les contrats'...)\n");
	sm_putstr("    'Redressement ERDF/GRDF' sur Edifuzz\n");
	sm_putstr("    - Mettre 'Correction d'index'\n");
	sm_putstr("    - Mettre 'Redressement manuel'\n"); 
	sm_putstr("      ou 'Les deux' si re-calcul de mensualites\n");
	sm_wait(reply_tmp);		
	sm_putstr("--> Cloturez le cas PAGE\n\n");
	sm_wait(reply_tmp);
	sm_putstr("By: Simon Monnier <s.monnier44440@gmail.com>\n");
	sm_putstr("	<https://github.com/SimonMonnier>\n\n\n");
	sm_wait(reply_tmp);
}
