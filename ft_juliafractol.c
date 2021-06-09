/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_juliafractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:42:00 by fballest          #+#    #+#             */
/*   Updated: 2021/06/09 12:39:39 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_juliafrctol(t_frc *frc)
{
	frc->rx = 1200;
	frc->ry = 800;
	frc->ptr = mlx_init();
	frc->win = mlx_new_window(frc->ptr, frc->rx, frc->ry, "fractol Julia");
	mlx_hook(frc->win, 17, 1L << 17, ft_exit_game, frc);
	mlx_hook(frc->win, 2, 1L << 0, ft_keypress, frc);
	mlx_hook(frc->win, 3, 1L << 1, ft_keyrelease, frc);
	// mlx_hook(frc->win,MASCARA, MASCARA, ft_mouseprees, frc);
	// mlx_hook(frc->win,MASCARA, MASCARA, ft_mouserelease, frc);
	mlx_loop_hook(frc->ptr, ft_julliadraw, frc)	
	return (0);
}
