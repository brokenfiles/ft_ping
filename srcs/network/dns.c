/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:51:26 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/12 16:30:22 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"

int		resolve_dns(t_params *params)
{
	struct addrinfo hints, *res;

	memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_CANONNAME;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(params->target, NULL, &hints, &res) != 0)
		return print_formatted_error("ft_ping: %s: Name or service not known", EXIT_FAILURE, params->target);

	struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
	void *addr = &(ipv4->sin_addr);

	inet_ntop(res->ai_family, addr, params->resolved_ip, INET_ADDRSTRLEN);

	freeaddrinfo(res);

	return (EXIT_SUCCESS);
}