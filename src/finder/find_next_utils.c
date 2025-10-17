/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:50:00 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/16 21:46:08 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_and_update_best(t_check_data *data)
{
	int	current_dist;
	int	size;

	if (data->current->value >= data->min && data->current->value <= data->max)
	{
		size = ft_stack_size(data->best->stack);
		current_dist = ft_get_min_distance(data->position, size);
		if (current_dist < data->best->distance)
		{
			data->best->position = data->position;
			data->best->distance = current_dist;
			return (1);
		}
	}
	return (0);
}
