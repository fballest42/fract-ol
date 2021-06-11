/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliafractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:42:00 by fballest          #+#    #+#             */
/*   Updated: 2021/06/11 14:22:11 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_juliafractol(t_frc *frc)
{
	frc->rx = 1280;
	frc->ry = 1024;
	frc->ptr = mlx_init();
	frc->win = mlx_new_window(frc->ptr, frc->rx, frc->ry, "fractol Julia");
	ft_setinitialvalues(frc);
	mlx_hook(frc->win, 17, 1L << 17, ft_exit_game, frc);
	// mlx_hook(frc->win, 2, 1L << 0, ft_keypress, frc);
	// mlx_hook(frc->win, 3, 1L << 1, ft_keyrelease, frc);
	// mlx_hook(frc->win,MASCARA, MASCARA, ft_mouseprees, frc);
	// mlx_hook(frc->win,MASCARA, MASCARA, ft_mouserelease, frc);
	mlx_loop_hook(frc->ptr, ft_juliadraw, frc);
	mlx_loop(frc->ptr);
	return (0);
}

void	ft_setinitialvalues(t_frc *frc)
{
	frc->zoom = 1;
	frc->movex = 0;
	frc->movey = 0;
	frc->max_iter = 300;
	frc->cRe = -0.7;
	frc->cIm = 0.27015;
	frc->shift = 0;
}

int	ft_juliadraw(t_frc *frc)
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
			ft_calculatecolor(frc, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frc->ptr, frc->win, frc->img, 0, 0);
	mlx_destroy_image(frc->ptr, frc->img);
	return (0);
}

void	ft_calculatecolor(t_frc *frc, int x, int y)
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
		frc->newRe = frc->oldRe * frc->oldRe - frc->oldIm
			* frc->oldIm + frc->cRe;
		frc->newIm = 2 * frc->oldRe * frc->oldIm + frc->cIm;
		if ((frc->newRe * frc->newRe + frc->newIm * frc->newIm) > 4)
			break ;
		i++;
	}
	frc->h = i % 256 - (frc->shift % 256);
	frc->s = 255 - frc->shift;
	frc->v = (255 - frc->shift) * (i < frc->max_iter);
	ft_hsv_to_rgb(frc);
	frc->color = (int)ft_to_rgb(frc->r, frc->g, frc->b);
	ft_mlx_pixel_put(frc, x, y, frc->color);
}
