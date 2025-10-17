/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:50:00 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/16 21:44:20 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_chunks(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 200)
		return (7);
	else if (size <= 300)
		return (9);
	else
		return (11);
}

void	ft_process_chunks(t_data *data, int min_val, int max_val, int chunks)
{
	int	i;
	int	chunk_size;
	int	range_min;
	int	range_max;

	chunk_size = (max_val - min_val) / chunks + 1;
	i = 0;
	while (i < chunks)
	{
		range_min = min_val + (i * chunk_size);
		range_max = range_min + chunk_size - 1;
		if (i == chunks - 1)
			range_max = max_val;
		ft_push_chunk_to_b(data, range_min, range_max);
		i++;
	}
}
