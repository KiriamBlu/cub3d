/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*getlimiter(char *limiter)
{
	int	i;
	int	k;

	i = -1;
	while (ft_isspaces(limiter[++i]) != 0 && limiter[i])
		;
	k = i;
	while (ft_isspaces(limiter[k]) == 0 && limiter[k])
		k++;
	return (ft_substr(limiter, i, k - i));
}

int	parse_limit(char *limiter)
{
	int	i;

	i = -1;
	while (limiter[++i])
		if (ft_isspaces(limiter[i]))
			return (1);
	return (0);
}

int	parse_and_storage(char *limiter, t_prog *game, char *content)
{
	if (!ft_strcmp(limiter, "north") || !ft_strcmp(limiter, "south")
		|| !ft_strcmp(limiter, "west") || !ft_strcmp(limiter, "east")
		|| !ft_strcmp(limiter, "F") || !ft_strcmp(limiter, "C"))
	{
		if (storage_info(limiter, game, content) != 0)
			return (-1);
	}
	else
	{
		printf("%s\n", limiter);
		return (-1);
	}
	game = (void *)game;
	return (0);
}

int	getinfovisual(char *content, t_prog *game)
{
	char	*limiter;

	limiter = getlimiter(content);
	if (ft_strlen(limiter) == 0 || parse_limit(limiter) == 1)
	{
		free(limiter);
		return (0);
	}
	if (parse_and_storage(limiter, game, content) == -1)
	{
		free(limiter);
		return (-1);
	}
	free(limiter);
	return (1);
}

int	storage_info(char *limiter, t_prog *game, char *content)
{
	if (ft_strcmp(limiter, "north") == 0)
		game->north = cacht_info_str(content);
	else if (ft_strcmp(limiter, "south") == 0)
		game->south = cacht_info_str(content);
	else if (ft_strcmp(limiter, "west") == 0)
		game->west = cacht_info_str(content);
	else if (ft_strcmp(limiter, "east") == 0)
		game->east = cacht_info_str(content);
	else if (ft_strcmp(limiter, "F") == 0)
		game->floor_clr = catch_number(content);
	else if (ft_strcmp(limiter, "C") == 0)
		game->sky_clr = catch_number(content);
	if (game->floor_clr == -1 || game->sky_clr == -1)
		return (-1);
	return (0);
}
