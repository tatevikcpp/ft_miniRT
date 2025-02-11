/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:22:05 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:22:06 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	zoom_in(const int keycode, t_window *w)
{
	t_camera	*camera;

	if (keycode != KEY_PLUS)
		return (0);
	camera = w->scene->camera;
	camera->pos = add_vect(camera->pos, camera->orientation);
	return (1);
}

int	zoom_out(const int keycode, t_window *w)
{
	t_camera	*camera;

	if (keycode != KEY_MINUS)
		return (0);
	camera = w->scene->camera;
	camera->pos = sub_vect(camera->pos, camera->orientation);
	return (1);
}
