/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_nbr_M015.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sm_putstr.h"
#include "sm_YesOrNo.h"
#include "sm_reboot_struct.h"

void				sm_nbr_M015(t_reply_tmp *reply_tmp)
{
	sm_putstr("--> Y'a-t-il plusieurs M015 ?\n");
	sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
	sm_reboot_struct(reply_tmp);
	sm_YesOrNo(reply_tmp);
}
