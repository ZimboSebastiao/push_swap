/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/16 21:44:57 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	ft_find_max_position_b(t_stack *stack)
{
	int		max;
	int		position;
	int		current_pos;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	position = 0;
	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			position = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (position);
}

void	ft_move_max_to_top_b(t_data *data)
{
	int	position;
	int	size;

	if (!data->b)
		return ;
	position = ft_find_max_position_b(data->b);
	size = ft_stack_size(data->b);
	if (position == 0)
		return ;
	if (position <= size / 2)
	{
		while (position-- > 0)
			ft_rotate_b(data);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			ft_reverse_rotate_b(data);
	}
}

void	ft_big_sort(t_data *data)
{
	int	size;

	if (!data || !data->a || ft_is_sorted(data->a))
		return ;
	size = ft_stack_size(data->a);
	if (size <= 5)
		return (ft_small_sort(data));
	else if (size <= 500)
		return (ft_medium_sort(data));
	else
	{
		ft_medium_sort(data);
	}
}
