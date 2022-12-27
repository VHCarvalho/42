/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:03 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/12/27 20:42:33 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

void	draw_line(void *mlx, void *mlx_win, int x_start, int y_start, int x_end, int y_end, int color)
{
	int			x_delta;
	int			y_delta;
	double	pixel_x;
	double	pixel_y;
	double	pixels;
	ssize_t	temp;

	x_delta = x_end - x_start;
	y_delta = y_end - y_start;
	//printf("delta x:%d -- delta y:%d", x_delta, y_delta);
	pixels = sqrt((x_delta * x_delta) + (y_delta * y_delta));
	//printf("pixels: %f", pixels);
	x_delta /= pixels;
	y_delta /= pixels;
	pixel_x = x_start;
	pixel_y = y_start;
	while (pixels)
	{
		temp = write(1, "entrou", 6);
		temp = write(1,"\n", 1);
		if (temp < 0)
			return;
		mlx_pixel_put(mlx, mlx_win, pixel_x, pixel_y, color);
		pixel_x += x_delta;
		pixel_y += y_delta;
		pixels--;
	}

}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 360, "Hello world!");
	mlx_pixel_put(mlx, mlx_win,640/2, 360/2, 0xFFFFFF);
	draw_line(mlx, mlx_win, 640, 360, 0, 0, 0xFFFFFF);
	mlx_loop(mlx);
}

