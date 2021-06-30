/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:56 by fballest          #+#    #+#             */
/*   Updated: 2021/06/30 11:49:43 by fballest         ###   ########.fr       */
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
# define C_KEY 8
# define H_KEY 4
# define R_KEY 15
# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define Z_KEY 6
# define X_KEY 7
# define ZOOM_MOD 1.001

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
	int		fractol;
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
	char	*str;
	char	*imp;
	double	pr;
	double	pi;
	double	radio;
	double	side;
	double	cx;
	double	cy;
	double	xi;
	double	yi;
	int		w;
	double	xx;
	double	yy;
	double	incx;
	double	incy;
	int		texto;
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
**FILE KEYANDMOUSE
*/
// void	ft_keyandmouse(t_frc *frc);
// void	ft_printhelp(t_frc *frc);

/*
**FILE MANDELFRACTOL
*/
int		ft_mandelfractol(t_frc *frc);
void	ft_setinitialvalues_mandel(t_frc *frc);
int		ft_mandeldraw(t_frc *frc);
void	ft_calculatecolor_mandel(t_frc *frc, int x, int y);
void	ft_settozero(t_frc *frc, int x, int y);

/*
**FILE UTILS
*/
int		ft_keypress(int key, t_frc *frc);
int		ft_keyrelease(int key, t_frc *frc);
int		ft_key_hook(t_frc *frc);
int		ft_mouse_hook(int clic, int x, int y, t_frc *frc);
int		ft_mouse_move(int x, int y, t_frc *frc);

/*
**FILE UTILSB
*/
int		ft_exit_game(t_frc *frc);
void	ft_restartfractol(t_frc *frc);
void	ft_helpmenu(t_frc *frc);
void	ft_mlx_pixel_put(t_frc *frc, int x, int y, int color);
int		ft_to_rgb(int r, int g, int b);

/*
**FILE UTILSC
*/
void	ft_hsv_to_rgb(t_frc *frc);
void	ft_hsv_to_rgb2(t_frc *frc);
void	ft_hsv_to_rgb3(t_frc *frc);
int		ft_nonpulsed(t_frc *frc);

/*
**FILE NEWTON
*/
int		ft_newtonfractol(t_frc *frc);
void	ft_setinitialvalues_newton(t_frc *frc);
int		ft_newtondraw(t_frc *frc);
void	ft_calculatecolor_newton(t_frc *frc, int x, int y);
void	ft_putpixelnewton(t_frc *frc, int i, int x, int y);

#endif
