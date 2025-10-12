/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 03:05:55 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data *data = malloc(sizeof(t_data));
	if (ft_checker(argc, argv) != 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	data->a = ft_receiver(argc, argv);
	data->b = NULL;

	// ft_swap_a(data);
	// ft_push_b(data);

	
	// ft_push_b(data);
	// ft_push_b(data);
	// ft_push_b(data);
	// ft_push_b(data);
	ft_putstr("Stack a Antes:\n\n");
	ft_reverse_rotate_a(data);
	// ft_rotate_a(data);
	// ft_rotate_b(data);

	
	ft_putstr("\n\nStack a Depois:\n");
	ft_print_stack(data->a);

	
	free(data);
	return (0);
}