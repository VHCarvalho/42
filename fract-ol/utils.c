/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:38:22 by vcarvalh          #+#    #+#             */
/*   Updated: 2023/01/22 13:47:08 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_line(t_data	*data, int x, int y, int length, int color)
{
	while (length)
	{
		my_mlx_pixel_put(data, x + length, y, color );
		length--;
	}
}
int	mouse_hook(int keycode, int x, int y, void *vars)
{
	printf("%d\n", keycode);
	(void)x;
	(void)y;
	(void)vars;
	return (1);
}

int	exit_fractol(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit_fractol(vars);
	return (1);
}
