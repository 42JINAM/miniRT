/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:27:37 by jinam             #+#    #+#             */
/*   Updated: 2025/02/20 20:58:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "miniRT_enum.h"
typedef struct s_coordinates {
  float x;
  float y;
  float z;
} t_coordinates; 

typedef struct s_colors{
  int r;
  int g;
  int b;
} t_colors;

typedef struct s_ambient {
  float     ratio;
  t_colors  rgb;
} t_ambient;

typedef struct s_camera {
  t_coordinates view_point;
  t_coordinates orientation;
  int           fov;
} t_camera;

typedef struct  s_light {
  t_coordinates light_point;
  float         brightness;
} t_light;

typedef struct  s_object {
  int           id;
  t_coordinates coordinates;
  float         diameter;
  t_colors      rgb;
  t_coordinates vector;
  float         height;
  s_object      *next;
} t_object;

typedef struct  s_scene{
  t_ambient ambient;
  t_camera  camera;
  t_light   light;
  t_object  *objs;
} t_scene;

int	open_rtfile(const char *rt_file);
#endif
