/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:42:00 by fballest          #+#    #+#             */
/*   Updated: 2021/06/29 13:32:17 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_newtonfractol(t_frc *frc)
{
	frc->fractol = 3;
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
	frc->movex = -0.5;
	frc->movey = 0;
	frc->max_iter = 128;
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
	frc->newRe = 1.5 * (x - frc->rx / 2) / (0.5 * frc->zoom * frc->rx)
		+ frc->movex;
	frc->newIm = (y - frc->ry / 2) / (0.5 * frc->zoom * frc->ry)
		+ frc->movey;
	while (i < frc->max_iter)
	{
		frc->oldRe = frc->newRe;
		frc->oldIm = frc->newIm;
		frc->newRe = 2 * frc->oldRe / 3 - (frc->oldRe * frc->oldRe
				- frc->oldIm * frc->oldIm) / (frc->oldRe * frc->oldRe
				+ frc->oldIm * frc->oldIm) / (frc->oldRe * frc->oldRe
				+ frc->oldIm * frc->oldIm) / 3;
		frc->newIm = 2 * frc->oldIm / 3 + 2 * frc->oldRe * frc->oldIm
			/ (frc->oldRe * frc->oldRe + frc->oldIm * frc->oldIm)
			/ (frc->oldRe * frc->oldRe + frc->oldIm * frc->oldIm) / 3;
		if ((frc->newRe * frc->newRe + frc->newIm * frc->newIm) > 4)
			break ;
		i++;
	}
	ft_putpixelnewton(frc, i, x, y);
}

void	ft_putpixelnewton(t_frc *frc, int i, int x, int y)
{
	frc->h = (int)(i + frc->range) % 256;
	frc->s = 255 - frc->range;
	frc->v = 255 * (i + frc->range < frc->max_iter);
	ft_hsv_to_rgb(frc);
	frc->color = frc->range + (int)ft_to_rgb(frc->r, frc->g, frc->b);
	ft_mlx_pixel_put(frc, x, y, frc->color);
}
