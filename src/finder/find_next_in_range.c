/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_in_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:50:00 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/17 15:13:17 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_check_data(t_check_data *check_data,
t_best_data *best, int min, int max)
{
	check_data->best = best;
	check_data->min = min;
	check_data->max = max;
}

static void	ft_process_current_node(t_check_data *check_data,
t_stack *current, int position)
{
	check_data->current = current;
	check_data->position = position;
	ft_check_and_update_best(check_data);
}

int	ft_find_next_in_range(t_stack *stack, int min, int max)
{
	t_stack			*current;
	int				position;
	t_best_data		best;
	t_check_data	check_data;

	if (!stack)
		return (-1);
	current = stack;
	position = 0;
	best.position = -1;
	best.distance = ft_stack_size(stack);
	best.stack = stack;
	ft_init_check_data(&check_data, &best, min, max);
	while (current)
	{
		ft_process_current_node(&check_data, current, position);
		position++;
		current = current->next;
	}
	return (best.position);
}
