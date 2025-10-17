/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:50:00 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/16 21:47:35 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunk_to_b(t_data *data, int min_val, int max_val)
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
