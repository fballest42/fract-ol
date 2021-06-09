/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:56 by fballest          #+#    #+#             */
/*   Updated: 2021/06/09 12:54:08 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
**LIBRARIES
*/
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include "libft/libft.h"

/*
**KEYS DEFINITION
*/
# ifdef __APPLE__
#  include "minilibx/mlx.h"
#  define A_KEY 0
#  define W_KEY 13
#  define S_KEY 1
#  define D_KEY 2
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define ESC_KEY 53
#  define LEFT_SHIFT 257
#  define X_BTN 17
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define MVSPD 0.07
#  define RTSPD 0.04363325
# endif

/*
**WORKING STRUCTURES
*/
typedef struct s_frc
{
	void	*ptr;
	void	*win;
	int		rx;
	int		ry;
	void	*img;
	char	*addr;
	int		sizeli;
	int		bpp;
	int		endian;
	t_key	*key;
}				t_frc;

typedef struct s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		lft;
	int		rgh;
	int		up;
	int		down;
}				t_key;

/*
**FUNTION IN FILES
*/

/*
**FILE FT_FRACTOLMAIN FUNTIONS + MAIN
*/
int		ft_exiterror (t_frc *frc, char *str, int num);
void	ft_freemen (t_frc *frc);

/*
**FILE FT_JULIAFRACTOL
*/
int		ft_juliafractol(t_frc *frc);

/*
**FILE FT_MANDELFRACTOL
*/
int		ft_mandelfractol(t_frc *frc);

/*
**FILE FT_UTILS
*/
int				ft_keypress(int key, t_frc *frc);
int				ft_keyrelease(int key, t_frc *frc);

#endif
