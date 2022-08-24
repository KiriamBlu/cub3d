/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/22 16:38:28 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	framework_2D(t_prog *game);

//NEXT mas prioritario
//posicion

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
int	main(int argc, char **argv)
{
	t_prog	*game;
	/* --------------------------------------------------------------- */
	//atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	/* --------------------------------------------------------------- */
	init_game(game);
	parser(game, argc, argv);
	framework_dimensions(game);
	init_map2D(game->map2D.map, game);
	
		
	/* --------------------------------------------------------------- */
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}
