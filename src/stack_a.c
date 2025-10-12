/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 14:02:08 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_data *data)
{
	t_stack	*first;
	t_stack	*second;
	int	temp;
	
	first = data->a;
	if (!first || !first->next)
		return;

	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	
	ft_putstr_fd("sa\n", 1);
}

void	ft_push_a(t_data *data)
{
	t_stack *first;

	if (data == NULL || data->b == NULL)
		return;
	first = data->b;
	data->b = first->next;
	first->next = data->a;
	data->a = first;

	ft_putstr_fd("pa\n", 1);
}

void	ft_rotate_a(t_data *data)
{
	t_stack *first;
	t_stack	*last;

	if (data == NULL || data->a == NULL || data->a->next == NULL)
		return;

	first = data->a;
	data->a = first->next;

	last = data->a;
	while (last->next != NULL)
		last = last->next;

	last->next = first;
	first->next = NULL;

	ft_putstr_fd("ra\n", 1);
}

void	ft_reverse_rotate_a(t_data *data)
{
	t_stack	*first;
	t_stack	*last;
	
	if (data == NULL || data->a == NULL || data->a->next == NULL)
		return;

	first = data->a;
	while (first->next->next != NULL)
		first = first->next;

	last = first->next;
	first->next = NULL;
	last->next = data->a;
	data->a = last;
	ft_putstr_fd("rra\n", 1);
}
