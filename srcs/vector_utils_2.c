/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:21:45 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:21:46 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	sign(double a)
{
	if (a < EPSILON && a > -EPSILON)
		return (1);
	return (fabs(a) / a);
}

t_vect	find_b(t_vect orient)
{
	if (orient.x < EPSILON && orient.x > -EPSILON)
	{
		if (orient.z < EPSILON && orient.z > -EPSILON)
			return (new_vect(1, 0, 0));
		return (new_vect(sign(orient.z), 0, 0));
	}
	else if (orient.z < EPSILON && orient.z > -EPSILON)
		return (new_vect(0, 0, -sign(orient.x)));
	return (new_vect(-sign(orient.z) * orient.z / orient.x, 0, sign(orient.z)));
}
