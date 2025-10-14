/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/14 04:44:29 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_overflow_str(const char *num, const char *max)
{
	size_t	size_num;
	size_t	size_max;

	size_num = ft_strlen(num);
	size_max = ft_strlen(max);
	if (size_num > size_max)
		return (1);
	if (size_num < size_max)
		return (0);
	return (ft_strncmp(num, max, size_num) > 0);
}

int	ft_is_overflow(int argc, char **argv)
{
	const char	*max = "2147483647";
	const char	*min = "2147483648";
	int			i;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] == '-' && argv[i][1] == '\0') ||
			(argv[i][0] == '+' && argv[i][1] == '\0'))
			return (1);
		if (argv[i][0] == '-')
		{
			if (ft_overflow_str(argv[i] + 1, min))
				return (1);
		}
		else if (ft_overflow_str(argv[i], max))
			return (1);
		i++;
	}
	return (0);
}

int	ft_duplicate(int argc, char **argv)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		num_i = ft_atoi(argv[i]);
		while (j < argc)
		{
			num_j = ft_atoi(argv[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
