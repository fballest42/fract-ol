/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:39:50 by fballest          #+#    #+#             */
/*   Updated: 2021/06/09 12:57:03 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keypress(int key, t_frc *frc)
{
	if (key == W_KEY)
		frc->key->w = 1;
	if (key == S_KEY)
		frc->key->s = 1;
	if (key == A_KEY)
		frc->key->a = 1;
	if (key == D_KEY)
		frc->key->d = 1;
	if (key == ESC_KEY)
		ft_exit_game(frc);
	if (key == LEFT_KEY)
		frc->key->lft = 1;
	if (key == RIGHT_KEY)
		frc->key->rgh = 1;
    if (key == UP_KEY)
		frc->key->up = 1;
	if (key == DOWN_KEY)
		frc->key->down = 1;
	return (0);
}

int	ft_keyrelease(int key, t_frc *frc)
{
	if (key == W_KEY)
		frc->key->w = 0;
	if (key == S_KEY)
		frc->key->s = 0;
	if (key == A_KEY)
		frc->key->a = 0;
	if (key == D_KEY)
		frc->key->d = 0;
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

void	ft_exit_game(t_frc *frc)
{

}
