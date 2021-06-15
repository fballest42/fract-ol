/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:39:50 by fballest          #+#    #+#             */
/*   Updated: 2021/06/15 13:30:45 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keypress(int key, t_frc *frc)
{
	if (key == C_KEY)
		frc->key->c = 1;
	if (key == H_KEY)
		frc->help = 1;
	if (key == R_KEY)
		frc->key->r = 1;
	if (key == LEFT_KEY)
		frc->key->lft = 1;
	if (key == RIGHT_KEY)
		frc->key->rgh = 1;
	if (key == UP_KEY)
		frc->key->up = 1;
	if (key == DOWN_KEY)
		frc->key->down = 1;
	if (key == ESC_KEY)
		ft_exit_game(frc);
	return (0);
}

int	ft_keyrelease(int key, t_frc *frc)
{
	if (key == C_KEY)
		frc->key->c = 0;
	if (key == R_KEY)
		frc->key->r = 0;
	if (key == LEFT_KEY)
		frc->key->lft = 0;
	if (key == RIGHT_KEY)
		frc->key->rgh = 0;
	if (key == UP_KEY)
		frc->key->up = 0;
	if (key == DOWN_KEY)
		frc->key->down = 0;
	return (0);
}

int	ft_key_hook(t_frc *frc)
{
	//mlx_mouse_get_pos(frc->ptr, &frc->mou_x, &frc->mou_y);
	// frc->oldtime = frc->time;
	// frc->time = 
	// frc->frametime = frc->time - frc->oldtime;
	if (frc->key->lft == 1)
		frc->movex = frc->movex - 10 * frc->zoom;
	else if (frc->key->rgh == 1)
		frc->movex = frc->movex + 10 * frc->zoom;
	else if (frc->key->up == 1)
		frc->movey = frc->movey - 10 * frc->zoom;
	else if (frc->key->down == 1)
		frc->movey = frc->movey + 10 * frc->zoom;
	else if (frc->key->c == 1)
	{
		frc->range = frc->range + 2.5;
		if (frc->range > 255)
			frc->range = 0;
	}
	else if (frc->key->r == 1)
		ft_restartfractol(frc);
	return (0);
}

void	ft_helpmenu(t_frc *frc)
{
	mlx_string_put(frc->ptr, frc->win, 160, 20, 0xffffff,
		"---- MENU DE AYUDA ----");
	mlx_string_put(frc->ptr, frc->win, 0, 40, 0xffffff,
		"======================================================");
	mlx_string_put(frc->ptr, frc->win, 0, 60, 0xffffff,
		"TECLA H  ------------->   Muestra u oculta la ayuda.");
	mlx_string_put(frc->ptr, frc->win, 0, 80, 0xffffff,
		"TECLA R  ------------->   Reinicia el frantol.");
	mlx_string_put(frc->ptr, frc->win, 0, 100, 0xffffff,
		"TECLA C  ------------->   Modifica los colores del fractol.");
	mlx_string_put(frc->ptr, frc->win, 0, 120, 0xffffff,
		"TECLA IZQ   ---------->   Mueve hacia la izquierda.");
	mlx_string_put(frc->ptr, frc->win, 0, 140, 0xffffff,
		"TECLA DRH   ---------->   Mueve hacia la derecha.");
	mlx_string_put(frc->ptr, frc->win, 0, 160, 0xffffff,
		"TECLA ARR   ---------->   Mueve hacia arriba.");
	mlx_string_put(frc->ptr, frc->win, 0, 180, 0xffffff,
		"TECLA ABJ   ---------->   Mueve hacia abajo.");
	mlx_string_put(frc->ptr, frc->win, 0, 200, 0xffffff,
		"SCROLL RATON Y +/-  -->   Aumenta o disminuye el zoom.");
	mlx_string_put(frc->ptr, frc->win, 0, 220, 0xffffff,
		"MOVER EL RATON  ------>   Prueba, algo hara.");
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
