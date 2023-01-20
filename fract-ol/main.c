/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:03 by vcarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 18:02:06 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

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
	if (keycode == 53)
		exit_fractol(vars);
	return (1);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920/2, 1080/2, "test");
	vars.img.img = mlx_new_image(vars.mlx, 1920/2, 1080/2);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	put_line(&vars.img, 5, 5,100, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, exit_fractol, &vars);
	mlx_loop(vars.mlx);
}
