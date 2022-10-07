/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/07 12:52:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : auxiliar function to calculate position. */
static void	get_new_pos(double new_pos[], int type, t_vector v, t_prog *game)
{
	if (type == 0)
	{
		new_pos[0] = game->pl.v_position_coor[0] + (v.x) * game->pl.speed;
		new_pos[1] = game->pl.v_position_coor[1] + (v.y) * game->pl.speed;
	}
	else if (type == 1)
	{
		new_pos[0] = game->pl.v_position_coor[0] - (v.x) * game->pl.speed;
		new_pos[1] = game->pl.v_position_coor[1] - (v.y) * game->pl.speed;
	}
	else if (type == 2)
	{
		new_pos[0] = game->pl.v_position_coor[0] + \
		(get_perpendicular(v)).x * game->pl.speed;
		new_pos[1] = game->pl.v_position_coor[1] + \
		(get_perpendicular(v)).y * game->pl.speed;
	}
	else
	{
		new_pos[0] = game->pl.v_position_coor[0] - \
		(get_perpendicular(v)).x * game->pl.speed;
		new_pos[1] = game->pl.v_position_coor[1] - \
		(get_perpendicular(v)).y * game->pl.speed;
	}
}

/** PURPOSE : calculate new coordinates. */
static	inline void	move_position(double v[], \
t_prog *game, int key, int pixel_per_block[])
{
	double		new_pos[2];
	t_vector	vec;
	int			flag;

	if (game->pl.flag_trance)
		game->pl.speed = (WIND_MODE * 0.01);
	else
		game->pl.speed = 0.01;
	vec.x = v[0];
	vec.y = v[1];
	get_new_pos(new_pos, key, vec, game);
	flag = wall_coll(game, new_pos, pixel_per_block);
	filter_final_pos(game, new_pos, flag, pixel_per_block);
}

/** PURPOSE : correct position by adding correct vector. */
void	update_player_position(int key, t_prog *game)
{
	int		i;
	int		x;
	int		speed;
	int		pixel_per_block[2];
	double	vp[2];

	i = -1;
	speed = PLAYER_SPEED * 2;
	if (game->map2D.v_pixel_per_block[0] != 0)
	{	
		pixel_per_block[0] = game->map2D.v_pixel_per_block[0];
		pixel_per_block[1] = game->map2D.v_pixel_per_block[1];
	}
	else
	{
		pixel_per_block[0] = game->map2D.pixel_per_block[0];
		pixel_per_block[1] = game->map2D.pixel_per_block[1];
	}
	vp[0] = ((game->pl.vis.x) / 5);
	vp[1] = ((game->pl.vis.y) / 5);
	x = 0;
	while (++i < 8)
		if (key == i)
			while (x++ < speed)
				move_position(vp, game, key, pixel_per_block);
}

/** PURPOSE : distribute proper key control
 * W A S D -- movement code.
 * Or combination of the above. */
void	movement_control(mlx_key_data_t t_key, t_prog *game)
{
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, t_key.key) == 1)
	{	
		game->pl.key[MLX_KEY_W] = mlx_is_key_down(game->mlx, MLX_KEY_W);
		game->pl.key[MLX_KEY_S] = mlx_is_key_down(game->mlx, MLX_KEY_S);
		game->pl.key[MLX_KEY_A] = mlx_is_key_down(game->mlx, MLX_KEY_A);
		game->pl.key[MLX_KEY_D] = mlx_is_key_down(game->mlx, MLX_KEY_D);
		game->pl.key[MLX_KEY_RIGHT] = mlx_is_key_down(game->mlx, MLX_KEY_RIGHT);
		game->pl.key[MLX_KEY_LEFT] = mlx_is_key_down(game->mlx, MLX_KEY_LEFT);
		game->pl.key[MLX_KEY_C] = mlx_is_key_down(game->mlx, MLX_KEY_C);
		game->pl.key[MLX_KEY_V] = mlx_is_key_down(game->mlx, MLX_KEY_V);
	}
	else
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_W) == 0)
			game->pl.key[MLX_KEY_W] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_S) == 0)
			game->pl.key[MLX_KEY_S] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_A) == 0)
			game->pl.key[MLX_KEY_A] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_D) == 0)
			game->pl.key[MLX_KEY_D] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) == 0)
			game->pl.key[MLX_KEY_RIGHT] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) == 0)
			game->pl.key[MLX_KEY_LEFT] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_C) == 0)
			game->pl.key[MLX_KEY_C] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_V) == 0)
			game->pl.key[MLX_KEY_V] = 0;
	}
}
