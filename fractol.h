/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:56 by fballest          #+#    #+#             */
/*   Updated: 2021/06/18 11:20:43 by fballest         ###   ########.fr       */
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
# include "minilibx/mlx.h"

/*
**KEYS DEFINITION
*/
# ifdef __APPLE__
#  define C_KEY 8
#  define H_KEY 4
#  define R_KEY 15
#  define ESC_KEY 53
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
#  define MAS_KEY 6
#  define MENOS_KEY 7
#  define ZOOM_MOD 1.001
#  define RTSPD 0.04363325
# endif

/*
**WORKING STRUCTURES
*/

typedef struct s_key
{
	int		c;
	int		h;
	int		r;
	int		zin;
	int		zou;
	int		esc;
	int		lft;
	int		rgh;
	int		up;
	int		down;
	int		mas;
	int		men;
}				t_key;

typedef struct s_frc
{
	void	*ptr;
	void	*win;
	void	**img;
	char	*addr;
	int		rx;
	int		ry;
	int		mou_x;
	int		mou_y;
	int		sili;
	int		bxp;
	int		end;
	double	cRe;
	double	cIm;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	double	zoom;
	double	movex;
	double	movey;
	double	time;
	double	oldtime;
	double	frametime;
	int		help;
	int		max_iter;
	int		color;
	float	r;
	float	g;
	float	b;
	float	h;
	float	s;
	float	v;
	float	f;
	float	p;
	float	q;
	float	t;
	float	range;
	int		i;
	float	cmax;
	float	cmin;
	float	diff;
	t_key	key;
}				t_frc;

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
void	ft_setinitialvalues(t_frc *frc);
int		ft_juliafractol(t_frc *frc);
int		ft_juliadraw(t_frc *frc);
void	ft_calculatecolor(t_frc *frc, int x, int y);

/*
**FILE FT_JULIAFRACTOL_2
*/
void	ft_hsv_to_rgb(t_frc *frc);
void	ft_hsv_to_rgb2(t_frc *frc);
void	ft_hsv_to_rgb3(t_frc *frc);

/*
**FILE KEYANDMOUSE
*/
void	ft_keyandmouse(t_frc *frc);
void	ft_printhelp(t_frc *frc);

/*
**FILE FT_MANDELFRACTOL
*/
int		ft_mandelfractol(t_frc *frc);

/*
**FILE FT_UTILS
*/
int		ft_keypress(int key, t_frc *frc);
int		ft_keyrelease(int key, t_frc *frc);
int		ft_key_hook(t_frc *frc);
void	ft_mlx_pixel_put(t_frc *frc, int x, int y, int color);
int		ft_to_rgb(int r, int g, int b);
int		ft_exit_game(t_frc *frc);
void	ft_restartfractol(t_frc *frc);
void	ft_helpmenu(t_frc *frc);
int		ft_mouse_hook(int clic, int x, int y, t_frc *frc);

#endif
