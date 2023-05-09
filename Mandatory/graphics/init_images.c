/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:05:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 18:44:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_images_1(t_data *map_data)
{
	map_data->walls.block_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/block_wall_v1.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.block_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/block_wall_v2.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.down_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/down_wall_v1.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.down_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/down_wall_v2.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.left_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/left_wall_v1.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.left_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/left_wall_v2.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
}

static void	init_images_2(t_data *map_data)
{
	map_data->componets.player = mlx_xpm_file_to_image(map_data->mlx,
			"textures/player/skull_1.xpm", &map_data->componets.img_width,
			&map_data->componets.img_height);
	map_data->componets.exit = mlx_xpm_file_to_image(map_data->mlx,
			"textures/exit/exit_1.xpm", &map_data->componets.img_width,
			&map_data->componets.img_height);
	map_data->componets.collectible = mlx_xpm_file_to_image(map_data->mlx,
			"textures/collectible/coin_1.xpm", &map_data->componets.img_width,
			&map_data->componets.img_height);
	map_data->floors.floor = mlx_xpm_file_to_image(map_data->mlx,
			"textures/floor/floor.xpm", &map_data->floors.img_width,
			&map_data->floors.img_height);
	map_data->walls.right_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/right_wall_v1.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.right_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/right_wall_v2.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
}

static void	init_images_3(t_data *map_data)
{
	map_data->walls.full_wall = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/full_wall.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.top_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/top_wall_v1.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.top_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/top_wall_v2.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.down_left_wall = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/down_left_wall.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
	map_data->walls.down_right_wall = mlx_xpm_file_to_image(map_data->mlx,
			"textures/wall/down_right_wall.xpm", &map_data->walls.img_width,
			&map_data->walls.img_height);
}

static void	protections(t_data *map_data)
{
	if (!map_data->walls.top_wall_v2 || !map_data->walls.block_wall_v2
		|| !map_data->walls.down_wall_v1 || !map_data->walls.down_wall_v2
		|| !map_data->walls.left_wall_v1)
		exit_msg(2, "Texture file not found.", RED, 1);
	if (!map_data->walls.left_wall_v2 || !map_data->walls.down_left_wall
		|| !map_data->walls.down_right_wall || !map_data->walls.full_wall)
		exit_msg(2, "Texture file not found.", RED, 1);
	if (!map_data->walls.top_wall_v1 || !map_data->walls.right_wall_v2
		|| !map_data->walls.down_right_wall || !map_data->walls.right_wall_v1)
		exit_msg(2, "Texture file not found.", RED, 1);
	if (!map_data->componets.player || !map_data->componets.exit
		|| !map_data->componets.collectible || !map_data->floors.floor)
		exit_msg(2, "Texture file not found.", RED, 1);
}

void	init_images(t_data *map_data)
{
	init_images_1(map_data);
	init_images_2(map_data);
	init_images_3(map_data);
	protections(map_data);
}
