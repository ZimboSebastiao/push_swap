/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/14 06:02:18 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_data *data)
{
	if (data == NULL || data->a == NULL || data->a->next == NULL)
		return ;
	if (data->a->value > data->a->next->value)
		ft_swap_a(data);
}

static void	ft_sort_three(t_data *data)
{
	int	one;
	int	two;
	int	three;

	if (data == NULL || data->a == NULL || data->a->next->next == NULL)
		return ;
	one = data->a->value;
	two = data->a->next->value;
	three = data->a->next->next->value;
	if (one > two && two < three && one < three)
		ft_swap_a(data);
	else if (one > two && two < three && one > three)
		ft_rotate_a(data);
	else if (one < two && two > three && one < three)
	{
		ft_swap_a(data);
		ft_rotate_a(data);
	}
	else if (one < two && two > three && one > three)
		ft_reverse_rotate_a(data);
	else if (one > two && two > three)
	{
		ft_swap_a(data);
		ft_reverse_rotate_a(data);
	}
}

static void	ft_move_min_to_b(t_data *data)
{
	t_stack	*min;
	t_stack	*current;
	int		position;
	int		total;

	total = 0;
	position = 0;
	min = data->a;
	current = data->a;
	while (current && ++total)
	{
		if (current->value < min->value)
		{
			min = current;
			position = total;
		}
		current = current->next;
	}
	if (position <= total / 2)
		while (data->a != min)
			ft_rotate_a(data);
	else
		while (data->a != min)
			ft_reverse_rotate_a(data);
	ft_push_b(data);
}

static void	ft_sort_four_five(t_data *data)
{
	t_stack	*temp;
	int		count;
	int		to_push;

	if (!data || !data->a)
		return ;
	count = 0;
	temp = data->a;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	to_push = count - 3;
	while (to_push--)
		ft_move_min_to_b(data);
	ft_sort_three(data);
	while (data->b)
		ft_push_a(data);
}

void	ft_small_sort(t_data *data)
{
	t_stack	*temp;
	int		count;

	if (!data || !data->a)
		return ;
	temp = data->a;
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (count == 1)
		return ;
	else if (count == 2)
		ft_sort_two(data);
	else if (count == 3)
		ft_sort_three(data);
	else if (count == 4 || count == 5)
		ft_sort_four_five(data);
}
