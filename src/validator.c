/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/10 13:26:06 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>


void	ft_empty(int argc)
{
	if (argc == 1)
		exit(0);
}

void	ft_check_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if(!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
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

void	ft_is_overflow(int argc, char **argv)
{
	const char	*max = "2147483647";
	int		i;
	
	i = 1;
	while (i < argc)
	{
		if (ft_overflow_str(argv[i], max))
		{
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
}

void	ft_duplicate(int argc, char **argv)
{
	int		i;
	int		j;
	size_t	size;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			size = ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], size) == 0)
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
