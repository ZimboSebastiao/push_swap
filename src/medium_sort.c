/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:30:00 by zimbo             #+#    #+#             */
/*   Updated: 2025/10/14 20:40:06 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_value(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (0);
	min = stack->value;
	current = stack;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

static int	ft_find_max_value(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

static void	ft_push_chunk_to_b(t_data *data, int min_val, int max_val)
{
	int	position;
	int	size_a;

	while (1)
	{
		position = ft_find_next_in_range(data->a, min_val, max_val);
		if (position == -1)
			break ;
		size_a = ft_stack_size(data->a);
		if (position <= size_a / 2)
		{
			while (position-- > 0)
				ft_rotate_a(data);
		}
		else
		{
			position = size_a - position;
			while (position-- > 0)
				ft_reverse_rotate_a(data);
		}
		ft_push_b(data);
		if (data->b->value < (min_val + max_val) / 2 && data->b->next)
			ft_rotate_b(data);
	}
}

static int	ft_calculate_chunks(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 200)
		return (7);
	else if (size <= 300)
		return (9);
	else
		return (11);
}

void	ft_medium_sort(t_data *data)
{
	int	size;
	int	chunks;
	int	chunk_size;
	int	i;
	int	min_val;
	int	max_val;
	int	range_min;
	int	range_max;

	if (!data || !data->a || ft_is_sorted(data->a))
		return ;
	size = ft_stack_size(data->a);
	if (size <= 5)
		return (ft_small_sort(data));
	
	min_val = ft_find_min_value(data->a);
	max_val = ft_find_max_value(data->a);
	chunks = ft_calculate_chunks(size);
	chunk_size = (max_val - min_val) / chunks + 1;
	
	i = 0;
	while (i < chunks)
	{
		range_min = min_val + (i * chunk_size);
		range_max = range_min + chunk_size - 1;
		if (i == chunks - 1)
			range_max = max_val;
		
		ft_push_chunk_to_b(data, range_min, range_max);
		i++;
	}
	
	while (data->b)
		(ft_move_max_to_top_b(data), ft_push_a(data));
}