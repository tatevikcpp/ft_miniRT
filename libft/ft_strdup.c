/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:12:32 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:12:35 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1);
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (0);
	i = ft_strlcpy(ptr, s1, i + 1);
	return (ptr);
}
