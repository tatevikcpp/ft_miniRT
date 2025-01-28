/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:04:12 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:04:13 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct s_scene
{
	t_couple		resolution;
	t_ambient_light	*al;
	t_camera		*camera;
	t_list			*lights;
	t_list			*spheres;
	t_list			*planes;
	t_list			*cylinders;
}					t_scene;

#endif
