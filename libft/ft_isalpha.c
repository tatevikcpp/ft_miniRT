/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:23 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:05:24 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int x)
{
	if (x >= 'A' && x <= 'Z')
		return (1);
	return (0);
}

static int	ft_islower(int x)
{
	if (x >= 'a' && x <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int x)
{
	if (ft_islower(x) || ft_isupper(x))
		return (1);
	return (0);
}
