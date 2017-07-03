/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_M015_reply.c                                    :+:      :+:    :+:   */
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

void				sm_M015_reply(t_reply_tmp *reply_tmp)
{
	if (reply_tmp->reply == 1)
	{
		sm_putstr("\n--> Analyser la situation et trouver\n");
		sm_putstr("    quelle est la M015 qui nous interesse\n\n");
		sm_wait(reply_tmp);
	}
	sm_putstr("--> La M015 a-t-elle ete transmise\n");
	sm_putstr("    au client il a plus de 30 jours ?\n");
	sm_putstr("    (cf. onglet 'Jalons')\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);	
	sm_YesOrNo(reply_tmp);
}
