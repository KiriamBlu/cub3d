/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/09/12 13:01:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : evaluate if movement gets close to window limit. */
static int	window_limit(double new_pos[], t_dim win, double margin, t_prog *game)
{
	(void) game;
	if (new_pos[0] + margin >= win.size[0] || new_pos[0] - margin <= 0)
		return (1);
	if (new_pos[1] + margin >= win.size[1] || new_pos[1] - margin <= 0)
		return (1);
	return (0);
}

/** PURPOSE : calculate new coordinates. */
static void move_position(double v[], t_prog *game, int key, int pixel_per_block[])
{
	double new_pos[2];
	double speed_multiplier;
	int flag;

	if (game->pl.flag_trance)
		speed_multiplier = (WIND_MODE * 0.01);
	else
		speed_multiplier = 0.01;
	if (key == 0)
	{
		new_pos[0] = game->pl.position_coor[0] + (v[0]) * speed_multiplier;
		new_pos[1] = game->pl.position_coor[1] + (v[1]) * speed_multiplier;
	}
	else
	{
		new_pos[0] = game->pl.position_coor[0] - (v[0]) * speed_multiplier;
		new_pos[1] = game->pl.position_coor[1] - (v[1]) * speed_multiplier;
	}
	if (window_limit(new_pos, game->w2, (double) SAFE_MARGIN, game))
		return ;
	flag = wall_coll(game, new_pos, pixel_per_block);
	filter_final_pos(game, new_pos, flag, pixel_per_block);
}

/** PURPOSE : correct position by adding correct vector. */
static void update_player_position(int key, t_prog *game)
{
	int i;
	int x;
	int speed;
	int pixel_per_block[2];
	double vp[2];

	i = -1;
	speed = PLAYER_SPEED * 2;
	if (game->map2D.v_pixel_per_block[0])
	{	
		pixel_per_block[0] = game->map2D.v_pixel_per_block[0];
		pixel_per_block[1] = game->map2D.v_pixel_per_block[1];
	}
	else
	{
		pixel_per_block[0] = game->map2D.pixel_per_block[0];
		pixel_per_block[1] = game->map2D.pixel_per_block[1];
	}
	vp[0] = ((game->pl.vis.x) / pixel_per_block[0]);
	vp[1] = ((game->pl.vis.y) / pixel_per_block[1]);
	x = 0;
	while (++i < 8)
	{
		if (key == i)
		{
			while(x++ < speed)
				move_position(vp, game, key, pixel_per_block);
		}
	}
}

/** PURPOSE : distribute proper key control
 * W A S D -- movement code.
 * Or combination of the above. */
void	movement_control(mlx_key_data_t key, t_prog *game)
{
	log_coor_int(game->pl.position);

	(void) key;
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		update_player_position(key_up, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		update_player_position(key_down, game);
}
