/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/04 01:12:51 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_first(t_data *game, char **map, int x, int y)
{
	int				w;
	unsigned int	i;

	i = 0;
	w = 0;
	while (map[0][w++] && game->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.left_wall_v1, x, y);
		else if (i > 0 && i != game->width)
		{
			if (i % 2 == 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.top_wall_v1, x, y);
			else if (i % 2 != 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.top_wall_v2, x, y);
			else if (i % 2 == 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.block_wall_v1, x, y);
			else if (i % 2 != 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.block_wall_v2, x, y);
		}
		else if (i == game->width)
			mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.right_wall_v1, x, y);
		x += 96;
	}
}

static int	draw_mid(t_data *game, char **map, int x, int y)
{
	int	w;
	int	h;

	h = 0;
	while (map[++h] && (unsigned int)h != game->height - 1)
	{
		x = 0;
		w = -1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
				draw_wall(game, h, w, x, y);
			else
			{
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.floor, x, y);
				if(map[h][w] == 'C')
				{
					if (map[game->p_position.x][game->p_position.y] == 'C')
						map[game->p_position.x][game->p_position.y] = '0';
					else
					{
						mlx_put_image_to_window(game->mlx, game->mlx_window, game->componets.collectible->content, x, y);
						game->componets.collectible = game->componets.collectible -> next;
					}
				}
				if (map[h][w] == 'E')
					mlx_put_image_to_window(game->mlx, game->mlx_window, game->componets.exit, x, y);
			}
			x += 96;
		}
		y += 96;
	}
	return (y);
}

static void	draw_last(t_data *game, char **map, int x, int y)
{
	int				w;
	unsigned  

	i = 0;
	w = 0;
	while (map[game->height - 1][w++] && game->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_left_wall, x, y);
		else if (i > 0 && i != game->width)
		{
			if (i % 2 == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_wall_v1, x, y);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_wall_v2, x, y);
		}
		else if (i == game->width)
			mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_right_wall, x, y);
		x += 96;
	}
}

int	drawing(t_data *game)
{
	char	**map;
	int		y;

	map = game->map;
	mlx_clear_window(game->mlx,game->mlx_window);
	draw_first(game, map, 0, 0);
	y = draw_mid(game, map, 0, 96);
	draw_last(game, map, 0, y);
	mlx_put_image_to_window(game->mlx, game->mlx_window,game->componets.player, 96 * game->p_position.y, 96 * game->p_position.x);
	return (0);
}