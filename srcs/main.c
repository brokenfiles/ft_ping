/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:12:43 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/12 23:12:51 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ping.h"
#include "../includes/loop.h"

/*
 * Ping sends out ICMP packets by opening RAW socket
 * ICMP means Internet Control Message Protocol
 */

//struct ping_pkt
//{
//	struct icmphdr hdr;
//	char msg[PING_PACKET_S-sizeof(struct icmphdr)];
//};

int	main(int ac, char **av)
{
	t_params params;

	if (handle_params(ac, av, &params) == EXIT_FAILURE)
		return (free_and_exit());

	// handle the INT signal to stop the loop
	signal(SIGINT, int_handler);

	(void )ping_loop;
	return (ping(&params));

	// tests

	/*
	int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0) {
		char buffer[ 256 ];
		strerror_r( errno, buffer, 256 ); // get string message from errno, XSI-compliant version
		printf("Error %s\n", buffer);
		return (EXIT_FAILURE);
	}

	int ttl = 64;
	// set socket option at ip and ttl to 64
	setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl));

	struct timeval tv_out;
	tv_out.tv_sec = RECV_TIMEOUT;
	tv_out.tv_usec = 0;
	// set timeout of recv setting
	setsockopt(sockfd, SOL_IP, SO_RCVTIMEO, &tv_out, sizeof(tv_out));

	int flag = 1;
	struct ping_pkt pckt;
	int msg_count = 0;

	while (ping_loop) {
		flag = 1;
		bzero(&pckt, sizeof(pckt));
		pckt.hdr.type = ICMP_ECHO;
		pckt.hdr.un.echo.id = getpid();

		size_t i;
		for ( i = 0; i < sizeof(pckt.msg)-1; i++ )
			pckt.msg[i] = i+'0';

		pckt.msg[i] = 0;
		pckt.hdr.un.echo.sequence = msg_count++;
		pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

		struct sockaddr_in addr_con;

		char *ip_addr = dns_lookup(params.target, &addr_con);

		(void)flag;
//		usleep(1000);

		sendto(sockfd, &pckt, sizeof(pckt), 0,
			   (struct sockaddr*) &addr_con,
			   sizeof(addr_con));

		printf("ip address %s\n", ip_addr);

		ping_loop = 0;

	}

	printf("target : %s\n", params.target);
	printf("verbose : %d\n", params.verbose_param);
	printf("help : %d\n", params.help_param);
	return (EXIT_SUCCESS);
	 */
}
