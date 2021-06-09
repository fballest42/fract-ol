/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractolmain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:55:35 by fballest          #+#    #+#             */
/*   Updated: 2021/06/09 11:51:09 by fballest         ###   ########.fr       */
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
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
			ft_juliafractol(frc);
		else if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
			ft_mandelfractol(frc);
		else
			ft_exiterror(frc,
				"Error:\nfractol set not valid, try 'Julia' or 'Mandelbrot'.",
				-3);
	}
	else
		ft_exiterror(frc, "Error:\nNot valid arguments", -2);
	ft_freemen(frc);
	return (0);
}
