/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:15:33 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/05 11:24:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw vector on screen.
 * Assuming position of player as a coordinate (0, 0).
 * Therefore, vector can be represented by having a single point in space (Vx, Vy) 
 * 1. First, unit vector (vector unit is calulated). 
 * 2. As the unit of the grid is the pixel, to obtain the line:
 * (unit_Vector + unit_Vector) repeated n module times.  */
void draw_vector(t_vector vec, double origin[], uint32_t colour, t_prog *game)
{
	double		x_pixel;
	double		y_pixel;
	double		counter;
	t_vector	unit_vec;
	mlx_image_t *image;

	image = game->image[MAP_2D];
	counter = get_module(vec);
	unit_vec = get_unit_vector(vec);
	x_pixel = origin[0] + unit_vec.x;
	y_pixel = origin[1] + unit_vec.y;
	while (--counter > 0)
	{	
		solid_pixel(image, (int) x_pixel, (int) coor(y_pixel, game->w2.size[1]), colour);
		x_pixel += unit_vec.x;
		y_pixel += unit_vec.y;
	}
}

/** ADDITIONAL NOTES
 * ¿Why not draw the line by using the ecuation of the line (y = mx + n)
 * As we are working with pixels, it will result in free spaces in the pixel map.
 * On th other hand, working with unitary vectors, will yield a continous line. */
