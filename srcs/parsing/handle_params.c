/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:19:19 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/12 16:14:15 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"

void	init_params(t_params *params)
{
	params->target				= NULL;
	params->help_param			= false;
	params->verbose_param		= false;
	params->ttl_value			= 64;
	params->recv_timeout_value	= RECV_TIMEOUT;

	bzero(params->resolved_ip, INET_ADDRSTRLEN);
}

void	parse_params (int ac, char **av, t_params *params)
{
	for (int i = 1; i < ac; i ++) {
		char *arg = av[i];
		if (arg[0] == '-' && ft_strlen(arg) > 0) { // it starts with a '-' so it's an argument
			switch (arg[1]) {
				case 'v':
					params->verbose_param = true; break;
				case 'h':
					params->help_param = true; break;
				default: //display help if the parameter is unknown
					params->help_param = true;
			}
		} else if (arg[0] != '-' && params->target == NULL) {
			params->target = arg;
		}
	}
}

int		handle_params(int ac, char **av, t_params *params)
{
	init_params(params);
	parse_params(ac, av, params);

	if (params->help_param || params->target == NULL) {
		help_param();
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}