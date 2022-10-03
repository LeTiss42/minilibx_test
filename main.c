/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:16:19 by mravera           #+#    #+#             */
/*   Updated: 2022/10/04 00:48:58 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_image {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_image;

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*path;
	t_image	img;
	void	*mllx;

	path = "key.xpm";
	mllx = mlx_init();
	vars.win = mlx_new_window(mllx, 500, 500, "Test");
	printf("test 1\n");
	img.ptr = mlx_xpm_file_to_image(mllx, path, &img.w, &img.h);
	printf("test 2\n");
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_length, &img.endian);
	mlx_put_image_to_window(mllx, vars.win, img.ptr, 0, 0);
	mlx_loop(mllx);
}
