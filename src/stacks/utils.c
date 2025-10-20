/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/17 15:14:59 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(int argc, char **argv)
{
	if (ft_check_int(argc, argv))
		return (1);
	if (ft_is_overflow(argc, argv))
		return (1);
	if (ft_duplicate(argc, argv))
		return (1);
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*cur;

	cur = stack;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	ft_get_min_distance(int pos, int size)
{
	if (pos < size - pos)
		return (pos);
	else
		return (size - pos);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
