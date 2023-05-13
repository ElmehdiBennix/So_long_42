/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:05:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 05:10:56 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	init_images_5(t_data *game)
{
	game->componets.floor_enemy = ft_lstnew(protect_image(
				game->mlx, "textures/enemy/floor_enemy/peaks_1.xpm",
				&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_2.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_3.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_2.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_1.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_4.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_4.xpm",
			&game->componets.img_width, &game->componets.img_height));
}

static	void	init_images_6(t_data *game)
{
	game->componets.wall_enemy = ft_lstnew(protect_image(
				game->mlx, "textures/enemy/wall_enemy/flame_2.xpm",
				&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_3.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_3.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_4.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_4.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_1.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_1.xpm",
			&game->componets.img_width, &game->componets.img_height));
}

static	void	init_images_7(t_data *game)
{
	t_list	*last;

	game->componets.exit = ft_lstnew(protect_image(
				game->mlx, "textures/exit/exit_1.xpm",
				&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.exit, protect_image(
			game->mlx, "textures/exit/exit_2.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.exit, protect_image(
			game->mlx, "textures/exit/exit_3.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.exit, protect_image(
			game->mlx, "textures/exit/exit_4.xpm",
			&game->componets.img_width, &game->componets.img_height));
	game->componets.tmp = game->componets.exit;
	ft_lstcreate_back(&game->componets.floor_enemy, protect_image(
			game->mlx, "textures/enemy/floor_enemy/peaks_4.xpm",
			&game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.wall_enemy, protect_image(
			game->mlx, "textures/enemy/wall_enemy/flame_1.xpm",
			&game->componets.img_width, &game->componets.img_height));
	last = ft_lstlast(game->componets.wall_enemy);
	last->next = game->componets.wall_enemy;
	last = ft_lstlast(game->componets.floor_enemy);
	last->next = game->componets.floor_enemy;
}

void	init_images(t_data *game)
{
	init_images_1(game);
	init_images_2(game);
	init_images_3(game);
	init_images_4(game);
	init_images_5(game);
	init_images_6(game);
	init_images_7(game);
}
