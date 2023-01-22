/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:54:52 by vcarvalh          #+#    #+#             */
/*   Updated: 2023/01/22 13:46:25 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <stdlib.h>
//RETIRAR
#include <stdio.h>
# ifdef __linux__
#  include "./mlx_linux/mlx.h"
# else
#  include "./mlx/mlx.h"
# endif

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
} t_vars;
#endif

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);
void	put_line(t_data	*data, int x, int y, int length, int color);
int	mouse_hook(int keycode, int x, int y, void *vars);
int	exit_fractol(t_vars *vars);
int key_hook(int keycode, t_vars *vars);
