/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:20:27 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:26:29 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	intersect_plane(const t_ray ray, const t_plane plane, t_hit *hit)
{
	double	denom;
	double	x;

	denom = dot_product(plane.normal, ray.dir);
	if (fabs(denom) > 0)
	{
		x = dot_product(sub_vect(plane.pos, ray.pos), plane.normal) / denom;
		if (x > EPSILON && x < hit->dist)
		{
			hit->normal = normalize(plane.normal);
			hit->pos = add_vect(ray.pos, multi_vect(ray.dir, x));
			hit->pos = add_vect(hit->pos,
					multi_vect(hit->normal, EPSILON));
			hit->dist = x;
			return (1);
		}
	}
	return (0);
}

void	ray_planes(const t_ray ray, const t_scene *scene,
	t_hit *hit, void **object)
{
	t_list		*planes;
	t_plane		*plane;

	planes = scene->planes;
	while (planes->next)
	{
		plane = (t_plane *)(planes->content);
		if (intersect_plane(ray, *plane, hit))
		{
			*object = plane;
			ft_memcpy(hit->type, "pl", 2);
		}
		planes = planes->next;
	}
}
