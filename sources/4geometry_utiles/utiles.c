/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* northTATION: 
	coor_x, coor_y :	abstraction coordinates. Have not been shifted.
	have DOUBLE type.
	x, y:				actual coordinates. already shifted. Used for solid_pixel.
	they have the type INT.
 */
/** PURPOSE : Put pixel to image in a secure way.
 * It need to recieve the y coordinate already SHIFTED!. */
void	solid_pixel(mlx_image_t *image, int coor_x, int coor_y, uint32_t colour)
{
	uint32_t	x;
	uint32_t	y;

	mlx_put_pixel(image, 50, 50, BLACK);
	if (coor_x < 0 || coor_y < 0 || colour < 0)
	{
		if (GRAPHIC_ENGINE_REPORT)
			printf("Pixel (%i, %i) not rendered\n", coor_x, coor_y);
		return ;
	}
	x = (uint32_t) coor_x;
	y = (uint32_t) coor_y;
	if (x >= image->width || y >= image->height)
	{
		if (GRAPHIC_ENGINE_REPORT)
			printf("Pixel (%i, %i) could not be rendered\n", coor_x, coor_y);
		return ;
	}
	mlx_put_pixel(image, x, y, colour);
}

/** PURPOSE : Horizontal line in given coordinate. */
void	put_horizontal(double coordinate_y, double limit_x, \
int colour, t_prog *game)
{
	int			i;
	int			coor_y;
	mlx_image_t	*image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += (SAFE_OFFSET);
	coor_y = (int)coor(coordinate_y, game->w2.size[1]);
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}

/** PURPOSE : Vertical line in given coordinate. */
void	put_vertical(double coordinate_x, double limit_y, \
int colour, t_prog *game)
{
	int			j;
	int			coor_y;
	mlx_image_t	*image;

	image = game->image[CUB_3D];
	if (coordinate_x == image->width)
		coordinate_x -= (SAFE_OFFSET);
	j = -1;
	while (++j < limit_y)
	{
		coor_y = (int) coor(j, game->w2.size[1]);
		solid_pixel(image, (int) coordinate_x, coor_y, colour);
	}
}

/** PURPOSE : Base times height.
 * 1. Requires dimensions and position of origin. */
void	draw_centered_rectangle(double position[], int base, \
int height, t_prog *game)
{
	int			i;
	int			j;
	int			x;
	int			y;
	mlx_image_t	*image;

	image = game->image[CUB_3D];
	if (position[0] < 0 || position[1] < 0)
		return ;
	i = -1;
	j = -1;
	position[1] = position[1] - height / 2;
	position[0] = position[0] - base / 2;
	while (++j < height)
	{
		while (++i < base)
		{
			x = (int)(position[0] + i);
			y = (int)coor(position[1] + j, game->w2.size[1]);
			solid_pixel(image, x, y, RED);
		}
		i = -1;
	}
}
