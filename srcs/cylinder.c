/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:18:59 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:26:29 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double	solve_plane(t_vect o, t_vect d, t_vect plane_p, t_vect plane_nv)
{
	double	x;
	double	denom;

	denom = dot_product(plane_nv, d);
	if (denom == 0)
		return (INFINITY);
	x = (dot_product(plane_nv, sub_vect(plane_p, o))) / denom;
	if (x > EPSILON)
		return (x);
	return (INFINITY);
}

static t_vect	caps_int(t_ray ray, const t_cylinder cylinder, \
	double *id1, double *id2)
{
	t_vect	c2;

	c2 = add_vect(cylinder.pos, multi_vect(cylinder.dir, cylinder.height));
	*id1 = solve_plane(ray.pos, ray.dir, cylinder.pos, cylinder.dir);
	*id2 = solve_plane(ray.pos, ray.dir, c2, cylinder.dir);
	return (c2);
}

static double	caps_intersection(t_ray ray, const t_cylinder cylinder)
{
	double	id1;
	double	id2;
	t_vect	ip1;
	t_vect	ip2;
	t_vect	c2;

	c2 = caps_int(ray, cylinder, &id1, &id2);
	if (id1 < INFINITY || id2 < INFINITY)
	{
		ip1 = add_vect(ray.pos, multi_vect(ray.dir, id1));
		ip2 = add_vect(ray.pos, multi_vect(ray.dir, id2));
		if ((id1 < INFINITY && distance(ip1, cylinder.pos) <= cylinder.radius2)
			&& (id2 < INFINITY && distance(ip2, c2) <= cylinder.radius2))
		{
			if (id1 < id2)
				return (id1);
			return (id2);
		}
		else if (id1 < INFINITY && distance(ip1, cylinder.pos)
			<= cylinder.radius2)
			return (id1);
		else if (id2 < INFINITY && distance(ip2, c2) <= cylinder.radius2)
			return (id2);
	}
	return (INFINITY);
}

static double	cylinder_intersection(const t_ray ray, \
	const t_cylinder cylinder, int *is_on_side)
{
	double	cylinder_inter;
	double	caps_inter;

	*is_on_side = 0;
	cylinder_inter = cy_intersection(ray, cylinder);
	if (!cylinder.is_closed)
		caps_inter = INFINITY;
	else
		caps_inter = caps_intersection(ray, cylinder);
	if (cylinder_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cylinder_inter < caps_inter)
		{
			*is_on_side = 1;
			return (cylinder_inter);
		}
		return (caps_inter);
	}
	return (INFINITY);
}

void	ray_cylinders(const t_ray ray, const t_scene *scene, \
	t_hit *hit, void **object)
{
	t_list		*cylinders;
	t_cylinder	*cylinder;
	double		tmp;
	int			is_on_side;

	cylinders = scene->cylinders;
	while (cylinders->next)
	{
		cylinder = (t_cylinder *)(cylinders->content);
		tmp = cylinder_intersection(ray, *cylinder, &is_on_side);
		if (tmp < hit->dist && tmp > 0)
		{
			*object = cylinder;
			hit->dist = tmp;
			hit->pos = new_vect(tmp * ray.dir.x, tmp * ray.dir.y,
					tmp * ray.dir.z);
			hit->normal = cylinder->dir;
			if (is_on_side)
				hit->normal = sub_vect(get_closest_point_from_line(\
					cylinder->pos, cylinder->pos2, hit->pos), hit->pos);
			hit->normal = normalize(hit->normal);
			ft_memcpy(hit->type, "cy", 2);
		}
		cylinders = cylinders->next;
	}
}
