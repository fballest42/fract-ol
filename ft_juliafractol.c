/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_juliafractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:42:00 by fballest          #+#    #+#             */
/*   Updated: 2021/06/10 14:20:25 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_juliafractol(t_frc *frc)
{
	frc->rx = 1200;
	frc->ry = 800;
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
			frc->color = rgb_to_hsv(i % 256, 255, 255 * (i < frc->max_iter));
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

// int	HSVtoRGB(t_frc *frc)
// {
// 	int i;
// 	float RGB_min;
// 	float RGB_max;
// 	float RGB_Adj;
// 	int difs;
// 	RGB_max = v*2.55f;
// 	RGB_min = RGB_max*(100 - s) / 100.0f;

// 	i = h / 60;
// 	difs = h % 60;
// 	RGB_Adj = (RGB_max - RGB_min)*difs / 60.0f;

// 	if (i == 0)
// 	{
// 		*r = RGB_max;
// 		*g = RGB_min + RGB_Adj;
// 		*b = RGB_min;
// 	}
// 	else if (i == 1)
// 	{
// 		*r = RGB_max - RGB_Adj;
// 		*g = RGB_max;
// 		*b = RGB_min;
// 	}
// 	else if (i == 2)
// 	{
// 		*r = RGB_min;
// 		*g = RGB_max;
// 		*b = RGB_min + RGB_Adj;
// 	}
// 	else if (i == 3)
// 	{
// 		*r = RGB_min;
// 		*g = RGB_max - RGB_Adj;
// 		*b = RGB_max;
// 	}
// 	else if (i == 4)
// 	{
// 		*r = RGB_min + RGB_Adj;
// 		*g = RGB_min;
// 		*b = RGB_max;
// 	}
// 	else
// 	{
// 		*r = RGB_max;
// 		*g = RGB_min;
// 		*b = RGB_max - RGB_Adj;
// 	}
// }

float	max(float a, float b, float c)
{
   return ((a > b)? (a > c ? a : c) : (b > c ? b : c));
}

float	min(float a, float b, float c)
{
   return ((a < b)? (a < c ? a : c) : (b < c ? b : c));
}

int rgb_to_hsv(float r, float g, float b)
{
   // R, G, B values are divided by 255
   // to change the range from 0..255 to 0..1:
   float h, s, v;
   r /= 255.0;
   g /= 255.0;
   b /= 255.0;
   float cmax = max(r, g, b); // maximum of r, g, b
   float cmin = min(r, g, b); // minimum of r, g, b
   float diff = cmax-cmin; // diff of cmax and cmin.
   if (cmax == cmin)
      h = 0;
   else if (cmax == r)
      h = fmod((60 * ((g - b) / diff) + 360), 360.0);
   else if (cmax == g)
      h = fmod((60 * ((b - r) / diff) + 120), 360.0);
   else if (cmax == b)
      h = fmod((60 * ((r - g) / diff) + 240), 360.0);
   // if cmax equal zero
      if (cmax == 0)
         s = 0;
      else
         s = (diff / cmax) * 100;
   // compute v
   v = cmax * 100;
   printf("h s v=(%f, %f, %f)\n", h, s, v );
   return 0;
}

// // void	ft_paintjulia(frc)
// // { 

// // }