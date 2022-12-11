/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:03 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/12/06 19:41:49 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 360, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, 640/2, 360/2, 0xFFFFFF);
	printf("%f\n", sqrt(4));
	mlx_loop(mlx);
}
