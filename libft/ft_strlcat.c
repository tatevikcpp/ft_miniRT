/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:12:57 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:12:58 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;

	lendst = ft_strlen(dst);
	if (lendst > dstsize || dstsize == 0)
		return (dstsize + ft_strlen(src));
	return (lendst + ft_strlcpy(dst + lendst, src, dstsize - lendst));
}
