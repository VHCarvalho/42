/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:21:32 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/27 08:34:39 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(int argc, char *argv[])
{
	if (!check_alpha(argc, argv))
		return (0);
	if (!check_maxmin(argc, argv))
		return (0);
	if (!check_duplicates(argc, argv))
		return (0);
	return (1);
}

int	check_alpha(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_maxmin(int argc, char *argv[])
{
	long	nbr;
	int		i;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;
	int	nbr;
	int	nbr_cmp;

	i = 1;
	while (i < argc - 1)
	{
		nbr = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			nbr_cmp = ft_atoi(argv[j]);
			if (nbr == nbr_cmp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
