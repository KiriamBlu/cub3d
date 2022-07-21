/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:40:37 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 06:30:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : manage window closing or 
 * exiting with other widgets/tools. */
static void	hk_close(void *game)
{
	clean_exit(game);
}

/** PURPOSE : Convert pointer of program and execute 60 times each second the frame. */
static void next_frame(void *g)
{
	t_prog		*game;
	static int	frame;

	game = (t_prog *) g;
	printf("												FRAME: 	 %i\n", frame);
	frame++;
	put_frame(game);

	game->pl.vis.x = (frame) * 0.01;
	game->pl.vis.y = 1;
}

/** PURPOSE : execute main routine of program.
 * mlx_loop and mlx_loop_hook will tried to be executed a total
 * of 60 times pers second. Therefore 60 fps. */
void	hooks_and_loops(t_prog *game)
{
	mlx_close_hook(game->mlx, &hk_close, (void *) game);
	mlx_key_hook(game->mlx, &hk_keys, game);
	mlx_loop_hook(game->mlx, &next_frame, game);
	mlx_loop(game->mlx);
}