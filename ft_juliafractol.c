/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_juliafractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:42:00 by fballest          #+#    #+#             */
/*   Updated: 2021/06/11 01:24:49 by fballest         ###   ########.fr       */
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
	//mlx_hook(frc->win, 17, 1L << 17, ft_exit_game, frc);
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
	frc->r = 10;
	frc->g = 10;
	frc->b = 180;
}

int	ft_juliadraw(t_frc *frc)
{
	int	x;
	int	y;
	int i;

	x = 0;
	y = 0;
	frc->img = mlx_new_image(frc->ptr, frc->rx, frc->ry);
	frc->addr = mlx_get_data_addr(frc->img, &frc->bxp, &frc->sili, &frc->endian);
	while (y < frc->ry)
	{
		x = 0;
		while (x < frc->rx)
		{
			frc->newRe = 1.5 *(x - frc->rx / 2) / (0.5 * frc->zoom * frc->rx)
				+ frc->movex;
			frc->newIm = (y - frc->ry / 2) / (0.5 * frc->zoom * frc->ry)
				+ frc->movey;
			i = 0;
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
			ft_rgb_to_hsv(frc, i % 256, 64, 255 * (i < frc->max_iter));
			ft_hsv_to_rgb(frc);
			frc->color = ft_to_rgb(frc->r, frc->g, frc->b);
			ft_mlx_pixel_put(frc, x, y, frc->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frc->ptr, frc->win, frc->img, 0, 0);
	mlx_destroy_image(frc->ptr, frc->img);
	return (0);
}

int	ft_to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	ft_hsv_to_rgb(t_frc *frc)
{
	int i;
	float RGB_min;
	float RGB_max;
	float RGB_Adj;
	float difs;

	RGB_max = frc->v * 2.55f;
	RGB_min = RGB_max*(100 - frc->s) / 100.0f;
	i = frc->h / 60;
	difs = (int)frc->h % 60;
	RGB_Adj = (RGB_max - RGB_min) * difs / 60.0f;
	if (i == 0)
	{
		frc->r = RGB_max;
		frc->g = RGB_min + RGB_Adj;
		frc->b = RGB_min;
	}
	else if (i == 1)
	{
		frc->r = RGB_max - RGB_Adj;
		frc->g = RGB_max;
		frc->b = RGB_min;
	}
	else if (i == 2)
	{
		frc->r = RGB_min;
		frc->g = RGB_max;
		frc->b = RGB_min + RGB_Adj;
	}
	else if (i == 3)
	{
		frc->r = RGB_min;
		frc->g = RGB_max - RGB_Adj;
		frc->b = RGB_max;
	}
	else if (i == 4)
	{
		frc->r = RGB_min + RGB_Adj;
		frc->g = RGB_min;
		frc->b = RGB_max;
	}
	else
	{
		frc->r = RGB_max;
		frc->g = RGB_min;
		frc->b = RGB_max - RGB_Adj;
	}
}

float	max(float a, float b, float c)
{
   return ((a > b)? (a > c ? a : c) : (b > c ? b : c));
}

float	min(float a, float b, float c)
{
   return ((a < b)? (a < c ? a : c) : (b < c ? b : c));
}

void	ft_rgb_to_hsv(t_frc *frc, float r, float g, float b)
{
	frc->cmax = max(r, g, b);
	frc->cmin = min(r, g, b);
	frc->diff = frc->cmax - frc->cmin;
	r = r / 255.0;
	g = g / 255.0;
	b = b / 255.0;
	if (frc->cmax == frc->cmin)
		frc->h = 0;
	else if (frc->cmax == r)
		frc->h = fmod((60 * ((g - b) / frc->diff) + 360), 360.0);
	else if (frc->cmax == g)
		frc->h = fmod((60 * ((b - r) / frc->diff) + 120), 360.0);
	else if (frc->cmax == b)
		frc->h = fmod((60 * ((r - g) / frc->diff) + 240), 360.0);
	if (frc->cmax == 0)
        frc->s = 0;
    else
        frc->s = (frc->diff / frc->cmax) * 100;
	frc->v = frc->cmax * 100;
}
