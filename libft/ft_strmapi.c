/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:13:17 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:13:18 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	if (s == NULL)
		return (0);
	j = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * j + 1);
	if (!ptr)
		return (0);
	while (++i < j)
		ptr[i] = f(i, s[i]);
	ptr[j] = '\0';
	return (ptr);
}
