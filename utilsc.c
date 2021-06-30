/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:57:59 by fballest          #+#    #+#             */
/*   Updated: 2021/06/30 11:56:03 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hsv_to_rgb(t_frc *frc)
{
	frc->h = frc->h / 256.0;
	frc->s = frc->s / 256.0;
	frc->v = frc->v / 256.0;
	if (frc->s == 0)
	{
		frc->b = frc->v;
		frc->g = frc->b;
		frc->r = frc->g;
	}
	else
	{
		frc->h = frc->h * 6;
		frc->i = (int)(floor(frc->h));
		frc->f = frc->h - frc->i;
		frc->p = frc->v * (1 - frc->s);
		frc->q = frc->v * (1 - (frc->s * frc->f));
		frc->t = frc->v * (1 - (frc->s * (1 - frc->f)));
		ft_hsv_to_rgb2(frc);
		ft_hsv_to_rgb3(frc);
	}
	frc->r = (int)(frc->r * 255.0);
	frc->g = (int)(frc->g * 255.0);
	frc->b = (int)(frc->b * 255.0);
}

void	ft_hsv_to_rgb2(t_frc *frc)
{
	if (frc->i == 0)
	{
		frc->r = frc->v;
		frc->g = frc->t;
		frc->b = frc->p;
	}
	if (frc->i == 1)
	{
		frc->r = frc->q;
		frc->g = frc->v;
		frc->b = frc->p;
	}
	if (frc->i == 2)
	{
		frc->r = frc->p;
		frc->g = frc->v;
		frc->b = frc->t;
	}
}

void	ft_hsv_to_rgb3(t_frc *frc)
{
	if (frc->i == 3)
	{
		frc->r = frc->p;
		frc->g = frc->q;
		frc->b = frc->v;
	}
	if (frc->i == 4)
	{
		frc->r = frc->t;
		frc->g = frc->p;
		frc->b = frc->v;
	}
	if (frc->i == 5)
	{
		frc->r = frc->v;
		frc->g = frc->p;
		frc->b = frc->q;
	}
}

int	ft_nonpulsed(t_frc *frc)
{
	if (frc->key.c || frc->key.h || frc->key.r || frc->key.down
		|| frc->key.up || frc->key.lft || frc->key.rgh || frc->key.mas
		|| frc->key.men)
		return (1);
	return (0);
}
