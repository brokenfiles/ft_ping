/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:49:34 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/12 15:07:57 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"

/**
 * Creates and configures the ICMP socket
 */
int	create_icmp_socket (t_ping *ping, t_params *params)
{
	struct timeval	tv_out;

	tv_out.tv_sec = params->recv_timeout_value;
	tv_out.tv_usec = 0;

	ping->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->sockfd < 0)
		return (print_error("permission denied, contact your administrator", EXIT_FAILURE));
	// set socket option at ip and ttl to 64
	if (setsockopt(ping->sockfd, SOL_IP, IP_TTL, &params->ttl_value, sizeof(params->ttl_value)) != 0)
		return (print_error("cannot set socket option (ttl)", EXIT_FAILURE));
	// set timeout of recv setting
	if (setsockopt(ping->sockfd, SOL_IP, SO_RCVTIMEO, &tv_out, sizeof(tv_out)) != 0)
		return (print_error("cannot set socket option (recv timeout)", EXIT_FAILURE));

	return (EXIT_SUCCESS);
}