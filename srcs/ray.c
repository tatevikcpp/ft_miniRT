/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:20:38 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:20:39 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	new_ray(const t_vect position, const t_vect direction)
{
	t_ray	ray;

	ray.pos = position;
	ray.dir = direction;
	ray.t = INFINITY;
	return (ray);
}

t_ray	generate_ray(const t_camera camera, \
	const t_couple resolution, t_couple pixel)
{
	t_vect	vect_dir;

	vect_dir = set_vect_dir_cam(camera, resolution, pixel.h, pixel.w);
	return (new_ray(camera.pos, vect_dir));
}
