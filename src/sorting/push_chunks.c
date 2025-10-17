/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:50:00 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/16 21:42:38 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunks_to_b(t_data *data)
{
	int	size;
	int	chunks;
	int	min_val;
	int	max_val;

	size = ft_stack_size(data->a);
	min_val = ft_find_min_value(data->a);
	max_val = ft_find_max_value(data->a);
	chunks = ft_calculate_chunks(size);
	ft_process_chunks(data, min_val, max_val, chunks);
}
