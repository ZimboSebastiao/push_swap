/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/17 15:14:36 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_data *data)
{
	t_stack	*first;

	if (data == NULL || data->a == NULL)
		return ;
	first = data->a;
	data->a = first->next;
	first->next = data->b;
	data->b = first;
	ft_putstr_fd("pb\n", 1);
}

void	ft_swap_b(t_data *data)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	first = data->b;
	if (!first || !first->next)
		return ;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_rotate_b(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	if (data == NULL || data->b == NULL || data->b->next == NULL)
		return ;
	first = data->b;
	data->b = first->next;
	last = data->b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	ft_reverse_rotate_b(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	if (data == NULL || data->b == NULL || data->b->next == NULL)
		return ;
	first = data->b;
	while (first->next->next != NULL)
		first = first->next;
	last = first->next;
	first->next = NULL;
	last->next = data->b;
	data->b = last;
	ft_putstr_fd("rrb\n", 1);
}
