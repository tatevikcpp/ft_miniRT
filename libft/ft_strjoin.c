/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:12:49 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:12:50 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, i + 1);
	ft_strlcat(ptr, s2, i + j + 1);
	return (ptr);
}
