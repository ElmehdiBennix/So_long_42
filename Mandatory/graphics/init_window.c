/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:43:15 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 20:45:35 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_window(t_data *game) // opens the window depending on the map width and height and calculates the image pixels to see if it can fit in the intra mac screen .
{
	int	hit;
	int	wid;

	hit = 96 * game->height;
	wid = 96 * game->width;
	if (wid > 2600 || hit > 1450)
		exit_msg(2, "Map is valid but its too big for the window.", GREEN, 0);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			wid, hit, "traps and dungeons");
}
