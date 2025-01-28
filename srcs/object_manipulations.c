/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manipulations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:19:59 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:20:01 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	camera_move(int keycode, t_window *window)
{
	if (zoom_in(keycode, window)
		|| zoom_out(keycode, window)
		|| move_up(keycode, window)
		|| move_down(keycode, window)
		|| move_left(keycode, window)
		|| move_right(keycode, window))
		return (1);
	return (0);
}

int	camera_rot(int keycode, t_window *window)
{
	if (rot_left(keycode, window)
		|| rot_right(keycode, window)
		|| rot_center_left(keycode, window)
		|| rot_center_right(keycode, window)
		|| rot_up(keycode, window)
		|| rot_down(keycode, window))
		return (1);
	return (0);
}

int	object_rot(int keycode, t_window *window)
{
	if (rot_x(keycode, window)
		|| rot_y(keycode, window)
		|| rot_z(keycode, window))
		return (1);
	return (0);
}
