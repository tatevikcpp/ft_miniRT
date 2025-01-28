/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:11:48 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:11:49 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsts;
	char	*srcs;
	size_t	i;

	dsts = (char *)dst;
	srcs = (char *)src;
	i = 0;
	if (dsts == srcs)
		return (0);
	if (dst < src)
	{
		while (i < len)
		{
			dsts[i] = srcs[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dsts[len] = srcs[len];
	}
	return (dst);
}
