/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 00:50:53 by zimbo            ###   ########.fr       */
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
	
	t_stack *current = data->a;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
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

	ft_printf("\npush_a: %d\n", first->value);
}
