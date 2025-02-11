/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:03:53 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:03:54 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "basics.h"

typedef struct s_ambient_light
{
	double			ratio;
	t_rgb			color;
}					t_ambient_light;

typedef struct s_camera
{
	t_vect			pos;
	t_vect			orientation;
	t_vect			up;
	t_vect			b;
	double			fov;
}					t_camera;

typedef struct s_light
{
	t_vect			pos;
	t_rgb			color;
	double			ratio;
}					t_light;

typedef struct s_sphere
{
	t_vect			pos;
	t_rgb			color;
	double			radius2;
	double			reflec;
}					t_sphere;

typedef struct s_plane
{
	t_vect			pos;
	t_vect			normal;
	t_rgb			color;
}					t_plane;

typedef struct s_cylinder
{
	t_vect			pos;
	t_vect			pos2;
	t_vect			dir;
	double			radius2;
	double			height;
	t_rgb			color;
	int				is_closed;
}					t_cylinder;

#endif
