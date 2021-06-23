/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:42:05 by fballest          #+#    #+#             */
/*   Updated: 2021/06/23 13:38:28 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_newtonfractol(t_frc *frc)
{
	frc->fractol = 2;
	ft_setinitialvalues_newton(frc);
	frc->ptr = mlx_init();
	frc->win = mlx_new_window(frc->ptr, frc->rx, frc->ry, "Newton");
	mlx_mouse_hook(frc->win, ft_mouse_hook, frc);
	mlx_hook(frc->win, 6, 1L << 6, ft_mouse_move, frc);
	mlx_hook(frc->win, 2, 1L << 0, ft_keypress, frc);
	mlx_hook(frc->win, 3, 1L << 1, ft_keyrelease, frc);
	mlx_hook(frc->win, 17, 1L << 17, ft_exit_game, frc);
	mlx_loop_hook(frc->ptr, ft_newtondraw, frc);
	mlx_loop(frc->ptr);
	return (0);
}

void	ft_setinitialvalues_newton(t_frc *frc)
{
	frc->rx = 800;
	frc->ry = 600;
	frc->zoom = 1;
	frc->movex = 0;
	frc->movey = 0;
	frc->max_iter = 64;
	frc->range = 0;
	frc->radio = 0.995;
	frc->side = 0.01;
	frc->cx = 0;
	frc->cy = 0;
}

int	ft_newtondraw(t_frc *frc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	frc->img = mlx_new_image(frc->ptr, frc->rx, frc->ry);
	frc->addr = mlx_get_data_addr(frc->img, &frc->bxp, &frc->sili, &frc->end);
	while (y < frc->ry)
	{
		frc->incy = -frc->side + 2 * frc->side / frc->ry * y;
		x = 0;
		while (x < frc->rx)
		{
			ft_calculatecolor_newton(frc, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frc->ptr, frc->win, frc->img, 0, 0);
	ft_key_hook(frc);
	mlx_destroy_image(frc->ptr, frc->img);
	return (0);
}

void	ft_calculatecolor_newton(t_frc *frc, int x, int y)
{
	int	i;

	i = 0;
	frc->incx = -frc->side + 2 * frc->side / frc->rx * x;
	frc->xi = frc->incx;
	frc->yi = frc->incy;
	frc->w = 0;
	while (i < frc->max_iter)
	{
		frc->xx = 2 * frc->xi / 3 - (frc->xi * frc->xi - frc->yi * frc->yi)
			/ (frc->xi * frc->xi + frc->yi * frc->yi)
			/ (frc->xi * frc->xi + frc->yi * frc->yi) / 3;
		frc->yy = 2 * frc->yi / 3 + 2 * frc->xi * frc->yi
			/ (frc->xi * frc->xi + frc->yi * frc->yi)
			/ (frc->xi * frc->xi + frc->yi * frc->yi) / 3;
		frc->xi = frc->xx;
		frc->yi = frc->yy;
		if ((frc->xi - frc->cx) * (frc->xi - frc->cx) + (frc->yi - frc->cy)
			* (frc->yi - frc->cy) < frc->radio)
			frc->w = frc->i;
		i++;
	}
	printf("%c", 255 * frc->w * frc->w / frc->max_iter / frc->max_iter);
	ft_putpixelnewton(frc, i, x, y);
}

void	ft_putpixelnewton(t_frc *frc, int i, int x, int y)
{
	frc->h = i % 256;
	frc->s = 255;
	frc->v = 255 * (i < frc->max_iter);
	ft_hsv_to_rgb(frc);
	frc->color = frc->range + (int)ft_to_rgb(frc->r, frc->g, frc->b);
	ft_mlx_pixel_put(frc, x, y, frc->color);
}

// void	ft_settozero_newton(t_frc *frc, int x, int y)
// {
// 	frc->pr = 1.5 * (x - frc->rx / 2) / (0.5 * frc->zoom * frc->rx)
// 		+ frc->movex;
// 	frc->pi = (y - frc->ry / 2) / (0.5 * frc->zoom * frc->ry) + frc->movey;
// 	frc->oldRe = 0;
// 	frc->oldIm = 0;
// 	frc->newRe = 0;
// 	frc->newIm = 0;
// }
