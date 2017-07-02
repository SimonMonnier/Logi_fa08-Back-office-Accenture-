/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_YesOrNo.c      	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "sm_atoi.h"
#include "sm_putstr.h"
#include "reply_tmp.h"

void				sm_YesOrNo(t_reply_tmp *reply_tmp)
{
	while (reply_tmp->reply < 1 || reply_tmp->reply > 2)
	{
		scanf("%s", &reply_tmp->yesORno[0]);
		reply_tmp->reply = sm_atoi(reply_tmp);
		getchar();
		if (reply_tmp->reply < 1 || reply_tmp->reply > 2)
		{
			sm_putstr(" /!\\ Tapez 1(oui) ou 2(non) /!\\\n");
		}
	}
}
