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

#include <stdio.h>
#include "reply_tmp.h"

void				sm_wait(t_reply_tmp *reply_tmp)

{
	int			i;

	scanf("%c", &reply_tmp->tmp[0]);
	while ((i = getchar()) != '\n' && i != EOF)
		{}
}
