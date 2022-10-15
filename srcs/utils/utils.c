/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaurent <louislaurent@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:34:20 by louislaurent      #+#    #+#             */
/*   Updated: 2022/10/11 21:52:16 by louislaurent     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ping.h"

size_t	ft_strlen(const char *str)
{
	size_t	len = 0;
	while (str[len])
		len++;
	return len;
}

char *	ft_strcpy(char *dst, const char *src)
{
	size_t src_len = ft_strlen(src), dst_len = ft_strlen(dst), i;
	for (i = dst_len; i < src_len + dst_len; i ++) {
		dst[i] = src[i - dst_len];
	}
	dst[i] = '\0';
	return (dst);
}