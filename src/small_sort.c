/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 21:20:32 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_data *data)
{
	if (data == NULL || data->a == NULL || data->a->next == NULL)
		return;

	if (data->a->value > data->a->next->value)
		ft_swap_a(data);
}

static void	ft_sort_three(t_data *data)
{
	if (data == NULL || data->a == NULL || data->a->next->next == NULL)
		return;

	int	one = data->a->value;
	int	two = data->a->next->value;
	int	three = data->a->next->next->value;

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

static void	ft_sort_four(t_data *data)
{
	if (!data || !data->a)
		return;

	t_stack *min;
	t_stack *current;
	min = data->a;
	current = data->a;

}

void	ft_small_sort(t_data *data)
{
	if (!data || !data->a)
		return;
	
	t_stack	*temp;
	int		count;
	temp = data->a;

	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	ft_printf("Count: %d\n", count);
	if (count == 2)
		ft_sort_two(data);
	if (count == 3)
		ft_sort_three(data);

}
