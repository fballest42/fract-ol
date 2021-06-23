/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:35 by fballest          #+#    #+#             */
/*   Updated: 2021/06/23 12:02:41 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_freemen(t_frc *frc)
{
	free(frc);
}

int	ft_exiterror (t_frc *frc, char *str, int num)
{
	printf("%s", str);
	ft_freemen(frc);
	exit(num);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_frc	*frc;

	frc = ft_calloc(sizeof(t_frc), 1);
	if (!frc)
		ft_exiterror(frc, "Error:\nMemory not allocated\n", -1);
	if (argv[1] && argc >= 2)
	{
		if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
			ft_juliafractol(frc);
		else if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
			ft_mandelfractol(frc);
		else if (ft_strncmp(argv[1], "Newton", ft_strlen(argv[1])) == 0)
			ft_newtonfractol(frc);
	}
	else
		ft_exiterror(frc, ft_strjoin("Error:\n",
				"Choose a fractol name:\nJulia\nMandelbrot\nNewton\n"), -3);
	ft_freemen(frc);
	return (0);
}
