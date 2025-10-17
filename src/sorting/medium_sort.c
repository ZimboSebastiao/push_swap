/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:30:00 by zimbo             #+#    #+#             */
/*   Updated: 2025/10/16 21:46:28 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_medium_sort(t_data *data)
{
	int	size;

	if (!data || !data->a || ft_is_sorted(data->a))
		return ;
	size = ft_stack_size(data->a);
	if (size <= 5)
		return (ft_small_sort(data));
	ft_push_chunks_to_b(data);
	while (data->b)
		(ft_move_max_to_top_b(data), ft_push_a(data));
}
