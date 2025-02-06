/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:27:03 by sidrissi          #+#    #+#             */
/*   Updated: 2025/02/06 22:37:11 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_check(int ac, char *av[], t_fractol *fractol)
{
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractol->name = av[1];
		if (!ft_strncmp(fractol->name, "julia", 5))
		{
			fractol->julia_x = -0.7269;
			fractol->julia_y = +0.1889;
			// fractol->julia_x = /*atoif(av[2])*/;
			// fractol->julia_y= /*atoif(av[3])*/;
		}
		initialize_window(fractol);
		fractol_render(fractol);
		mlx_loop(fractol->mlx_connection);
	}
	else
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_fractol	fractol;
	if (ft_check(ac, av, &fractol))
		return ((write(2, "Error\n", 6)), 1);
	return (0);
}
