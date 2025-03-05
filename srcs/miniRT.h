/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:27:37 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 19:26:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "../libft/libft/libft.h"
# include "miniRT_enum.h"

typedef struct s_coordinates
{
	float	x;
	float	y;
	float	z;
}	t_coordinates;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_ambient
{
	int			status;
	float		ratio;
	t_colors	rgb;
}	t_ambient;

typedef struct s_camera
{
	int				status;
	t_coordinates	view_point;
	t_coordinates	orientation;
	int				fov;
}	t_camera;

typedef struct s_light
{
	int				status;
	t_coordinates	light_point;
	float			brightness;
}	t_light;

typedef struct s_object
{
	int				id;
	t_coordinates	coordinates;
	float			diameter;
	t_colors		rgb;
	t_coordinates	vector;
	float			height;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	int			parsing_state;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_object	*objs;
}	t_scene;

/*parsing*/

int		parsing(const char *rt_file, t_scene *scene);
int		open_file(const char *rt_file);
int		read_file(int fd, t_scene *scene);
int		paring_str(char *str, t_scene scene);
int		validate_file(const char *rt_file);

int		check_type(const char *str);
void	ft_split_free(char **str);
int		ft_array_len(const char **str);
int		parse_colors(const char *str, t_colors *color);
int		parse_point(const char *str, t_coordinates *loc);
int		parse_normal_vector(const char *str, t_coordinates *vec);

int		parse_ambient(const char **tokens, t_ambient *ambient);
int		parse_camera(const char **tokens, t_camera *camera);
int		parse_light(const char **tokens, t_light *light);
int		parse_objects(const char **tokens, t_object **obj, int type);
int		print_err(int err);
#endif
