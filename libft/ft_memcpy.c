/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:11:42 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:11:43 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dsts;
	char	*srcs;
	size_t	i;

	srcs = (char *)src;
	dsts = (char *)dst;
	i = 0;
	if (ft_abs((int)dst, (int)src) >= (int)n)
	{
		while (i < n)
		{
			dsts[i] = srcs[i];
			i++;
		}
	}
	return (dst);
}
