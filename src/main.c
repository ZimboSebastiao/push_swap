/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/14 04:22:54 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (ft_checker(argc, argv) != 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->a = ft_receiver(argc, argv);
	data->b = NULL;

	if (!data->a)
	{
		free(data);
		return (1);
	}

	 if (ft_is_sorted(data->a))
    {
        ft_free_stack(data->a);
        ft_free_stack(data->b);
        free(data);
        return (0); 
    }
	ft_big_sort(data);
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	free(data);
	return (0);
}
