/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:19:18 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:19:19 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_min_float(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_max_float(const float a, const float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_swap(void *a, void *b)
{
	void	*c;

	c = a;
	a = b;
	b = c;
}
