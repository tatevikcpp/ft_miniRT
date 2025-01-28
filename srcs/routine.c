/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:21:12 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:38:03 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_hit	*closest_object(const t_ray ray, \
	const t_scene *scene, void **object)
{
	t_hit	*hit;

	hit = malloc(sizeof(*hit));
	if (!hit)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	hit->type = malloc(3 * sizeof(char));
	if (!(hit->type))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	ft_bzero(hit->type, 3);
	hit->dist = INFINITY;
	ray_spheres(ray, scene, hit, object);
	ray_planes(ray, scene, hit, object);
	ray_cylinders(ray, scene, hit, object);
	if (!*hit->type)
		*object = NULL;
	return (hit);
}

static void	man_li(const t_scene *scene, t_rgb *diffuse,
		t_hit *hit, t_light *light)
{
	t_ray		to_light;
	t_hit		*hit_obstacle;
	void		*obstacle;
	double		normal_dot_light;

	obstacle = NULL;
	to_light = new_ray(hit->pos, sub_vect(light->pos, hit->pos));
	hit_obstacle = closest_object(to_light, scene, &obstacle);
	if (hit_obstacle->dist > distance(hit->pos, light->pos))
	{
		normal_dot_light = ft_max_float(dot_product(hit->normal, \
			to_light.dir), 0.0) / (distance(hit->pos, \
			light->pos) * (distance(hit->pos, light->pos)));
		*diffuse = add_rgb_rgb(*diffuse, \
			mult_rgb_double(light->color, normal_dot_light));
	}
	free(hit_obstacle->type);
	free(hit_obstacle);
}

void	manage_light(const t_scene *scene, t_hit *hit, t_rgb *color)
{
	t_rgb		diffuse;
	t_list		*lights;
	t_light		*light;

	lights = scene->lights;
	diffuse = int_to_rgb(0, 0, 0);
	while (lights->next)
	{
		light = (t_light *)lights->content;
		man_li(scene, &diffuse, hit, light);
		lights = lights->next;
	}
	diffuse = mult_rgb_double(diffuse, ALBEDO);
	*color = mult_rgb_rgb(add_rgb_rgb(scene->al->color, diffuse), *color);
	min_rgb(color);
}

static void	rout(t_thread *thread)
{
	t_hit	*hit;
	t_rgb	color;
	t_ray	ray;
	void	*object;

	color = int_to_rgb(0, 0, 0);
	ray = generate_ray(*thread->window->scene->camera,
			thread->window->scene->resolution, thread->start);
	hit = closest_object(ray, thread->window->scene, &object);
	if (object)
	{
		color = get_color(hit->type, object);
		if (dot_product(hit->normal, ray.dir) >= 0)
			hit->normal = minus_vect(hit->normal);
		manage_light(thread->window->scene, hit, &color);
	}
	free(hit->type);
	free(hit);
	ft_put_pixel(thread->window->img->data,
		thread->start, rgb_to_int(color));
}

void	*routine(void *thr)
{
	t_thread	*thread;

	thread = (t_thread *)thr;
	thread->limit.h = thread->start.h + thread->resolution.h;
	thread->limit.w = thread->start.w + thread->resolution.w;
	while (thread->start.h < thread->limit.h)
	{
		thread->start.w = thread->limit.w - thread->resolution.w;
		while (thread->start.w < thread->limit.w)
		{
			rout(thread);
			thread->start.w++;
		}
		thread->start.h++;
	}
	return ((void *)0);
}
