/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:03:47 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:26:29 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include "minirt.h"

typedef struct s_couple
{
	int				w;
	int				h;
}					t_couple;

typedef struct s_dcouple
{
	double			w;
	double			h;
}					t_dcouple;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct s_ray
{
	double			t;
	t_vect			pos;
	t_vect			dir;
}					t_ray;

typedef struct s_hit
{
	double			dist;
	t_vect			pos;
	t_vect			normal;
	char			*type;
}					t_hit;

t_rgb				int_to_rgb(const int r, const int g, const int b);
int					rgb_to_int(const t_rgb rgb);
t_rgb				char_to_rgb(const char *r, const char *g, const char *b);
t_rgb				mult_rgb_rgb(const t_rgb rgb, const t_rgb mult);
t_rgb				mult_rgb_double(const t_rgb rgb, const double mult);
t_rgb				add_rgb_rgb(const t_rgb rgb, const t_rgb add);
void				min_rgb(t_rgb *color);
t_ray				new_ray(const t_vect position, const t_vect direction);
t_rgb				get_color(const char *type, const void *object);

#endif
