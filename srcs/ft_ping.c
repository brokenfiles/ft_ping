/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:53:17 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/12 23:13:27 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"
#include "../includes/loop.h"

int loop (t_params *params, t_ping ping)
{
	(void)params;
	(void)ping;
	while (ping_loop) {
		usleep(1000000);
		write(1, "Ping...\n", 8);
	}

	return (EXIT_SUCCESS);
}

int	ping(t_params *params)
{
	t_ping	ping;

	if (create_icmp_socket(&ping, params) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	if (resolve_dns(params) == EXIT_FAILURE)
		return (close_and_exit(ping, EXIT_FAILURE));

	printf("PING %s (%s) %lu(%lu) bytes of data.", params->target, params->resolved_ip, sizeof(ICMP_pckt),
		   sizeof(ICMP_pckt) + sizeof(struct ip));

//	if (loop(params, ping) == EXIT_FAILURE)
//		return (close_and_exit(ping, EXIT_FAILURE));

	return (close_and_exit(ping, EXIT_SUCCESS));
}