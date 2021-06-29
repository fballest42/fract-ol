/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:39:50 by fballest          #+#    #+#             */
/*   Updated: 2021/06/29 10:57:37 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_helpmenu(t_frc *frc)
{
	mlx_string_put(frc->ptr, frc->win, 50, 20, 0x000000,
		"-- MENU DE AYUDA --");
	mlx_string_put(frc->ptr, frc->win, 0, 60, 0x000000,
		"TECLA H == Muestra la ayuda");
	mlx_string_put(frc->ptr, frc->win, 0, 80, 0x000000,
		"TECLA C == Modifica el color");
	mlx_string_put(frc->ptr, frc->win, 0, 100, 0x000000,
		"TECLA R == Reinicia");
	mlx_string_put(frc->ptr, frc->win, 0, 120, 0x000000,
		"FLECHAS == Mueve la imagen");
	mlx_string_put(frc->ptr, frc->win, 0, 140, 0x000000,
		"SCROLL RATON O Z/X == Zoom +/-");
	mlx_string_put(frc->ptr, frc->win, 0, 160, 0x000000,
		"MOV. RATON == Prueba...");
}

void	ft_restartfractol(t_frc *frc)
{
	frc->img = NULL;
	frc->addr = NULL;
	mlx_destroy_window(frc->ptr, frc->win);
	frc->ptr = NULL;
	free(frc->ptr);
	if (frc->fractol == 1)
		ft_juliafractol(frc);
	else if (frc->fractol == 2)
		ft_mandelfractol(frc);
	else
		ft_newtonfractol(frc);
}

int	ft_exit_game(t_frc *frc)
{
	mlx_destroy_window(frc->ptr, frc->win);
	frc->ptr = NULL;
	free(frc->ptr);
	free(frc->str);
	free(frc);
	exit(0);
}

void	ft_mlx_pixel_put(t_frc *frc, int x, int y, int color)
{
	char	*dst;

	dst = frc->addr + (y * frc->sili + x * (frc->bxp / 8));
	*(unsigned int *)dst = color;
}

int	ft_to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}
