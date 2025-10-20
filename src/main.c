/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/17 15:15:24 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**handle_args(char **av, int *ac)
{
	char	**split;
	int		i;

	if (*ac != 2)
		return (av);
	split = ft_split(av[1], ' ');
	if (!split || !split[0])
		return (av);
	i = 0;
	while (split[i])
		i++;
	av = malloc(sizeof(char *) * (i + 2));
	if (!av)
		return (free(split), av);
	av[0] = av[0];
	i = 0;
	while (split[i])
	{
		av[i + 1] = split[i];
		i++;
	}
	av[i + 1] = NULL;
	*ac = i + 1;
	return (free(split), av);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (0);
	argv = handle_args(argv, &argc);
	if (ft_checker(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->a = ft_receiver(argc, argv);
	data->b = NULL;
	if (!data->a)
		return (free(data), 1);
	if (!ft_is_sorted(data->a))
		ft_big_sort(data);
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	return (free(data), 0);
}
