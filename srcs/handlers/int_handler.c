/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:11:39 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/11 13:43:48 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"
#include "../../includes/loop.h"

void int_handler (int dummy)
{
	(void) dummy;
	ping_loop = 0;
}