//
// Created by Louis Laurent on 09/10/2022.
//

#ifndef FT_PING_FT_PING_H
#define FT_PING_FT_PING_H

# include "definitions.h"
# include "structures.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/ip_icmp.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <signal.h>
# include <memory.h>

int 			handle_params(int ac, char **av, t_params *params);
int 			ping(t_params *params);
void			help_param();
int				free_and_exit();
int				print_error(char *str, int code);
int				print_formatted_error(char *str, int code, char *param);
int				close_and_exit(t_ping ping, int code);
void			int_handler (int dummy);
unsigned short	checksum(void *b, int len);
int				resolve_dns(t_params *params);
int				create_icmp_socket (t_ping *ping, t_params *params);

// utils
size_t			ft_strlen(const char *str);
char *			ft_strcpy(char *dst, const char *src);

// ping structures

typedef struct	icmp_pckt
{
	struct icmphdr	hdr;
	char			msg[PING_PACKET_S-sizeof(struct icmphdr)];
}				ICMP_pckt;

#endif //FT_PING_FT_PING_H
