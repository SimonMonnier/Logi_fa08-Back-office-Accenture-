/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reply_tmp.h"

int				sm_atoi(t_reply_tmp *reply_tmp)
{
	int			result;
	int			i;
	int			negative;

	result = 0;
	negative = 0;
	while (reply_tmp->yesORno && (*reply_tmp->yesORno == '\n' 
		|| *reply_tmp->yesORno == '\t' || *reply_tmp->yesORno == '\v' 
			|| *reply_tmp->yesORno == ' ' || *reply_tmp->yesORno == '\f' 
				|| *reply_tmp->yesORno == '\r'))
		*reply_tmp->yesORno += 1;
	i = 0;
	if (reply_tmp->yesORno[i] == '-' || reply_tmp->yesORno[i] == '+')
		negative = (reply_tmp->yesORno[i++] == '-') ? 1 : 0;
	while (reply_tmp->yesORno && reply_tmp->yesORno[i] >= '0' 
		&& reply_tmp->yesORno[i] <= '9')
	{
		result = result * 10 + reply_tmp->yesORno[i] - 48;
		i++;
	}
	if (negative == 1)
		return (result * -1);
	else
		return (result);
}
