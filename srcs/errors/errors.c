/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:48:59 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/12 16:09:35 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"

int	print_error(char *str, int code)
{
	fprintf(stderr, "%s\n", str);
	return (code);
}

int	print_formatted_error(char *str, int code, char *param)
{
	fprintf(stderr, str, param);
	return (code);
}

int	close_and_exit(t_ping ping, int code)
{
	close(ping.sockfd);
	return (code);
}