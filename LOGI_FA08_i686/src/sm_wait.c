/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_wait.c                              	        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonnier <s.monnier44440@gmail.com>        +#+  +:+       +#+        */
/*   	   <https://github.com/SimonMonnier>      +#+#+#+#+#+   +#+           */
/*   					               #+#    #+#             */
/*   Created: 2017/07/01 by smonnier	              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "reply_tmp.h"

void				sm_wait(t_reply_tmp *reply_tmp)

{
	reply_tmp->buf = NULL;
	reply_tmp->rtrn_read = read(0, reply_tmp->buf, 1);
	while ((reply_tmp->rtrn_read = getchar()) != '\n' && reply_tmp->rtrn_read != EOF)
		{}
}
