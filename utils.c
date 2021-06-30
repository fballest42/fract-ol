/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:39:50 by fballest          #+#    #+#             */
/*   Updated: 2021/06/30 11:47:48 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_hook(int clic, int mx, int my, t_frc *frc)
{
	int	dx;
	int	dy;

	dx = mx - (frc->rx / 2);
	dy = my - (frc->ry / 2);
	if (clic == 5)
	{
		frc->zoom = frc->zoom * pow(1.001, 50);
		frc->movex = frc->movex + dx * 0.0003 / frc->zoom;
		frc->movey = frc->movey - dy * 0.0003 / frc->zoom;
	}
	else if (clic == 4)
	{
		frc->zoom = frc->zoom / pow(1.001, 50);
		frc->movex = frc->movex + dx * 0.0003 / frc->zoom;
		frc->movey = frc->movey - dy * 0.0003 / frc->zoom;
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
	if (key == Z_KEY)
		frc->key.mas = 1;
	if (key == X_KEY)
		frc->key.men = 1;
	if (key == ESC_KEY)
		ft_exit_game(frc);
	if (key == H_KEY)
		frc->key.h = 1;
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
	if (key == Z_KEY)
		frc->key.mas = 0;
	if (key == X_KEY)
		frc->key.men = 0;
	if (key == H_KEY)
		frc->key.h = 0;
	return (0);
}

int	ft_key_hook(t_frc *frc)
{
	if (ft_nonpulsed(frc) == 0)
		return (0);
	if (frc->key.lft == 1)
		frc->movex = frc->movex - 0.0003 * 50 / frc->zoom;
	else if (frc->key.rgh == 1)
		frc->movex = frc->movex + 0.0003 * 50 / frc->zoom;
	else if (frc->key.up == 1)
		frc->movey = frc->movey - 0.0003 * 50 / frc->zoom;
	else if (frc->key.down == 1)
		frc->movey = frc->movey + 0.0003 * 50 / frc->zoom;
	else if (frc->key.mas == 1)
		frc->zoom = frc->zoom * pow(ZOOM_MOD, 50);
	else if (frc->key.men == 1)
		frc->zoom = frc->zoom / pow(ZOOM_MOD, 50);
	else if (frc->key.c == 1)
	{
		frc->range = frc->range + 25;
		if (frc->range > 255)
			frc->range = 0;
	}
	else if (frc->key.r == 1)
		ft_restartfractol(frc);
	else if (frc->key.h == 1)
		ft_helpmenu(frc);
	return (0);
}

int	ft_mouse_move(int x, int y, t_frc *frc)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	frc->str = ft_itoa((int)(frc->zoom));
	frc->imp = ft_strjoin("ZOOM = x", frc->str);
	if (frc->str)
		free(frc->str);
	dx = dx - x;
	dy = dy - y;
	if (dx != 0 && dy != 0)
		mlx_string_put(frc->ptr, frc->win, 600, 20, 0xFFFFFF, frc->imp);
	if (frc->imp)
		free(frc->imp);
	return (0);
}
