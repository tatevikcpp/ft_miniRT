/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:21:39 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:21:40 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect	minus_vect(const t_vect vect)
{
	return (new_vect(-vect.x, -vect.y, -vect.z));
}

t_vect	add_vect(const t_vect vect1, const t_vect vect2)
{
	return (new_vect(vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z));
}

t_vect	sub_vect(const t_vect vect1, const t_vect vect2)
{
	return (new_vect(vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z));
}

t_vect	multi_vect(const t_vect vect, const double x)
{
	return (new_vect(vect.x * x, vect.y * x, vect.z * x));
}

double	dot_product(const t_vect vect1, const t_vect vect2)
{
	return (vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z);
}
