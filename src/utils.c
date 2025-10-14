/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:41 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/14 05:00:56 by zimbo            ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_print_stack(t_stack *head)
{
	while (head != NULL)
	{
		ft_printf("print: %d\n", head->value);
		head = head->next;
	}
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
		return pos;
	else
		return size - pos;
}

// Função auxiliar para ft_final_rotate_a
void	ft_final_rotate_a(t_data *data)
{
	int	min_pos;
	int	size;
	int	min_value;
	t_stack	*current;
	int	pos;

	if (!data->a)
		return ;
	
	min_value = data->a->value;
	min_pos = 0;
	current = data->a;
	pos = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	
	size = ft_stack_size(data->a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ft_rotate_a(data);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			ft_reverse_rotate_a(data);
	}
}