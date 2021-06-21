/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:39:50 by fballest          #+#    #+#             */
/*   Updated: 2021/06/21 13:55:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_hook(int clic, int mx, int my, t_frc *frc)
{
	int	dx;
	int	dy;

	if (mx >= (frc->rx / 2) && my < (frc->ry / 2))
	{
		dx = abs(mx - (frc->rx / 2));
		dy = abs((frc->ry / 2) - my);
	}
	else if (mx >= (frc->rx / 2) && my >= (frc->ry / 2))
	{
		dx = abs(mx - (frc->rx / 2));//CAMBIAR DESDE AQUI
		dy = abs((frc->ry / 2) - my);
	}
	dx = abs(mx - (frc->rx / 2));
	dy = abs((frc->ry / 2) - mx);
	if (clic == 5)
	{
		printf("CLICK = %d MX = %d MY = %d\n", clic, mx, my);
		frc->zoom = frc->zoom / pow(1.001, 24);
		frc->movex = (dx / frc->zoom) * 0.003;
		frc->movey = (dy / frc->zoom) * 0.003;
	}
	else if (clic == 4)
	{
		printf("CLICK = %d MX = %d MY = %d\n", clic, mx, my);
		frc->zoom = frc->zoom * pow(1.001, 24);
		frc->movex = (dx * frc->zoom) * 0.003;
		frc->movey = (dy * frc->zoom) * 0.003;
	}
	else
	{
		printf("CLICK = %d MX = %d MY = %d\n", clic, mx, my);
		frc->movex = dx * 0.003 * 24 / frc->zoom);
		frc->movey = dy * 24 / frc->zoom);
	}
	return (0);
}

int	ft_keypress(int key, t_frc *frc)
{
	if (key == C_KEY)
		frc->key.c = 1;
	if (key == R_KEY)
		frc->key.r = 1;
	if (key == LEFT_KEY)
		frc->key.lft = 1;
	if (key == RIGHT_KEY)
		frc->key.rgh = 1;
	if (key == UP_KEY)
		frc->key.up = 1;
	if (key == DOWN_KEY)
		frc->key.down = 1;
	if (key == MAS_KEY)
		frc->key.mas = 1;
	if (key == MENOS_KEY)
		frc->key.men = 1;
	if (key == ESC_KEY)
		ft_exit_game(frc);
	if (key == H_KEY)
		ft_helpmenu(frc);
	return (0);
}

int	ft_keyrelease(int key, t_frc *frc)
{
	if (key == C_KEY)
		frc->key.c = 0;
	if (key == R_KEY)
		frc->key.r = 0;
	if (key == LEFT_KEY)
		frc->key.lft = 0;
	if (key == RIGHT_KEY)
		frc->key.rgh = 0;
	if (key == UP_KEY)
		frc->key.up = 0;
	if (key == DOWN_KEY)
		frc->key.down = 0;
	if (key == MAS_KEY)
		frc->key.mas = 0;
	if (key == MENOS_KEY)
		frc->key.men = 0;
	return (0);
}

int	ft_key_hook(t_frc *frc)
{
	if (frc->key.lft == 1)
		frc->movex = frc->movex - 0.0003 * 24 / frc->zoom;
	else if (frc->key.rgh == 1)
		frc->movex = frc->movex + 0.0003 * 24 / frc->zoom;
	else if (frc->key.up == 1)
		frc->movey = frc->movey - 0.0003 * 24 / frc->zoom;
	else if (frc->key.down == 1)
		frc->movey = frc->movey + 0.0003 * 24 / frc->zoom;
	else if (frc->key.mas == 1)
		frc->zoom = frc->zoom * pow(1.001, 24);
	else if (frc->key.men == 1)
		frc->zoom = frc->zoom / pow(1.001, 24);
	else if (frc->key.c == 1)
	{
		frc->range = frc->range + 25;
		if (frc->range > 255)
			frc->range = 0;
	}
	else if (frc->key.r == 1)
		ft_restartfractol(frc);
	return (0);
}

void	ft_helpmenu(t_frc *frc)
{
	mlx_string_put(frc->ptr, frc->win, 50, 20, 0xffffff,
		"-- MENU DE AYUDA --");
	mlx_string_put(frc->ptr, frc->win, 0, 60, 0xffffff,
		"TECLA H == Muestra la ayuda");
	mlx_string_put(frc->ptr, frc->win, 0, 80, 0xffffff,
		"TECLA C == Modifica el color");
	mlx_string_put(frc->ptr, frc->win, 0, 100, 0xffffff,
		"TECLA R == Reinicia");
	mlx_string_put(frc->ptr, frc->win, 0, 120, 0xffffff,
		"FLECHAS == Mueve la imagen");
	mlx_string_put(frc->ptr, frc->win, 0, 140, 0xffffff,
		"SCROLL RATON O Z/X == Zoom +/-");
	mlx_string_put(frc->ptr, frc->win, 0, 160, 0xffffff,
		"MOV. RATON == Prueba...");
}

void	ft_restartfractol(t_frc *frc)
{
	frc->img = NULL;
	frc->addr = NULL;
	mlx_destroy_window(frc->ptr, frc->win);
	frc->ptr = NULL;
	free(frc->ptr);
	ft_juliafractol(frc);
}

int	ft_exit_game(t_frc *frc)
{
	mlx_destroy_window(frc->ptr, frc->win);
	frc->ptr = NULL;
	free(frc->ptr);
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
