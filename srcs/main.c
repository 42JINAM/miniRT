/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:48:12 by jinam             #+#    #+#             */
/*   Updated: 2025/03/05 12:49:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_enum.h"
#include <stdio.h>

void	init_scene(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
}

void	print_rgb(t_colors *color)
{
	ft_printf("rgb r: %d, g: %d, b: %d\n", color->r, color->g, color->b);
}

void	print_coordinates(t_coordinates *vec)
{
	printf("coordinates x: %f, %f, %f \n", vec->x, vec->y, vec->z);
}

void	test_obj(t_object *obj)
{
	t_object	*curr;

	curr = obj;
	while (curr)
	{
		printf("type : %d diameter : %f, height: %d\n", curr->id, curr->diameter, curr->height);
		print_rgb(&curr->rgb);
		print_coordinates(&curr->coordinates);
		print_coordinates(&curr->vector);
		curr = curr->next;
	}
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		return (1);
	init_scene(&scene);
	parsing(argv[1], &scene);
	test_obj(scene.objs);
}
