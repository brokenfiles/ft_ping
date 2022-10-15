/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:54:47 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/09 20:00:09 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"

void	help_param()
{
	printf("usage: ft_ping [-vh] target\n"
		   "            [-v] verbose output\n"
		   "            [-h] display help and exit\n");
}