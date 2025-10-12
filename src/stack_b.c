/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/12 00:51:05 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_data *data)
{
	t_stack *first;
	if (data == NULL || data->a == NULL)
		return;

	first = data->a;
	data->a = first->next;
	first->next = data->b;
	data->b = first;

	ft_printf("\npush_b: %d\n", first->value);

}

void	ft_swap_b(t_data *data)
{
	t_stack	*first;
	t_stack	*second;
	int	temp;
	
	first = data->b;
	if (!first || !first->next)
		return;

	second = first->next;

	temp = first->value;
	first->value = second->value;
	second->value = temp;
	
	t_stack *current = data->b;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}