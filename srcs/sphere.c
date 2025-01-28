/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:21:23 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:26:29 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	solve_quadratic(const t_vect point, double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = point.y * point.y - 4 * point.x * point.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * point.y / point.x;
		*x1 = -0.5 * point.y / point.x;
	}
	else
	{
		if (point.y > 0)
			q = -0.5 * (point.y + sqrt(discr));
		else
			q = -0.5 * (point.y - sqrt(discr));
		*x0 = q / point.x;
		*x1 = point.z / q;
	}
	if (*x0 > *x1)
		ft_swap(x0, x1);
	return (1);
}

int	intersect_sphere(const t_ray ray, const t_sphere sphere, t_hit *hit)
{
	double	x0;
	double	x1;
	t_vect	vect;

	vect = new_vect(ray.pos.x - sphere.pos.x, ray.pos.y - sphere.pos.y,
			ray.pos.z - sphere.pos.z);
	if (!solve_quadratic(new_vect(dot_product(ray.dir, ray.dir),
				2 * dot_product(ray.dir, vect),
				dot_product(vect, vect) - sphere.radius2), &x0, &x1))
		return (0);
	if ((x0 < 0 && x1 < 0) || (x0 > hit->dist && x1 > hit->dist))
		return (0);
	else if (x0 <= 0.)
		x0 = x1;
	else if (x1 <= 0.)
		x1 = x0;
	hit->dist = ft_min_float(x0, x1);
	hit->pos = add_vect(ray.pos, multi_vect(ray.dir, x1));
	hit->normal = normalize(sub_vect(hit->pos, sphere.pos));
	hit->pos = add_vect(hit->pos, multi_vect(hit->normal, EPSILON));
	return (1);
}

void	ray_spheres(const t_ray ray, const t_scene *scene, \
	t_hit *hit, void **object)
{
	t_list		*spheres;
	t_sphere	*sphere;

	spheres = scene->spheres;
	while (spheres->next)
	{
		sphere = (t_sphere *)(spheres->content);
		if (intersect_sphere(ray, *sphere, hit))
		{
			*object = sphere;
			ft_memcpy(hit->type, "sp", 2);
		}
		spheres = spheres->next;
	}
}
