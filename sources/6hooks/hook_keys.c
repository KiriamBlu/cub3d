/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:32:07 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/12 13:12:40 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//merge realizado

/** PURPOSE : Correct minimap status and reset screen. */
void	update_player_location(t_prog *game)
{
	
	game->pl.position_coor[0] = (double)(game->pl.position[0]) * 
	game->map2D.pixel_per_block[0] + (game->map2D.pixel_per_block[0] / 2);
	game->pl.position_coor[1] = (double)(game->map2D.map_y - (game->pl.position[1] + 1)) * 
	game->map2D.pixel_per_block[1] + (game->map2D.pixel_per_block[1] / 2);
}

/** PURPOSE : Is there os is there not a minimap. */
static int	is_minimap(t_prog *game)
{
	if (!game->minimap_state)
		return (0);
	else if (game->minimap_state == 4)
		return (1);
	else if (game->minimap_state == 2)
		return (2);
	else
		return (0);
}

/** PURPOSE : Correct minimap status and reset screen. */
static void	correct_minimap_value(t_prog *game)
{
	game->minimap_state++;
	if (game->minimap_state == 6)
		game->minimap_state = 0;
}

/** PURPOSE : Executed when hitting tab. It executes twice */
static void	hook_control_minimap(t_prog *game)
{
	correct_minimap_value(game);
	game->map2D.v_pixel_per_block[0] = 0;
	game->map2D.v_pixel_per_block[1] = 0;
	if (is_minimap(game) == 1)
	{
		game->pl.flag_movement = 1;
		minimap_dimensions(game);
		update_pixel_per_block(game);
		update_player_location(game);
	}
	else if (is_minimap(game) == 2)
	{
		game->pl.flag_movement = 1;
		minimap_dimensions(game);
		game->map2D.v_pixel_per_block[0] = game->map2D.pixel_per_block[0];
		game->map2D.v_pixel_per_block[1] = game->map2D.pixel_per_block[1];
		update_pixel_per_block(game);
		//update_player_location(game);
	}
}

/** PURPOSE : manage keys. */
void	hk_keys(mlx_key_data_t key, void *g)
{
	t_prog	*game;

	game = (t_prog *)g;
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(game);
	else if (key.key == MLX_KEY_TAB)
		hook_control_minimap(game);
	else if (key.key == MLX_KEY_F)
	{
		ft_putstr_fd("Wind mode activated. Speed boosted.\n", 1);
		game->pl.flag_trance++;
	}
	else if (key.key == MLX_KEY_G)
	{
		if (game->pl.flag_trance)
		{
			ft_putstr_fd("Exhausted. Speed back to normal.\n", 1);
			game->pl.flag_trance--;
		}
	}
	else
		movement_control(key, game);
	vison_control(key, game);
}
