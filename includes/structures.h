//
// Created by Louis Laurent on 09/10/2022.
//

#ifndef FT_PING_STRUCTURES_H
#define FT_PING_STRUCTURES_H

#include <stdbool.h>
#include <netinet/in.h>

typedef struct	s_params
{
	char *	target;
	char	resolved_ip[INET_ADDRSTRLEN];

	bool	verbose_param;
	bool	help_param;
	int 	ttl_value;
	int		recv_timeout_value;
} t_params;

typedef struct	s_ping
{
	int		sockfd;
	char	*ip_addr;
}				t_ping;

#endif //FT_PING_STRUCTURES_H
